#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU"); // Вывод русского текста в консоль

    // Задаём строку и счётчик
    int counter = 0;
    string my_str;

    cout << "\nВведите строку" << endl; // Ввод строки
    cin >> my_str;

    for (int i = 0; i < my_str.size(); i++) {
        if (my_str[i] == '!') { // Если элемент строки !, то увеличиваем счётчик
            counter++;
            if (counter % 2 == 0) { // Если значение счётчика чётное, то меняем ! на $
                my_str[i] = '$';
            }
        }
    }

    cout << "\nВаша строка: " << my_str << endl; // Выводим изменённую строку

    return 0;
}

