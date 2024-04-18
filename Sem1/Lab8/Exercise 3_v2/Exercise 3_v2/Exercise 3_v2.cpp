#include <iostream>
using namespace std;

// Обычная функция
int Simple(int arr[], int n) {
    int maximum = arr[0];
    for (int i = 1; i < n; i++) {
        maximum = max(maximum, arr[i]);
    }
    return maximum;
}

// Рекурсивная функция
int Recurs(int arr[], int n) {
    if (n == 1)
        return arr[0];
    else
        return max(arr[n - 1], Recurs(arr, n - 1));
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Максимальный элемент (c помощью обычной функции): " << Simple(arr, n) << endl;
    cout << "Максимальный элемент (с помощью рекурсивной функции): " << Recurs(arr, n) << endl;
    return 0;
}