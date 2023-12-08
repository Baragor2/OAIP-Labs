#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

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
        y = exp(2 * a);

        double k = 0, sum = 1, r = 1;

        while (k <= n)
        {
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
