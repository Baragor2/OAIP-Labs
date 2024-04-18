#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// Функция Out_Rez_Y принимает аргумент и возвращает функцию Y(x)
double Out_Rez_Y(double x) {
    return exp(2 * x);
}

// Функция Out_Rez_S принимает аргументы и возвращает функцию S(x)
double Out_Rez_S(int k, double a, int n) {
    double sum = 1, r = 1;
    while (k <= n) {
        k++;
        r = r * 2 * a / k;
        sum += r;
    }
    return sum;
}

// Функция Out_Rez_Y_S принимает аргументы и возвращает модуль разности функций
double Out_Rez_Y_S(double y, double sum) {
    return abs(y - sum);
}


int main() {

    setlocale(LC_ALL, "RU"); //Вывод русского текста в консоль

    double a, b, h, y, n, i = 1;

    cout << "\nВведите значение a: " << endl;
    cin >> a;

    cout << "\nВведите значение b: " << endl;
    cin >> b;

    cout << "\nВведите значение h: " << endl;
    cin >> h;

    cout << "\nВведите значение n: " << endl;
    cin >> n;

    while (a < b) {
        y = Out_Rez_Y(a); //Запускаем функцию для вычисления Y(x)

        double k = 0, sum;

        sum = Out_Rez_S(k, a, n); //Запускаем функцию для вычисления S(x)

        // Выводим данные в виде таблицы
        cout << left << setw(6) << i++;
        cout << left << setw(7) << "Y(x) =";
        cout << left << setw(10) << y;
        cout << left << setw(7) << "S(x) = ";
        cout << left << setw(10) << sum;
        cout << left << setw(10) << "|Y(x) - S(x)| = ";
        cout << left << setw(10) << Out_Rez_Y_S(y, sum) << endl;
        a += h;
    }

    return 0;
}
