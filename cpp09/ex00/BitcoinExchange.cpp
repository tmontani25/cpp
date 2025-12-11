#include "BitcoinExchange.hpp"

std::string BitcoinExchange::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::loadDatabase(std::string &fileDb){

    std::ifstream file(fileDb);
    if (!file.is_open()){
        std::cerr<<"error couldn't open file\n"<<std::endl;
        file.close();
        return false;
    }
    else{

        //boucle de lecture du fichier data.csv ligne par ligne
        std::string line;
        std::getline(file, line); //skip la premiere ligne du fichier data.csv qui contient le titre
        while(std::getline(file, line)){ //tant qu'on a pas EOF
            std::string date;
            double value;
            if (!parseLine(line, ',', date, value)){
                return false;
            }
            // mettre dans map date et value
            // std::cout<< "date :"<< date <<std::endl;
            // std::cout<<"\n";
            // std::cout << "value :" << std::fixed << std::setprecision(2) << value << std::endl;
            // std::cout<<"\n";

            _database[date] = value; // Load ma map _database

        }
        // std::cout << "PRINTING DATABASE\n";
        // printDatabaseMap();
        file.close();
        return true;
    }
}


//decoupe chaque ligne du fichier en deux parties date et price
bool BitcoinExchange::parseLine(std::string line, char delimiter, std::string &date, double &value){

    /*gestion d'erreur faite ici
    1. Pas de délimiteur trouvé
    2. Valeur complètement non numérique
    3. Valeur avec caractères invalides APRÈS le nombre


    2012-01-11 | abc
    2012-01-11 |  (valeur vide)
    2012-01-11 | hello
    2012-01-11 | 5abc
    2012-01-11 | 5 extra
    2012-01-11 | 5,extra

    */
    std::string priceStr;
    size_t pos = line.find(delimiter);
    if (pos == std::string::npos) {  // No delimiter
        std::cerr<< "Error bad input => " << line << "\n";
        return false;  // Erreur de format
    }
    date = trim(line.substr(0, pos)); // enlever les espaces avant et apres | 
    priceStr = trim(line.substr(pos + 1));
    // std::cout<< "priceStr:  " << priceStr << "\n";

    char *end;
    double temp = strtod(priceStr.c_str(), &end); //convertit PriceStr en double
    if (end == priceStr.c_str() || *end != '\0'){  // Erreur de conversion end pointe la ou la conversion s'arrete
        std::cerr<< "Error bad input => " << line << std::endl; //valeur completement non digit detectee ex: 2012-01-11 | abc ou 2012-01-11 | (rien)
        return false;
    }
    value = temp;
    return true;

}


void BitcoinExchange::printDatabaseMap(){
     std::cout << "INSIDE\n";
    std::map<std::string, double>::const_iterator it;
    
    for(it = _database.begin(); it != _database.end(); ++it){ //it->first = key it->second = value
        std::cout << it->first << " : " << std::fixed 
            << std::setprecision(2) << it->second << std::endl;       
    }
}


bool BitcoinExchange::checkInputFormat(const std::string &date, const double &nbBtc){
    //check format date
    (void)nbBtc;
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    // Vérifier que les autres caractères sont des chiffres
    for (size_t i = 0; i < date.length(); i++) {
        if (i != 4 && i != 7) {
            if (!isdigit(date[i]))
                return false;
        }
    }
    return true;
}

bool BitcoinExchange::processInputFile(const std::string &inputFile){

    std::ifstream file(inputFile); // ouvrir input database
    if (!file.is_open()){
        std::cerr<<"error couldn't open file\n"<<std::endl;
        file.close();
        return false;
    }

    std::string line;
    std::getline(file, line); //skip premiere ligne

    while(std::getline(file, line)){

        double result;

        std::string date;
        double nbBtc;
        if (!parseLine(line, '|', date, nbBtc))
            continue;// skip cette ligne
        
        if(!checkInputFormat(date, nbBtc)){
            std::cerr << "Error format =>" << date << std::endl;
                continue;
        }
            

        if (nbBtc < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
            continue;
    }
    if (nbBtc > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
            continue;
    }

    // recherche dans database
        std::map<std::string, double>::iterator it = _database.find(date);
    // si la date est pas trouvee
        if (it == _database.end()){
            it = _database.lower_bound(date); // comparaison lexicographique des dates, trouve la next date >= a date

            if (it == _database.begin()){
                std::cerr << "date too early\n" << std::endl;
                    continue;
            }
            --it;

            double price = it->second;
            result = price * nbBtc;
            std::cout << date << " => " << nbBtc << " = " << result << std::endl;;
            continue;
        }

        //calculer le resultat du prix * nbBtc
        result = nbBtc * it->second;
        std::cout << date << " => " << nbBtc << " = " << result << std::endl;
        
    }
    return true;      
}

//a faire rechercher dans map calculer et print
//checker les edges cases format
