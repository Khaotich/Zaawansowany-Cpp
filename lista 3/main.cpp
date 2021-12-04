#include <iostream>
#include <type_traits>
#include "a.h"

using namespace std;

//Zadanie 9
A copy(A& org)
{
    return A(org);
}

A copy(A&& org)
{
    return A(move(org));
}

//Zadanie 10
// template <typename T>
// A copy_template(T&& org)
// {
//     if(is_lvalue_reference<T>::value) return A(org);
//     else return A(move(org));
// }

template <typename T>
A copy_template(T&& org)
{
    return A(forward<T>(org));
}

int main()
{
    string text = "Witam";

    //Testy do zadania 8
    cout << "Testy do zadania 8: \n";
    A object1(text);
    cout << "Obiekt1 " << object1.get() << endl;
    A object2(object1);
    cout << "Obiekt2 " << object2.get() << endl;
    A object3(move(object2));
    cout << "Obiekt3 " << object3.get() << endl;
    cout << "\n\n";

    //Testy do zadania 9
    cout << "Testy do zadania 9: \n";
    A object1_2(text);
    cout << "Obiekt1_2 " << object1_2.get() << endl;
    A object2_2(copy(object1_2));
    cout << "Obiekt2_2 " << object2_2.get() << endl;
    A object3_2(copy(move(object1_2)));
    cout << "Obiekt3_2 " << object3_2.get() << endl;
    cout << "\n\n";

    //Testy do zadania 10
    cout << "Testy do zadania 10: \n";
    A object1_3(text);
    cout << "Obiekt1_3 " << object1_3.get() << endl;
    A object2_3 = copy_template(object1_3);
    cout << "Obiekt2_3 " << object2_3.get() << endl;
    A object3_3 = copy_template(move(object1_3));
    cout << "Obiekt3_3 " << object3_3.get() << endl;
    cout << "\n\n";
}
