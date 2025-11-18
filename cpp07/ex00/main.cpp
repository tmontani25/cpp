#include "Templates.hpp"

//introduction aux templates


int main(void){

    // std::cout << "=== Test swap ===" << std::endl;
    // int a = 10;
    // int b = 20;
    // std::cout << "Avant: a = " << a << ", b = " << b << std::endl;
    // ::swap(a, b);
    // std::cout << "Après: a = " << a << ", b = " << b << std::endl;

    // std::cout << "\n=== Test min ===" << std::endl;
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    
    // int& result = ::min(a, b);
    // std::cout << "min retourne: " << result;
    
    // // Identifier quel paramètre est retourné
    // if (&result == &a) {
    //     std::cout << " (paramètre 'a')" << std::endl;
    // } else if (&result == &b) {
    //     std::cout << " (paramètre 'b')" << std::endl;
    // }

    // std::cout << "\n=== Test avec valeurs égales ===" << std::endl;
    // int x = 5, y = 5;
    // std::cout << "x = " << x << ", y = " << y << std::endl;
    
    // int& result2 = ::min(x, y);
    // std::cout << "min retourne: " << result2;
    
    // if (&result2 == &x) {
    //     std::cout << " (paramètre 'x' - premier)" << std::endl;
    // } else if (&result2 == &y) {
    //     std::cout << " (paramètre 'y' - second)" << std::endl;
    // }

    // std::cout << "\nmax test"<< std::endl;

    // int big = 100, small = 1;
    // std::cout << "max is: " << ::max(big, small) << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;








}