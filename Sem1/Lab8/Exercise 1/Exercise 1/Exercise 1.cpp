#include <iostream>
#include <math.h>

using namespace std;

// Функция Out_Rez принимает аргумент и возвращает функцию Y(x)
double Out_Rez(double x) {
    return exp(x) * sin(x);
}

int main() {

    setlocale(LC_ALL, "RU"); //Вывод русского текста в консоль

    double a, b, h, y, i = 1, min_y, max_y;

    cout << "\nВведите значение a: " << endl;
    cin >> a;

    cout << "\nВведите значение b: " << endl;
    cin >> b;

    cout << "\nВведите значение h: " << endl;
    cin >> h;

    // Вычисление начального минимального и максимального значений
    min_y = Out_Rez(a); 
    max_y = Out_Rez(a);

    while (a < b) {
        y = Out_Rez(a); //Запускаем функцию для вычисления Y(x)

        // Проверка на новое минимальное значение
        if (y < min_y) {
            min_y = y;
        }

        // Проверка на новое максимальное значение
        if (y > max_y) { 
            max_y = y;
        }

        cout << i++ << ". " << "x = " << a << "; y = " << y << endl;
        a += h;
    }
    cout << "\nМинимальное значение y: " << min_y << endl;
    cout << "Максимальное значение y: " << max_y << endl;

    return 0;
}

