#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU"); //Вывод русского текста в консоль
    double a, b; //Создание переменных a и b

    cout << "Введите значение a: " << endl;
    //Вывод "Введите значение a: " в консоль

    cin >> a; //Получение значения a от пользователя

    cout << "Введите значение b: " << endl;
    //Вывод "Введите значение b: " в консоль

    cin >> b; //Получение значения b от пользователя

    double z1 = pow(cos(a) - cos(b), 2) - pow(sin(a) - sin(b), 2);
    //Расчёт значения z1

    double z2 = -4 * pow(sin((a - b) / 2), 2) * cos(a + b);
    //Расчёт значения z2

    cout << "\nz1 = " << z1 << endl; //Вывод z1
    cout << "z2 = " << z2 << endl; //Вывод z2

    return 0;
}

