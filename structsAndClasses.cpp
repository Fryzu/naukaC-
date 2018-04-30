#include <iostream>

class Klasa  {

    public:
        int y;
        void showMe() {

            std::cout << "I am showing myself" << std::endl;

        }

};

struct struktura : public Klasa {

    int x = 0;

};

int main() {

    struktura struktura;

    struktura.showMe();

    return 0;

}