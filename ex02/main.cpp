#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

Base * generate(void)
{
    int num = std::rand();

    if (num % 3 == 0)
        return static_cast<Base*>(new A());
    else if (num % 3 == 1)
        return static_cast<Base*>(new B());
    else
        return static_cast<Base*>(new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try {
        A &derived = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &e) {}

    try {
        B &derived = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::bad_cast &e) {}

    try {
        C &derived = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::bad_cast &e) {}
}

int main()
{
    try {
        for (int i = 0; i < 5; i++)
        {
            Base *b = generate();
            identify(b);
            identify(&(*b));
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}