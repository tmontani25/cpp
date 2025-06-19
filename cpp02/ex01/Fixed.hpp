#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();                          // Constructeur par défaut
    Fixed(const int n);               // Constructeur int
    Fixed(const float f);             // Constructeur float
    Fixed(const Fixed& other);        // Constructeur de copie
    Fixed& operator=(const Fixed& other); // Opérateur d'affectation
    ~Fixed();                         // Destructeur

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;        // Conversion en float
    int toInt(void) const;            // Conversion en int

private:
    int _value;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif