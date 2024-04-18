#include <iostream>
//#include <cstdlib>
//#include <ctime>
#include <random>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int n, proizv = 1, sw, count_zero = 0, ind_first_zero, ind_second_zero, between_zeros = 0;

    cout << "\nВведите длину массива меньше 20: " << endl;
    cin >> n;

    while (n > 20) {
        cout << "\nВведённое число больше 20" << endl;
        cout << "\nВведите длину массива меньше 20: " << endl;
        cin >> n;
    }

    int* nums = new int[n];

    cout << "\nВыберите как получать значения\n1.Ручной ввод\n2.Случайное добавление значений" << endl;
    cin >> sw;

    switch (sw)
    {
    case 1:
        for (int i = 0; i < n; i++) {
            cout << "\nВведите значение для элемента с индексом: " << i << endl;
            cin >> nums[int(i)];
        }
        break;

    case 2:
        //srand(time(0));
        //for (int i = 0; i < n; i++) {
        //    nums[int(i)] = rand() % 200001 - 100000;
        //}
        cout << "\nСписок сгенерирован случайно" << endl;
        random_device random_device;
        mt19937 generator(random_device());
        uniform_int_distribution<> distribution(-100, 100);
        for (int i = 0; i < n; i++) {
                nums[int(i)] = distribution(generator);
        }
        break;
    }


    for (int i = 0; i < n; i++) {
        if (nums[i] == 0 && count_zero == 1) {
            ind_second_zero = i;
            count_zero++;
            break;
        }
        if (nums[i] == 0 && count_zero == 0) {
            ind_first_zero = i + 1;
            count_zero++;
        }
    }

    if (count_zero < 2) {
        cout << "\nВ списке отсутствует два нулевых элемента\n";
        return EXIT_FAILURE;
    }

    while (ind_first_zero < ind_second_zero) {
        if ((nums[ind_first_zero] % 2) == 0) {
            proizv *= nums[ind_first_zero];
            between_zeros++;
        }
        ind_first_zero++;
    }

    if (between_zeros == 0) {
        cout << "\nМежду первым и вторым нулевыми элементами отсутсвуют чётные числа\n";
        return EXIT_FAILURE;
    }

    cout << "Произведение равно " << proizv << endl;

    return 0;
}