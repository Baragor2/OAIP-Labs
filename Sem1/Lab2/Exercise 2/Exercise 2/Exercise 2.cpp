#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double z, x, y, a, c;
    int ф;

    cout << "Введите значение z: " << endl;
    cin >> z;

    if (cin.fail()) {
        cout << "\nВведите число.\n";
        return EXIT_FAILURE;
    }

    if (z >= 0) {
        x = (2 * z) + 1;
        cout << "\nz >= 0, поэтому x = (2 * z) + 1" << endl;
    }
    else {
        x = log((z * z) - z);
        cout << "\nz < 0, поэтому x = log((z^2) - z)" << endl;
    }

    cout << "Выберите номер значения функции ф(x)\n1.ф(x) = 2x\n2.ф(x) = x^2\n3.ф(x) = x/3" << endl;
    cin >> ф;

    switch (ф)
    {
    case 1:
        cout << "\nВы выбрали ф = 2 * x" << endl;
        ф = 2 * x;
        break;
    case 2:
        cout << "\nВы выбрали ф = x^2" << endl;
        ф = x * x;
        break;
    case 3:
        ф = x / 3;
        cout << "\nВы выбрали ф = x/3" << endl;
        break;
    default:
        cout << "Вы ввели неверное значение" << "\n";
        return EXIT_FAILURE;
        break;
    }

    cout << "\nВведите значение a: " << endl;
    cin >> a;

    if (cin.fail()) {
        cout << "Введите число.\n";
        return EXIT_FAILURE;
    }

    cout << "\nВведите значение c: " << endl;
    cin >> c;

    if (cin.fail()) {
        cout << "Введите число.\n";
        return EXIT_FAILURE;
    }

    if ((pow((x), 2 / 5.)) <= 0) {
        cout << "\nЧисло в натуральном логарифме должно быть больше 0" << endl;
        return EXIT_FAILURE;
    }

    y = pow(sin(ф), 2) + (a * pow(cos(pow(x, 3)), 5)) + (c * log(pow((x), 2 / 5.)));
    cout << "\ny = " << y << endl;

    return 0;
}