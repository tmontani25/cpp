#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class BitcoinExchange{
    private:
    bool parseLine(std::string line, char delimiter, std::string &date, double &value);
    std::map<std::string, double> _database;
    std::string trim(const std::string& str);

    public:
    BitcoinExchange(){};
    ~BitcoinExchange(){};


    //fonctions
    bool loadDatabase(std::string &filename);
    void printDatabaseMap();
    bool processInputFile(const std::string &inputFile);
    bool checkInputFormat(const std::string &date, const double &nbBtc);


    
    // //getter
    // const std::map<std::string, double> getDataBase() const {
    //     return _database;
    // }


};