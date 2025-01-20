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
    else if (xn == 4)//если точка единственная, т.е. совпадает с правой границей
    {
        cout << sin(xn) / xn << endl;
        return;
    }
    while (xn <= 4)//если точек много
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
    int x1 = 1, x2 = 1, t, s = 2, n = 2;
    while (s + x1 + x2 <= maxx) //1 1 2 3 5 8
    {
        t = x2;//буферная переменная
        x2 = x1 + t;
        x1 = t;
        s += x2;//сумма
        n++;//счетчик итераций
    }
    if (maxx == 1) 
    {
        cout << "Сумма равна: 1\nКоличество равно: 1\n";
        return;
    }
    else if (maxx == 2)
    {
        cout << "Сумма равна: 2\nКоличество равно: 2\n";
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
    try
    {
        x = stof(s);
    }
    catch (invalid_argument)
    {
        cout << "Нужно ввести число";
    }
    if (s == "0")
    {
        cout << "Граница не может быть равна 0" << endl;
        return 1;
    }
    else func_dots(stof(s));

    cout << "Введите MAX для ряда Фибоначчи: ";
    cin >> s;
    try
    {
        maxx = stoi(s);
    }
    catch (invalid_argument)
    {
        cout << "Нужно ввести число";
        return 1;
    }
    fib(maxx);
}