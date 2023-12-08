#include <iostream>
#include <math.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int n, otr = 0, sum = 0;

    cout << "\nВведите длину массива меньше 20: " << endl;
    cin >> n;
    
    while (n > 20) {
        cout << "\nВведённое число больше 20" << endl;
        cout << "\nВведите длину массива меньше 20: " << endl;
        cin >> n;
    }

    float *nums = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "\nВведите значение для элемента с индексом: " << i << endl;
        cin >> nums[int(i)];

        if (nums[i] < 0) {
            otr = i + 1;
        }
    }

    if (otr == 0) {
        cout << "\nМассив должен содержать отрицательное значение" << endl;
        return EXIT_FAILURE;
    }

    for (int i2 = otr; i2 < n; i2++) {
        sum += nums[i2];
    }

    cout << "Сумма значений после последнего отрицательного элемента = " << sum << endl;

    return 0;
}