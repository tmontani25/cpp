#include "BitcoinExchange.hpp"

// a faire:
//gerer les erreurs et cas limites dans le parsing de la database
//recuper ligne par ligne le fichier input.txt et chercher la donnee dans _database





//parser la database et la stocker dans un container map
//pour chaque input utilisateur


int main(int argc, char **argv){

    //recuperer le fichier utilisateur
    //retourner error si input faux
    (void)argv;

    if (argc != 2){
        std::cerr << "Error bad input: no input file\n"<<std::endl;
        // return 1;
    }

    BitcoinExchange btc;

    //parser la database et la stocker dans une map
    std::map<std::string, float> database;
    std::string filename = "data.csv";
    btc.loadDatabase(filename);







 
    
    
    
    
    //fichier utilisateur: parser la cle et la valeur et ensuite chercher dans la database

        //std::ifstream file() // c_str() convertit les chaines c++ en c -> std::string -> char * / std::ifstream cree un outil pour lire le fichier
    











    

}