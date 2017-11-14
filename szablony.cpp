#include <iostream>

/*Ćwiczenie 1

Przypomnij sobie z wykładu odpowiednią składnię, a następnie zaimplementuj szablon funkcji minimum() , wybierającej mniejszy z dwóch argumentów.*/

template <typename T> T minimum(T a, T b) {return (a > b) ? a : b;};

/*Ćwiczenie 2

Zaimplementuj funkcję uogólnioną minimum_z_tablicy() . Informację o początku i rozmiarze tablicy przekazuj przy pomocy dwóch wskaźników, pokazujących na pierwszy element w tablicy oraz miejsce w pamięci tuż za końcem tablicy. Wyglądać to powinno mniej więcej tak:

int tab[10];
tab[0] = 7;   tab[1] = 33; .....
int m = minimum_z_tablicy(tab, tab + 10); */

template <typename T> 
T minimum_z_tablicy(T* firstElement, T* elementBehind)
{
	T minimum = *firstElement;
	for (T* i = firstElement + 1; i < elementBehind; i++)
	{
		if (*i < minimum) minimum = *i;
	}

	return minimum;
}

int main()
{
	//testy

	//1
	std::cout << minimum(10.1, 20.0) << std::endl;

	//2
	int tablica[10] = {0, 9, 1, 8, 7, 2, 6, 3, 5, 4};
	std::cout << minimum_z_tablicy(tablica, tablica + 10) << std::endl;
	

	return 0;
}

