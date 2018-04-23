#include <iostream>

class Haba {

    public:
        int _a;
        int _b;
        int _c;

        //Konstruktor delegujacy
        Haba(int a) : Haba() {

            _a = a;

        };

        //Konstruktor domyslny
        Haba() = default;

        //Konstruktor kopiujący
        Haba(const Haba& toCopy) : Haba() {

            _a = toCopy._a;

            std::cout << "Wywoływany jest konstruktor kopiujący." << std::endl;

        }

        Haba& operator=(const Haba& toCopy) {

            this->_a = toCopy._a;

            std::cout << "Wywoływany jest operator przypisania." << std::endl;

            return *this;

        }

};

void przekazywanieWartosc(const Haba x) {}

int main() {

    Haba haba1(1);

    /*
    std::cout << a._a << std::endl;
    std::cout << a._b << std::endl; 
    std::cout << a._c << std::endl;*/   

    std::cout << "Haba haba2(haba1);" << std::endl; 
    Haba haba2(haba1);

    std::cout << "Haba haba3 = haba1;" << std::endl; 
    Haba haba3 = haba1;

    std::cout << "haba4 = haba1;" << std::endl; 
    Haba haba4;
    haba4 = haba1;

    std::cout << "haba5.operator=(haba1);" << std::endl; 
    Haba haba5;
    haba5.operator=(haba1);

    std::cout << "przekazywanieWartosc(haba1);" << std::endl;
    przekazywanieWartosc(haba1);


    return 0;

}