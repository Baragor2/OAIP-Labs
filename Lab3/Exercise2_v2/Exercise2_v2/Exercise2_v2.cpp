#include <iostream>
#include <math.h>

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

        cout << i++ << ". " << "Y(x) = " << y << "; S(x) = " << sum << "; |Y(x) - S(x)| = " << y - sum << endl;
        a += h;
    }

    return 0;
}
