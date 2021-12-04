#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    #pragma omp parallel
    //#pragma omp single 
    //#pragma omp master
    #pragma omp critical
    cout << "Witaj z wątku nr " << omp_get_thread_num() << " spośród " << omp_get_num_threads() << "\n";
}

/*
    Zadanie 1:
    Za każdym razem wynik programu jest inny poniważ OpenMP przydziela losowo wątek po czym wykonuje instukcję cout.
    Komunikaty wyświetlane są przez program w kolejności jakiej zostały przydzielone rdzenie procesora i zdarzają się
    sytuacje że napis nie został dokonczony po czym został już uruchominy kolejny rdzeń.

    Zadanie 2:
    #pragma omp single - fragment kodu wykonany przez jeden wątek niekoniecznie główny, wątki są blokowane
    #pragma omp master - fragment kodu wykonany przez główny wątek, wątki nie są blokowane przed i po wykonaniu fragmentu kodu 
    #pragma omp critical - fragment kodu wykonany w danym czasie tylko przez jeden wątek 

    Dodanie #pragma omp critical ratuje program w sposob taki jaki powinien działać, czyli każdy rdzeń wykonuje 1 swoją instrukcję cout, 
    nie wchodząc innym w drogę.
*/