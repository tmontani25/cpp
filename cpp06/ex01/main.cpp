#include "Serializer.hpp"
#include "Data.hpp"


int main(void){

    //creer un pointeur data
    //le serialiser transformer en nb
    //le retransformer en nb

    Data obj;
    obj.x = 10;

    Data *ptr = &obj;
    //serializer ptr

    std::cout << "serialize function test\n";

    std::cout << "ptr: "<< ptr << std::endl;
    uintptr_t value = Serializer::serialize(ptr);
    std::cout << "value = serialised ptr in decimal: "<< value << std::endl;
    std::cout << "value = serialised ptr Hexadécimal: 0x" << std::hex << value << std::endl; 
    
    std::cout << "\n deserialize function test\n";
    


    Data* restoredPtr = Serializer::deserialize(value);
    std::cout << std::dec << "ptr adress after deserialize: " << restoredPtr << std::endl;

    // TEST OBLIGATOIRE : vérifier l'égalité des pointeurs
    std::cout << "\n=== VERIFICATION ===" << std::endl;
    if (ptr == restoredPtr) {
        std::cout << "✅ SUCCESS: Original and restored pointers are EQUAL!" << std::endl;
        std::cout << "✅ Serialization/Deserialization works perfectly!" << std::endl;
    } else {
        std::cout << "❌ FAIL: Pointers are different!" << std::endl;
    }

}