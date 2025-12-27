#include "RPN.hpp"

int main(int argc, char **argv){

    //recup string
    //verifier le format
    //algo avec stack
    if (argc != 2){
        std::cerr << "Error wrong number of arguments\n";
        return 1;
    }
    try{
       int result = RPN::evaluate(argv[1]);
        std::cout<< result << std::endl;
    } catch (const std::exception&){
        std::cerr << "Error" << std::endl;
        return 1;
    }
}