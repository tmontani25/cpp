#ifndef BASE_HPP
#define BASE_HPP

// Classe de base avec destructeur virtuel public
class Base {
public:
    virtual ~Base() {}
};

// Classes dérivées vides qui héritent publiquement de Base
class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif