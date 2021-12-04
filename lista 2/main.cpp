#include <iostream>
#include <math.h>

using namespace std;

//zadanie 1 (lista 1)
template <typename T, typename U>
auto add1(T x,  U y)
{
    return x + y;
}

//zadanie 5(lista 2)
template <typename T, typename U>
auto add1(T* x,  U* y)
{
    return *x + *y;
}

template <>
auto add1<const char>(const char*x, const char*y)
{
    string a = x;
    string b = y;
    return a + b;
}

//zadanie 2 (lista 1)
template <typename T, typename U, typename W>
auto add2(const T x, const U y, W oper)
{
    return oper(x, y);
}

//zadanie 6 (lista 2)
template <typename T, typename U>
constexpr auto hypercube(T a, U n) -> decltype (pow(a, n))
{
    if (a < 0 or n < 0) return -1;
    else return pow(a, n);
}

//zadanie 7 (lista 2)
template <typename T, typename ... Args>
auto add(T first, Args ... args)
{
    if constexpr (sizeof...(args) == 0) return first;
    else return first + add(args...);
}

int main()
{
    //testy zadanie 1
    auto x = add1(25, 17);
    auto y = add1(17, 3.14);
    string a = "abc";
    string b = "def";
    auto z = add1(a, b);

    cout << "Testy do zadania 1: \n";
    cout << "Jeden typ numeryczny: " << x << "\n";
    cout << "Różne typy numeryczne: " << y << "\n";
    cout << "Typy string: " << z << "\n";

    //testy zadanie 2
    auto x2 = add2(25, 17, [](auto a, auto b) {return a + b; });
    auto y2 = add2(17, 3.14, [](auto a, auto b) {return a + b; });
    auto z2 = add2(a, b, [](auto a, auto b) {return a + b; });

    cout << "\nTesty do zadania 2: \n";
    cout << "Jeden typ numeryczny: " << x2 << "\n";
    cout << "Różne typy numeryczne: " << y2 << "\n";
    cout << "Typy string: " << z2 << "\n";

    //testy zadanie 5
    cout << "\nTesty do zadania 5: \n";
    int i = 1;
    float j = 2.5;
    int* i_pointer = &i;
    float* j_pointer = &j;
    cout << "Dodanie inta z floatem, które są przekazane przez wskaźnik: " << add1(*i_pointer, *j_pointer) << "\n";
    const char* k = "a";
    const char* l = "b";
    cout << "Dodanie const char* z const char*: " << add1(k, l) << "\n";

    //testy zadanie 6
    //static_assert(hypercube(4, 5) == 1024, "Nie działa, zły wynik!");
    cout << "\nTesty do zadania 6: \n";
    cout << "Obliczenie objętości hipersześcianu o boku 4 i 5 wymiarach: " << hypercube(4, 5) << "\n";
    cout << "Funkcja jest wywoływana w czasie kompilacji ponieważ, static_assert nie zwraca błędu.\n";

    //testy zadanie 7
    cout << "\nTesty do zadania 7: \n";
    cout << "Funkcja dodająca do siebie różne typy danych: " << add(1, 1.0, 1.0f) << "\n";

}
