#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// Функция Out_Rez_Y принимает аргумент и возвращает функцию Y(x)
double Out_Rez_Y(double x) {
    return exp(2 * x);
}

int main() {

    setlocale(LC_ALL, "RU");

    double a, b, h, y, i = 1;

    cout << "\nВведите значение a: " << endl;
    cin >> a;

    cout << "\nВведите значение b: " << endl;
    cin >> b;

    cout << "\nВведите значение h: " << endl;
    cin >> h;

    while (a < b) {
        y = Out_Rez_Y(a);

        double k = 0, sum = 0, r = 1;

        while (abs(y - sum) >= 0.001) {
            k++;
            r = r * 2 * a / k;
            sum += r;
        }



        cout << left << setw(6) << i++;
        cout << left << setw(7) << "Y(x) =";
        cout << left << setw(10) << y;
        cout << left << setw(7) << "S(x) = ";
        cout << left << setw(10) << sum;
        cout << left << setw(10) << "|Y(x) - S(x)| = ";
        cout << left << setw(10) << abs(y - sum) << endl;
        a += h;
    }

    return 0;
}
