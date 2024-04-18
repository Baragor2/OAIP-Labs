#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    int row, column, i = 0, j = 0, sum, otr;

    cout << "\nВведите количество строк массива" << endl;
    cin >> row;

    cout << "\nВведите количество столбцов массива" << endl;
    cin >> column;

    int** numbers{ new int* [row] {} }; // выделяем память под двухмерный массив

    // выделяем память для вложенных массивов
    for (i = 0; i < row; i++) {
        numbers[i] = new int[column] {};
    }

    for (i = 0; i < row; i++) {
        cout << "Введите данные для строки " << (i + 1) << endl; // вводим данные для столбцов i-й строки
        for (j = 0; j < column; j++){
            cout << (j + 1) << " колонка: ";
            cin >> numbers[i][j];
        }
    }
        
    for (i = 0; i < row; i++) {
            // выводим данные столбцов i-й строки
        for (j = 0; j < column; j++) {
            cout << numbers[i][j] << "\t";
        }
        cout << endl;
    }

    for (i = 0; i < column; i++) {
        sum = 0;
        otr = 0;
        for (j = 0; j < row; j++) { 
            if (numbers[j][i] < 0) { // Если в строке найдётся отрицательное число, увеличиваем счётчик
                otr = 1;
                break;
            }
        }
        if (otr == 1) { // Если счётчик был увеличен, подсчитываем сумму столбца
            for (j = 0; j < row; j++) {
                sum += numbers[j][i];
            }
            cout << "\nСумма элементов в столбце " << i + 1 << ": " << sum << endl;
        }
    }

    return 0;
}