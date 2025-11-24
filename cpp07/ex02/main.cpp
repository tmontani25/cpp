#include "array.hpp"

// Array<int> // tableau d’entiers
// Array<float> // tableau de flottants
// Array<double> // tableau de doubles
// Array<char> // tableau de caractères
// Arraystd::string // tableau de chaînes de caractères
// Array<bool> // tableau de booléens
// Array<Array<int>> // tableau de tableaux d’entiers (tableau 2D)
// Array<MyClass>

class Foo {
public:
    Foo() : value(0) {}
    Foo(int v) : value(v) {}
    int value;
};


int main(void){

    std::cout<< "TESTER\n";

    std::cout<< "TABLEAU VIDE\n";
    Array<int> empty;
    unsigned int size = empty.getSize();
    std::cout<< "size du tableau vide: " << size << std::endl;



    std::cout<< "\nTABLEAU ALLOUE DYNAMIQUEMENT\n";
    Array<int> *dynamicArray = new Array<int>(5);
    for (unsigned int i = 0; i < (*dynamicArray).getSize(); i++){
        (*dynamicArray)[i] = i * 1;
    }
    for (unsigned int i = 0; i < (*dynamicArray).getSize(); i++){
        std::cout << (*dynamicArray)[i] <<std::endl;
    }
    delete dynamicArray;


    std::cout << "\nTABLEAU INITIALISE AVEC UNE TAILLE DEFINIE n et test float\n";
    Array<float> floatEmpty(10);
    std::cout<< "size du tableau de float vide: " << floatEmpty.getSize() << std::endl;
    std::cout<< "contenu du tableau: \n";

    std::cout << '{';
    for(unsigned int i = 0; i < floatEmpty.getSize(); i++){

        std::cout << floatEmpty[i];
        std::cout<<", ";
    }
    std::cout<< '}';

    std::cout << "\n\nFIN DE MES TESTS\n\n CHAT GPT TESTS\n";

    std::cout<< "TEST OUT OF BOUNDS\n";

    try {
        Array<int> arr(3);
        arr[3] = 42; // Doit lancer une exception arr[3] existe pas
    } 
    catch (const std::exception& e) {
        std::cout << "Exception attendue : " << e.what() << std::endl;
    }


    std::cout<< "\n\nTEST COPY CONSTRUCTOR\n";
    Array<int> original(3);
    original[0] = 1; original[1] = 2; original[2] = 3;
    Array<int> copie(original);
    copie[0] = 99;
    std::cout << "original[0] = " << original[0] << ", copie[0] = " << copie[0] << std::endl;


     std::cout<< "\n\nTEST OPERATOR AFFECTATION = \n";

    Array<int> a(2), b(2);
    a[0] = 5; a[1] = 6;
    b = a;
    b[1] = 42;
    std::cout << "a[0] = " << a[0] << ", a[1] = " << a[1]  << ", b[0] = "<< b[0] << ", b[1] = " << b[1] << std::endl;

     std::cout<< "\n\n STRING ARRAY TEST = \n";
    Array<std::string> strArr(2);
    strArr[0] = "Hello";
    strArr[1] = "World";
    std::cout << "strArr: " << strArr << std::endl;


    std::cout<< "\n\nTEST TABLEAU DE TABLEAU = \n";
    Array< Array<int> > matrix(2);
    for (unsigned int i = 0; i < matrix.getSize(); ++i)
        matrix[i] = Array<int>(2);
    matrix[0][0] = 1; matrix[0][1] = 2;
    matrix[1][0] = 3; matrix[1][1] = 4;

    std::cout << "matrix[0][0] = " << matrix[0][0] << std::endl;
    std::cout << "matrix[0][1] = " << matrix[0][1] << std::endl;
    std::cout << "matrix[1][0] = " << matrix[1][0] << std::endl;
    std::cout << "matrix[1][1] = " << matrix[1][1] << std::endl;

    std::cout<< "\n\nTEST TABLEAU DE CLASS FOO = \n";
    Array<Foo> arr(3);
    arr[0] = Foo(10);
    arr[1] = Foo(20);
    arr[2] = Foo(30);

    for (unsigned int i = 0; i < arr.getSize(); ++i)
        std::cout << arr[i].value << std::endl; 
    
}

