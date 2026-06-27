#include "Serializer.hpp"


int main(){
    Data d;
    uintptr_t serialized;

    d.type = "String";
    d.val = 12;
    serialized = Serializer::serialize(&d);

    std::cout << "The adress before serialization : " << &d << std::endl;
    std::cout << "The serialized : " <<  serialized << std::endl;
    std::cout << "The adress aftr deserialization : " << Serializer::deserialize(serialized) << std::endl;

}