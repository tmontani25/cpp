#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

class BitcoinExchange{
    private:
    bool parseLine(std::string line, char delimiter, std::string &date, double &price);
    std::map<std::string, double> _database;

    public:
    BitcoinExchange(){};
    ~BitcoinExchange(){};


    //fonctions
    bool loadDatabase(std::string &filename);
    void printDatabase();

    
    // //getter
    // const std::map<std::string, double> getDataBase() const {
    //     return _database;
    // }


};