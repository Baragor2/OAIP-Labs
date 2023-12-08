#include <iostream>
#include <math.h>

using namespace std;

int factor(double k) {
    double res = 1, i;

    for (i = 1; i <= k; i++) {
        res = res * i;
    }
    
    return res;
}

int main() {

    setlocale(LC_ALL, "RU");

    double a, b, h, y, n, sum = 0, i = 1;

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
        
        double k = 0, sum = 1;

        while (k < n)
        {
            k++;
            sum += (pow(2 * a, k)) / factor(k);
        }
        cout << i++ << ". " << "Y(x) = " << y << "; S(x) = " << sum <<"; |Y(x) - S(x)| = " << y - sum << endl;
        a += h;
    }

    return 0;
}