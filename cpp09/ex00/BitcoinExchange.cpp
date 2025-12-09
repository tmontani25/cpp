#include "BitcoinExchange.hpp"

bool BitcoinExchange::loadDatabase(std::string &filename){

    std::ifstream file(filename);
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
            double price;
            if (!parseLine(line, ',', date, price)){
                std::cerr<< "error database format\n";
                return false;
            }
            // mettre dans map date et price
            // std::cout<< "date :"<< date <<std::endl;
            // std::cout<<"\n";
            // std::cout << "price :" << std::fixed << std::setprecision(2) << price << std::endl;
            // std::cout<<"\n";

            _database[date] = price; // Load ma map _database

        }
        std::cout << "PRINTING DATABASE\n";
        printDatabase();
        file.close();
        return true;
    }
}


//decoupe chaque ligne du fichier en deux parties date et price
bool BitcoinExchange::parseLine(std::string line, char delimiter, std::string &date, double &price){

    std::string priceStr;
    size_t pos = line.find(delimiter);
    date = line.substr(0, pos);
    priceStr = line.substr(pos + 1); //depuis le delimiter jusqu'a la fin de la ligne
    // std::cout<< "priceStr:  " << priceStr << "\n";

    char *end;
    double temp = strtod(priceStr.c_str(), &end); //convertit PriceStr en double
    if (end == priceStr.c_str() || *end != '\0'){  // Erreur de conversion end pointe la ou la conversion s'arrete
        std::cerr<< "error conversion\n";
        return false;
    }
    price = temp;
    return true;

}


void BitcoinExchange::printDatabase(){
     std::cout << "INSIDE\n";
    std::map<std::string, double>::const_iterator it;
    
    for(it = _database.begin(); it != _database.end(); ++it){ //it->first = key it->second = value
        std::cout << it->first << " : " << std::fixed 
            << std::setprecision(2) << it->second << std::endl;       
    }
}