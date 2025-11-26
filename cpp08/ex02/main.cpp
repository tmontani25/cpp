#include "MutantStack.hpp"


// int main(void){

//     MutantStack<int> myStack;

//     myStack.push(5);
//     myStack.push(6);
//     myStack.push(7);

//     MutantStack<int>::iterator it = myStack.begin();
//     std::cout << *it << std::endl;

//     std::cout<< "\nTEST ITERATION SUR MA STACK:\n";

//     for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it) {
//         std::cout << *it << std::endl;
// }


// }
int main()
{

    std::cout<< "42 TESTS\n";
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite) {
    std::cout << *it << std::endl;
++it; }
std::stack<int> s(mstack);



    std::cout<< "\nMY TESTS\n";
MutantStack<std::string> str;
str.push("hello");
str.push("world");

for (MutantStack<std::string>::iterator it = str.begin(); it != str.end(); ++it) {
    std::cout << *it << std::endl;
}



    std::cout << "\n== TEST MutantStack<std::string> ==" << std::endl;
    MutantStack<std::string> s_str;
    s_str.push("salut");
    s_str.push("bye");
    s_str.push("42");
    s_str.push("ciao");
    std::cout << "Top: " << s_str.top() << std::endl;
    s_str.pop();
    std::cout << "Size after pop: " << s_str.size() << std::endl;
    std::cout << "Elements in stack (iteration): ";
    for (MutantStack<std::string>::iterator it = s_str.begin(); it != s_str.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;





return 0;




}

