#include "ScalarConverter.hpp"

// affiche tout les type
namespace { // namespace permet de rien avoir dans le .hpp et utiliser les fonctions
    void printChar(double value) {
        std::cout << "char: ";
        if (std::isnan(value) || std::isinf(value)) {
            std::cout << "impossible";
        }
        else if (value < 0 || value > 255) {
            std::cout << "impossible";
        }
        else if (value < 32 || value > 126) {
            std::cout << "Non displayable";
        }
        else {
            std::cout << "'" << static_cast<char>(value) << "'"; //typecast
        }
        std::cout << std::endl;
    }

    void printInt(double value) {
        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value)) {
            std::cout << "impossible";
        }
        else if (value > INT_MAX || value < INT_MIN) {
            std::cout << "impossible";
        }
        else {
            std::cout << static_cast<int>(value); //typecast
        }
        std::cout << std::endl;
    }

    void printFloat(double value) {
        std::cout << "float: ";
        if (std::isnan(value)) {
            std::cout << "nanf";
        }
        else if (std::isinf(value)) {
            std::cout << (value > 0 ? "+inff" : "-inff");
        }
        else {
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
        }
        std::cout << std::endl;
    }

    void printDouble(double value) {
        std::cout << "double: ";
        if (std::isnan(value)) {
            std::cout << "nan";
        }
        else if (std::isinf(value)) {
            std::cout << (value > 0 ? "+inf" : "-inf");
        }
        else {
            std::cout << std::fixed << std::setprecision(1) << value;
        }
        std::cout << std::endl;
    }

    void printAllTypes(double value) { // print chaque type
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
}

void ScalarConverter::convert(const std::string& literal){

    LiteralType type;

    // 1. Pseudo-literals d'abord
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || 
        literal == "+inff" || literal == "-inff") {
            std::cout << "test nan\n";
        type = PSEUDO;
    }
    // 2. Char literal : exactement 3 caractères 'a'
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        type = CHAR;
    }
    // 3. Float : contient '.' ET finit par 'f'
    else if (literal.find('.') != std::string::npos && literal[literal.length()-1] == 'f') {
        type = FLOAT;
    }
    // 4. Double : contient '.' mais pas de 'f'
    else if (literal.find('.') != std::string::npos && literal.find('f') == std::string::npos) {
        type = DOUBLE;
    }
    // 5. Int : ni '.' ni 'f'
    else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos) {
        type = INT;
    }
    else {
        type = INVALID;
    }

    // Conversion et affichage selon le type double est la plus grande valeur
    double value = 0.0;
    
    // sert a tout caster en double et assigner a value
    // mon enum sert a caster en fonction du type

    switch (type) {
        case CHAR:
            value = static_cast<double>(literal[1]); // assigne value a l'input
            break;
        case INT:
        case FLOAT:
        case DOUBLE:
            value = atof(literal.c_str()); //assigne value a l'input (atof str to double)
            break;
        case PSEUDO:
            if (literal == "nan" || literal == "nanf") {
                value = std::numeric_limits<double>::quiet_NaN(); // quiet_NaN ne lance pas d'exceptions 
            }
            else if (literal == "+inf" || literal == "+inff") {
                value = std::numeric_limits<double>::infinity();
            }
            else if (literal == "-inf" || literal == "-inff") {
                value = -std::numeric_limits<double>::infinity();
            }
            break;
        default:
            std::cout << "Error: Invalid input" << std::endl;
            return;
    }
    
    // Afficher tous les types
    printAllTypes(value);

}