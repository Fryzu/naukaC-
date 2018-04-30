#include <iostream>

/*
  A
 / \
B   C
 \ /
  D
*/

class A {

    public:
        void say() {

            std::cout << "saying" << std::endl;

        };

};

class B : public virtual A {};

class C : public virtual A {};

class D : public B, public C {};


int main() {

    D d;

    d.say();

    return 0;
}