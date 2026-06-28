#include "Serializer.hpp"

int main()
{
    Data d;
    uintptr_t serialized;

    d.type = "String";
    d.val = 12;

    std::cout << "  Before serialization  " << std::endl;
    std::cout << "Address : " << &d << std::endl;
    std::cout << "type    : " << d.type << std::endl;
    std::cout << "val     : " << d.val << std::endl;

    serialized = Serializer::serialize(&d);

    std::cout << "\nSerialized value : " << serialized << std::endl;

    Data* ptr = Serializer::deserialize(serialized);

    std::cout << "\n   After deserialization   " << std::endl;
    std::cout << "Address : " << ptr << std::endl;
    std::cout << "type    : " << ptr->type << std::endl;
    std::cout << "val     : " << ptr->val << std::endl;

    return 0;
}