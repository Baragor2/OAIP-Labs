#include <iostream>
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU"); // Вывод русского текста в консоль

    int counter = 0; 
    string my_str, new_str; // Начальная строка и подстрока

    cout << "\nВведите строку" << endl; // Ввод начальной строки
    cin >> my_str;

    for (int i = 0; i < my_str.size(); i++) {
        if (isdigit(my_str[i])) { // Если элемент строки числовой добавляем в новую строку
            new_str += my_str[i];
        }
        if (new_str.size() >= 1 && my_str[i] == '.') { // Если элемент строки точка, делаем проверку 
            if (counter >= 1) { // Если это вторая точка, то прерывае
                break;
            }
            else { // Иначе добавляем точку в подстроку
                new_str += my_str[i];
                counter++;
            }
        }
    }

    //Если подстрока пуста или точки не найдены или последний элемент равен точке, то число не найдено
    if (new_str.empty() || counter == 0 || new_str[new_str.size() - 1] == '.') {
        cout << "\nЧисло с плавающей точкой не найдено." << endl;
    }
    // Иначе выводим подстроку
    else {
        cout << "\nВаша подстрока: " << new_str << endl;
    }

    return 0;
}