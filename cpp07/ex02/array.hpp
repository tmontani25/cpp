#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    // Default constructor: Creates an empty array
    Array() : _data(NULL), _size(0) {}
    
    // Constructor with size: Creates an array of n elements initialized by default
    Array(unsigned int size) : _data(new T[size]()), _size(size) {}
    
    // Copy constructor: Deep copy
    Array(const Array& other) : _data(NULL), _size(0) {
        if (other._size > 0) {
            _data = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++) { 
                _data[i] = other._data[i];
            }
        }
    }
    
    // Destructor
    ~Array() {
        delete[] _data;
    }
    
    // Assignment operator: Deep copy
    Array& operator=(const Array& other) {
        if (this != &other) {
            // Delete old data
            delete[] _data;
            _data = NULL;
            _size = 0;
            
            // Copy new data
            if (other._size > 0) {
                _data = new T[other._size];
                _size = other._size;
                for (unsigned int i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            }
        }
        return *this;
    }
    
    // operateur []
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }
    
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }
    
    // guetter
    unsigned int getSize() const {
        return _size;
    }
};

// operateur <<
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    os << "[";
    for (unsigned int i = 0; i < arr.getSize(); ++i) {
        os << arr[i];
        if (i + 1 < arr.getSize())
            os << ", ";
    }
    os << "]";
    return os;
}

#endif

