//declaration de ma class Fixed
// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();                              // constructeur par défaut
    Fixed(const Fixed& other);           // constructeur de copie
    Fixed& operator=(const Fixed& other); // opérateur d'affectation
    ~Fixed();                             // destructeur

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
