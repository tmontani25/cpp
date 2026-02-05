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
    BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {};
    BitcoinExchange &operator=(const BitcoinExchange &other) {
        if (this != &other)
            _database = other._database;
        return *this;
    };
    ~BitcoinExchange(){};


    //fonctions
    bool loadDatabase(std::string &filename);
    void printDatabaseMap();
    bool processInputFile(const std::string &inputFile);
    bool checkDateFormat(const std::string &date);
    bool isBissextile(const std::string &year);


    
    // //getter
    // const std::map<std::string, double> getDataBase() const {
    //     return _database;
    // }


};