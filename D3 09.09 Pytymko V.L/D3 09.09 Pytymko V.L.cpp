// D3 09.09 Pytymko V.L.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1) Напишите предикат, который сравнивает две строки и возвращает true, если первая короче второй.
//  Используйте его в алгоритме sort для сортировки вектора строк в порядке возрастания длины.
//2) Напишите функтор, который сравнивает две строки и возвращает true, если первая короче второй. 
// Используйте его в алгоритме sort для сортировки вектора строк в порядке возрастания длины.
//3) Напишите функтор, который удваивает каждый элемент вектора.
//4) Напишите функтор, который умножает каждый элемент вектора на определенный коэффициент
// (этот коэффициент должен храниться в поле функтора).

#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;


bool pred(const string a, const string b) {
    return a.length() < b.length();
}

class Functor1 {
public:
    bool operator ()(const string a, const string b)  {
        return a.length() < b.length();
    }
};

class Functor2 {
public:
    void operator ()( int& value) const{
         value *= 2;
    }

};
class Functor3 {
    int cof;
public:
    Functor3(int c) :cof(c) {};
    void operator()(int& i)const{
        i *= cof;
    }

};

int main()
{
    vector<string> abc = {"fgjh456gh","rty465u","rtyu","fghjfh","weryerty","dfjhghjg"};

    cout << "vector abc before sort pred :" << endl;

    for (const string& str : abc) {

        cout << str << endl;
    }
    cout << endl;   

    sort(abc.begin(), abc.end(), pred);

    cout << "vector abc after sort pred :" << endl;


   /* Functor1 f1;
    cout << "vector abc before sort functor1 :" << endl;

    for (const string& str : abc) {

        cout << str << endl;
    }
    cout << endl;                        

    sort(abc.begin(), abc.end(), f1);

    cout << "vector abc after sort functor1 :" << endl;*/

    for (const string& str : abc) {

        cout << str << endl;
    }
    cout << endl;

    vector<int> A = { 2,4,6,8,1,3,5,7,9 };
    cout << "vector A before functor2 :" << endl;

    for (const int& i :A) {

        cout << i << " ";
        }
    cout << endl;
    Functor2 f2;
    for_each(A.begin(), A.end(), f2);

    cout << "vector A after functor2 :" << endl;
    for (const int& value : A) {

        cout << value << " ";
    }
    cout << endl;
    int cof = 5;
    Functor3 f3(cof);

    for_each(A.begin(), A.end(), f3);
    cout << "vector A after functor3 :" << endl;
    for (const int& value : A) {

        cout << value << " ";
    }
    
    cout << endl;

    return 0;
}




