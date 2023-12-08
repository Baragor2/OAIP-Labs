#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    double a, z1, z2;

    cout << "Введите значение a: " << endl;
    cin >> a;

    if (!(a) && a != 0) {
        cout << "Введите число\n";
        return EXIT_FAILURE;
    }

   if (pow(a, 2) - 4 < 0 || 2 * a + 2 * sqrt(pow(a, 2) - 4) < 0 || a + 2 < 0) {
        cout << "Под корнем отрицательное значение";
        return EXIT_FAILURE;
   }

    if (sqrt(pow(a, 2) - 4) + a + 2 == 0) {
        cout << "На ноль делить нельзя";
        return EXIT_FAILURE;
    }
    
    z1 = (sqrt(2 * a + 2 * sqrt(pow(a, 2) - 4))) / (sqrt(pow(a, 2) - 4) + a + 2);
    z2 = 1 / (sqrt(a + 2));
    cout << "\nz1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    return 0;
}

