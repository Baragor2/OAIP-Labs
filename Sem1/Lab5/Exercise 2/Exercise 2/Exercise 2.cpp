#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int row, column, i = 0, j = 0, sum;

    cout << "\nВведите количество строк массива" << endl;
    cin >> row;

    cout << "\nВведите количество столбцов массива" << endl;
    cin >> column;

    int** numbers{ new int* [row] {} }; // выделяем память под двухмерный массив
    int* sums = new int[row]; // выделяем память под массив для сумм элементов строк
    int** numbers_sort{ new int* [row] {} }; // выделяем память под двухмерный массив c отсортированными строками

    // выделяем память для вложенных массивов
    for (i = 0; i < row; i++) {
        numbers[i] = new int[column] {};
    }

    for (i = 0; i < row; i++) {
        numbers_sort[i] = new int[column] {};
    }

    for (i = 0; i < row; i++) {
        cout << "Введите данные для строки " << (i + 1) << endl; // вводим данные для столбцов i-й строки
        for (j = 0; j < column; j++) {
            cout << (j + 1) << " колонка: ";
            cin >> numbers[i][j];
        }
    }

    // выводим данные столбцов i-й строки
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            cout << numbers[i][j] << "\t";
        }
        cout << endl;
    }

    // Подсчитываем сумму в строках и добавляем суммы в массив sums
    for (i = 0; i < row; i++) {
        sum = 0;
        for (j = 0; j < column; j++) {
            sum += numbers[i][j];
        }
        sums[int(i)] = sum;
        cout << "\nСумма элементов в строке " << i + 1 << ": " << sum << endl;
    }

    // Копируем исходный массив в массив для сортировки
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            numbers_sort[i][j] = numbers[i][j];
        }
    }

    // Сортируем строки по сумме элементов
    for (i = 0; i < row; i++) {
        for (j = i + 1; j < row; j++) {
            if (sums[i] > sums[j]) {
                swap(sums[i], sums[j]); // Эта функция меняет местами значения переменных
                swap(numbers_sort[i], numbers_sort[j]);
            }
        }
    }

    // Выводим отсортированный массив
    cout << "\nОтсортированный массив:\n";
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            cout << numbers_sort[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}