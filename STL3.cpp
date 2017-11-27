/* Wykład krótko wspomina o funktorach, czyli obiektach wyglądających 
 * syntaktycznie tak jak funkcje. Są one przydatne m.in. wtedy, 
 * gdy chcemy napisać uogólniony algorytm coś robiący, ale nie wiemy 
 * z góry co to będzie. Rozważmy szablon funkcji, która przechodzi 
 * przez ciąg elementów i dla każdego elementu spełniającego pewien 
 * warunek wykonuje pewną czynność. Jak widać, chcemy mieć możliwość 
 * przekazania z zewnątrz zarówno warunku, jak i czynności. 
 * Wyglądać to może na przykład tak:
 * 
 *      template <typename Iter, typename Cond, typename Oper>
 *      void wykonaj_na_spełniających(Iter początek, Iter za_końcem,
 *              Cond warunek, Oper czynność)
 *  
 * Zaimplementuj algorytm o takiej sygnaturze.
 */

 #include <iostream>

template <typename Iterator>
class Bubblesort
{
    public:
        void operator()(const Iterator start, const Iterator end)
        {
            for (Iterator a = end+1; a != start; a--)
            {
                for (Iterator b = start; b != (a - 1); b++)
                {
                    if ((*b)>(*(b+1))) swap(b, b+1);
                }
            }
        }
        void swap(const Iterator a, const Iterator b)
        {
            auto tmp = *a;
            *a = *b;
            *b = tmp; 
        }
};

int main()
{
    int table[10];

    Bubblesort<int*> bubblesort;
    bubblesort(table, &(table[9]));

    for (int i = 0; i < 10; i++)
    {
        std::cout << table[i] << std::endl;
    }
    
    return 0;
}