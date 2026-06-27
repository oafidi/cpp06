#include <iostream>

struct Dog {
    short a;
};

struct Car {
    public :
        int a;
        long b;



};

int main() {
    Dog* myDog = new Dog();

    myDog->a = 15;
    myDog->b = 15;

    // ❌ C-STYLE CAST: Compiles silently but creates a dangerous bug.
    // The compiler forces the memory of a Dog to look like a Car.
    // Car* fakeCar = (Car*)myDog; 
    
    // 💥 CRASH / UNDEFINED BEHAVIOR: 
    // You are calling drive() on memory that actually holds a Dog object.
    // std::cout << fakeCar->a << std::endl;
    // std::cout << fakeCar->b << std::endl;
    //  `static_cast`: The compiler blocks this dangerous mistake.
    // ERROR: invalid 'static_cast' from type 'Dog*' to type 'Car*'
    Car* safeCar = static_cast<Car*>(myDog); 

    delete myDog;
    return 0;
}