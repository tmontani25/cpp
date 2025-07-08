#include "Fixed.hpp"
#include <cmath>

// Canonical
Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const int n) { _value = n << _fractionalBits; }
Fixed::Fixed(const float f) { _value = roundf(f * (1 << _fractionalBits)); }
Fixed::Fixed(const Fixed& other) { _value = other._value; }
Fixed& Fixed::operator=(const Fixed& other) { if (this != &other) _value = other._value; return *this; }
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }
float Fixed::toFloat(void) const { return (float)_value / (1 << _fractionalBits); }
int Fixed::toInt(void) const { return _value >> _fractionalBits; }

// Comparison
bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

// Arithmetic
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed res;
    res._value = _value + other._value;
    return res;
}
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed res;
    res._value = _value - other._value;
    return res;
}
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    res._value = (int)(((long long)_value * (long long)other._value) >> _fractionalBits);
    return res;
}
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed res;
    res._value = (int)(((long long)_value << _fractionalBits) / other._value);
    return res;
}

// Increment/decrement
Fixed& Fixed::operator++() { _value++; return *this; }
Fixed Fixed::operator++(int) { Fixed tmp(*this); _value++; return tmp; }
Fixed& Fixed::operator--() { _value--; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp(*this); _value--; return tmp; }

// min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

// Output
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}