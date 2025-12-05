#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>     // pour atof, atoi
#include <climits>     // pour INT_MAX, INT_MIN
#include <cfloat>      // pour FLT_MAX, FLT_MIN
#include <cmath>       // pour isnan, isinf
#include <cerrno>      // pour errno
#include <limits>      // pour std::numeric_limits
#include <iomanip>     // pour std::fixed, std::setprecision

// Exemple d'usage : ./convert "42"
// Sortie attendue :
// char: '*' (ou "Non displayable" si pas affichable)
// int: 42  
// float: 42.0f
// double: 42.0

// Exemple : ./convert "4.2f"
// Sortie attendue :
// char: Non displayable (ou impossible)
// int: 4
// float: 4.2f  
// double: 4.2

class ScalarConverter {
private:
    // Constructeurs privés pour empêcher l'instanciation
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    enum LiteralType {
        CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID
    };

public:
    static void convert(const std::string& literal);
};

