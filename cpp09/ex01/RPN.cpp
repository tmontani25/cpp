#include "RPN.hpp"

int RPN::calculate(int a, int b, char op){
    int result = 0;

    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else if (op == '/'){
        if (b == 0)
            throw std::runtime_error("Error");
        result = a / b;
    }
    else throw std::runtime_error("Error");
    return result;
}
bool RPN::isOperator(char token){
    //verifie si le token est un operateur
    return token == '+' || token == '-' || token == '*' || token == '/';
}
int RPN::evaluate(const std::string &expr){
    //lis la chaine de caractere
    //tokenise donc chiffre et symbole pas de parsing pour l'instant
    //place les elements dans la stack en calculant
    int finalResult;
    std::string token;
    std::stack<int> st;
    std::istringstream iss(expr);//iss contient la string il y'a un curseur comme dans un stream
    while (iss >> token){  // lit le caractere et le met dans token
        if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))){
            int number = token[0] - '0';
            st.push(number);
        }
        else if(token.size() == 1 && isOperator(token[0])){
            if (st.size() < 2){
                throw std::runtime_error("Error");
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = calculate(a, b, token[0]);
            st.push(result);
        }
        else
            throw std::runtime_error("Error");
    }
    if (st.size() != 1)
        throw std::runtime_error("Error");
    finalResult = st.top();
    return finalResult;
}
