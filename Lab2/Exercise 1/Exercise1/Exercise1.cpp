#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU"); //Вывод русского текста в консоль
    double z, x, y; //Создание переменных z, x и y

    cout << "Введите значение z: " << endl; //Вывод "Введите значение z: " в консоль
    cin >> z; //Получение значения z от пользователя

    if (z >= 0) {
        x = (2 * z) + 1;
        cout << "\nz >= 0, поэтому x = (2 * z) + 1" << endl;
    }
    else {
        x = log((z * z) - z);
        cout << "\nz < 0, поэтому x = log((z^2) - z)" << endl;
    }
    //Проверка z и выбор формулы x

    y = pow(sin(x), 2) + pow(cos(pow(x, 3)), 5) + log(pow((x), 2/5.));
    //Вычисление значения y

    cout << "y = " << y << endl;//Вывод y
    return 0;
}
