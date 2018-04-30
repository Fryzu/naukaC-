#include <iostream>
#include <memory>

class Haba {

    int _a;

    Haba(const int a) {
        _a = a;
    }

};

int main()
{
    std::cout << "ahababa" << std::endl;

    {
        auto pointer = std::make_unique<Haba>(1);
    }

    

    return 0;
}