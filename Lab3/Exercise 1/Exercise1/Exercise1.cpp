#include <iostream>
#include <math.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    double a, b, h, y, i = 1, min_y, max_y; 

    cout << "\nВведите значение a: " << endl;
    cin >> a;

    cout << "\nВведите значение b: " << endl;
    cin >> b;

    cout << "\nВведите значение h: " << endl;
    cin >> h;

    min_y = exp(a) * sin(a);
    max_y = exp(a) * sin(a);

    while (a < b) {
        y = exp(a) * sin(a);

        if (y < min_y)
        {
            min_y = y;
        }

        if (y > max_y)
        {
            max_y = y;
        }

        cout << i++ << ". " << "x = " << a << "; y = " << y << endl;
        a += h;
    }
    cout << "\nМинимальное значение y: " << min_y << endl;
    cout << "Максимальное значение y: " << max_y << endl;

    return 0;
}