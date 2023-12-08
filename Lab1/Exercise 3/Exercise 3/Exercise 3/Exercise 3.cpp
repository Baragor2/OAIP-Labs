#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double x, y, z, a;

    cout << "Введите значение x: " << endl;
    cin >> x;

    if (x != -0.02235) {
        cout << "Значение x должно быть равно -0.02235";
        return EXIT_FAILURE;
    }

    cout << "Введите значение y: " << endl;
    cin >> y;

    if (y != 2.23) {
        cout << "Значение y должно быть равно 2.23";
        return EXIT_FAILURE;
    }

    cout << "Введите значение z: " << endl;
    cin >> z;

    if (z != 15.221) {
        cout << "Значение z должно быть равно 15.221";
        return EXIT_FAILURE;
    }

    if (!(x) || !(y) || !(z)) {
        cout << "Введите число\n";
        return EXIT_FAILURE;
    }

    if(atan(x) + atan(z) == 0) {
        cout << "На ноль делить нельзя";
        return EXIT_FAILURE;
    }

    a = (((exp(fabs(x - y))) * pow(fabs(x - y), x + y)) / ((atan(x) + atan(z)))) + pow(pow(x, 6) + pow(log(y), 2), 1/3);
    cout << "\nф = " << a << endl;

    return 0;
}