#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) {
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    _value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    _value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _value = other._value;
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}