#include <iostream>
#include <tgmath.h>
#include <string>
using namespace std;

void func_dots(float xn)
{
    float i = (4 - xn) / 10;
    xn += i / 2;
    if (xn <= 0 || xn > 4)
    {
        cout << "Граница должна быть больше 0 и не больше 4" << endl;
        return;
    }
    else if (xn == 4)
    {
        cout << sin(xn) / xn << endl;
        return;
    }
    while (xn <= 4)
    {
        cout << sin(xn) / xn << endl;
        xn += i;
    }
}

void fib(int maxx)
{   
    if (maxx <= 0)
    {
        cout << "Сумма должна быть положительной" << endl;
        return;
    }
    int x1, x2, t, s, n;
    x1 = 1;
    x2 = 1;
    s = 2;
    n = 2;
    while (s + x1 + x2 <= maxx) //1 1 2 3 5 8
    {
        t = x2;
        x2 = x1 + t;
        x1 = t;
        s += x2;
        n++;
    }
    if (maxx == 1) 
    {
        cout << "Сумма равна: 1" << endl << "Количество равно: 1" << endl;
        return;
    }
    else if (maxx == 2)
    {
        cout << "Сумма равна: 2" << endl << "Количество равно: 2" << endl;
        return;
    }
    cout << "Сумма равна: " << s << endl;
    cout << "Количество равно: " << n << endl;
}

int main(void)
{
    string s;
    int maxx;
    float x;
    cout << "Введите начальную точку интервала возможных значений функции: ";
    cin >> s;
    try // мне кажется траи написаны неправильно, возможно их поправить нужно
    {
        x = std::stof(s);
    }
    catch (const std::invalid_argument)
    {
        cout << "Нужно ввести число";
    }
    if (s == "0") cout << "Граница не может быть равна 0" << endl;
    else func_dots(std::stof(s));
    cout << "Введите MAX для ряда Фибоначчи: ";
    cin >> s;
    try
    {
        maxx = std::stoi(s);
        return 1;
    }
    catch (const std::invalid_argument)
    {
        cout << "Нужно ввести число";
        return 1;
    }
    fib(maxx);
}