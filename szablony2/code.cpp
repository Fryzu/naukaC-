#include "code.h"
#include <iostream>

char CezarCode::code(const char input, int displacement)
{
    char result;

    if((input>96)&&(input<123))
    {
        result = (input - 'a' + displacement) % 26;
        if (result < 0) result = 26 + result;
        result += 'a';
    }
    else if((input>64)&&(input<91)) 
    {
        result = (input - 'A' + displacement) % 26;
        if (result < 0) result = 26 + result;
        result += 'A';
    }
    else 
        result = input;

    return result;
}

