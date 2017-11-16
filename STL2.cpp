/*
 * Oprócz uogólnionych pojemników STL dostarcza również uogólnionych 
 * funkcji działających na ciągach elementów, tzw. algorytmy. 
 * Ciąg przekazuje się do funkcji za pomocą dwóch iteratorów, 
 * wskazujących na jego początek i za jego koniec. 
 * Zaimplementuj algorytm wypisz_na_cout(), robiący dokładnie to, 
 * na co jego nazwa wskazuje; przetestuj go na którymś z pojemników 
 * STL oraz na zwykłej tablicy. Czy jesteś w stanie powiedzieć jakie 
 * typy będą użyte podczas konkretyzacji tego szablonu? 
 */

#include <iostream>
#include <vector>
#include <list>
#include <sstream>

template <typename Iterator>
const std::string wypisz_na_cout(const Iterator iter1, const Iterator iter2)
{
    std::stringstream result;

    for (Iterator i = iter1; i != iter2; i++)
    {
        result << *i << std::endl;
    }

    return result.str();
}

int main()
{
    std::vector<double> wektor(100);

    int a = 1;
    for (std::vector<double>::iterator i = wektor.begin(); i != wektor.end(); i++)
    {
        *i = a;
        a += 1;
    }

    int tablica[100];

    std::cout << "Wektor:" << std::endl;
    std::cout << wypisz_na_cout(wektor.begin(), wektor.end());
    std::cout << "Tablica:" << std::endl;
    std::cout << wypisz_na_cout(tablica, &(tablica[99]));

    return 0;
}