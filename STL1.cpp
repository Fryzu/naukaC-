/*
 * Ćwiczenie 1
 * 
 * Zapoznaj się z dokumentacją pojemników vector oraz list, 
 * a następnie spróbuj napisać jakiś prosty programik, 
 * wykorzystujący co najmniej 50% metod oferowanych przez te klasy. 
 * Programik nie musi robić niczego specjalnie pożytecznego. 
 * W przypadku niedostatku fantazji jako punkt startowy możesz 
 * wykorzystać plik zabawa_z_stl.cpp.
 */

#include <iostream>
#include <list>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    clock_t start;
    //zabawa polega na porównywaniu prędkości różnych metod klas list i vector
    
    cout << "INICJALIZACJA 1000 EL. INT" << endl;

    cout << "Wektor - ";
    start = clock();
    vector<int> wektor(1000);
    cout << ( "Czas wykonania: %lu ms\n", clock() - start ) << endl;

    cout << "Lista - ";
    start = clock();
    list<int> lista(1000);
    cout << ( "Czas wykonania: %lu ms\n", clock() - start ) << endl;

    cout << "\nDODAWANIE 1000 EL. NA KONIEC" << endl;
    
    cout << "Wektor - ";
    start = clock();
    
    for(int i = 0; i < 1000; i++)
    {
        wektor.push_back(i);
    }

    cout << ( "Czas wykonania: %lu ms\n", clock() - start ) << endl;

    cout << "Lista - ";
    start = clock();

    for(int i = 0; i < 1000; i++)
    {
        lista.push_back(i);
    }

    cout << ( "Czas wykonania: %lu ms\n", clock() - start ) << endl;

    cout << "\nPRZEPSYWANIE 1000 EL. Z TABLICY" << endl;
    
    int table[1000];
    for (int i = 0; i<1000; i++) table[i] = 2*i;

    cout << "Wektor - ";
    start = clock();
    
    vector<int>::iterator iteratorWektora = wektor.begin();
    for(int i = 0; i < 1000; i++)
    {
        *iteratorWektora = table[i];
        ++iteratorWektora;
    }

    cout << ( "Czas wykonania: %lu ms\n", clock() - start ) << endl;

    cout << "Lista - ";
    start = clock();

    list<int>::iterator iteratorListy = lista.begin();
    for(int i = 0; i < 1000; i++)
    {
        *iteratorListy = table[i];
        ++iteratorListy;
    }

    cout << ( "Czas wykonania: %lu ms\n", clock() - start ) << endl;

    return 0;
}