#include <iostream>
#include "code.h"

int main()
{
    CezarCode translator;
    std::cout << translator.translate<3>(translator.translate<-3>("Bartek")) << std::endl;

    return 0;
}