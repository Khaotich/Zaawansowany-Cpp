#include <iostream>
#include <vector>
#include "Wektor.hpp"

using namespace std;

//zadanie 1
template <typename T, typename U>
auto add1(const T x, const U y)
{
    return x + y;
}

//zadanie 2
template <typename T, typename U, typename W>
auto add2(const T x, const U y, W oper)
{
    return oper(x, y);
}

//zadanie 4
template <typename T, int size, T value, typename Y>
auto operator*(Wektor <T, size, value> a, vector<Y> b) -> decltype(a[0] * b[0])
{
    if(b.size() == 0 || a.len() == 0 || a.len() != b.size())
    {
        throw logic_error("Nieprawidłowy rozmiar wektorów!\n");
    }
    else
    {
        auto result = 0;
        for(int i = 0; i <= b.size(); ++i) result += a[i] * b[i];
        return result;
    }
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

    //testy zadanie 3
    cout << "\nTesty do zadania 3: \n";
    Wektor <double, 5, 4.5> wek;
    cout << "Liczba przed zmianą: " << wek[2] << "\n";
    wek[2] = 152.1;
    cout << "Liczba po zmianie: " << wek[2] << "\n";

    //testy zadanie 4
    cout << "\nTesty do zadania 4: \n";
    Wektor <double, 3, 0.5> wa;
    vector <int> wb = { 2, 4, 6 };
    
    try
    {
        auto il = wa * wb;
        cout << "Iloczyn skalarny wektorów różnych typów: " << il << "\n";
    }
    catch(const logic_error& e)
    {
        cerr << e.what() << '\n';
    }
    
    cout << "Value type klasy Wektor: " << typeid(wb).name() << "\n\n";
}
