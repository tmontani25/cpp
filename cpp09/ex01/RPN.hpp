#include<stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <stack>

class RPN{
    private:
    static int calculate(int a, int b, char op);
    static bool isOperator(char token);
    public :
    static int evaluate(const std::string &expr); // static permet d'utiliser la fonction sans creer un objet rpn
};