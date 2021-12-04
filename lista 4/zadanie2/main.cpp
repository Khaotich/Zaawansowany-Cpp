#include <stdio.h>
#include <time.h>
#include <omp.h>

int main()
{
    const int N = 1000000000;
    int i = 0;
    double sum = 0;
    clock_t t0 = clock();

    #pragma omp parallel for private(i) reduction(+:sum)
    for (i = 0; i <= N-1; ++i)
    {
        sum += 1.0 / (i + 1.0);
    }

    clock_t t1 = clock();
    printf("s = %g\n", sum);
    printf("t = %g\n", ((double)t1 - t0)/CLOCKS_PER_SEC);
}

/*

    - wersja równoległa i szeregowa daje inne wyniki
    
    - zmieniając ilość wątków przy uruchomieniu programu za każdym razem wychodzą inne wyniki sumy i czasu
    
    - konstrukcja pętli jest niepoprawna, należy iterować od najmniejszych do największych i zmienić typ zmienej sum na double
    aby zwiększyć prezycję, ponieważ folat gubił dokładność, teraz ze zmianami program daje zawsze poprawny wynik nie zależnie
    od ilości wątków, wynik jest poprawny (Taki również podaje WolframAlpha około 21,3005) 
    
    - funkcja clock() zwraca ilość cykli od uruchomienia programu, pierwsza jest wywoływana 
    przed rozpoczęciem pętli a kolejna po zakończeniu pętli i ich różnica podzielona przez stałą clocks_per_sec co daje
    nam czas trwania pętli a nie jest to wallclock, ponieważ wallclock jest czasem działania całego programu a nasza różnica
    jest tylko czasem działaniem pętli
    
    - funkcja clock() nie nadaje się do oceny czasu działania programu ponieważ nażut robi przydzielenie wątku, co przekłamuje wyniki
    
    - elapsed wyświetla czas działania programu a użyte wątki to % CPU (100% to jeden wątek, 200% to dwa wątki, itk. jeden wątek
    to około 100%)

*/