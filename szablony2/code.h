#ifndef SZYFROWANIE
#define SZYFROWANIE

#include <string>
#include <sstream>

class CezarCode
{
    public:
        template <int displacement> 
        std::string translate(std::string input)
        {
            std::stringstream result;

            for (int i = 0; i < input.size(); i++)
            {    
                result << code(input[i], displacement);
            }

            return result.str();
        };
    private:
        char code(const char, int);
};

#endif
