#include <iostream>
#include <math.h>

using namespace std;


double max(double a, double b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}


int main() {
    setlocale(LC_ALL, "RU");
    double x, y, z, m, max1, max2;

    cout << "Введите значение x: " << endl;
    cin >> x;

    if (cin.fail()) {
        cout << "\nВведите число.\n";
        return EXIT_FAILURE;
    }

    cout << "\nВведите значение y: " << endl;
    cin >> y;

    if (cin.fail()) {
        cout << "\nВведите число.\n";
        return EXIT_FAILURE;
    }

    cout << "\nВведите значение z: " << endl;
    cin >> z;

    if (cin.fail()) {
        cout << "\nВведите число.\n";
        return EXIT_FAILURE;
    }

    max1 = max(x + y + z, x * y * z);
    
    max2 = max(x + y + z, x / (y * z));

    if (max2 == 0) {
        cout << "На ноль делить нельзя";
        return EXIT_FAILURE;
    }

    if (max2 == x / (y * z) && (y * z) == 0) {
        cout << "На ноль делить нельзя";
        return EXIT_FAILURE;
    }

    m = max1 / max2;
    cout << "\nm = " << m << endl;

    return 0;
}