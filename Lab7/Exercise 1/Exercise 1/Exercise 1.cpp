#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Вывод русского текста в консоль

struct Student { // Создание структуры студент со всеми показателями
    string surname;
    int group_number;
    int physics_grade;
    int math_grade;
    int cs_grade;
    double average_grade;
};

void create() { // Функция для создания файла
    ofstream file("students.txt"); // Создание файла
    file.close(); // Закрытие файла
}

void add() { // Функция для создания объекта структуры студент
    Student student;
    cout << "Введите фамилию: "; // Последовательно запрашиваем информацию и добавляем в структуру
    cin >> student.surname;
    cout << "Введите номер группы: ";
    cin >> student.group_number;
    cout << "Введите оценку по физике: ";
    cin >> student.physics_grade;
    cout << "Введите оценку по математике: ";
    cin >> student.math_grade;
    cout << "Введите оценку по информатике: ";
    cin >> student.cs_grade;
    // Вычисление среднего балла студента
    student.average_grade = (student.physics_grade + student.math_grade + student.cs_grade) / 3.0; 

    // открываем файл в режиме добавления и записываем информацию о студенте в файл
    ofstream file("students.txt", ios::app);
    file << student.surname << " "
        << student.group_number << " "
        << student.physics_grade << " "
        << student.math_grade << " "
        << student.cs_grade << " "
        << student.average_grade << "\n";
    file.close(); // Закрытие файла
}

void view() { // Функция для вывода содержимого файла
    ifstream file("students.txt");
    string line;
    while (getline(file, line)) { // Цикл для вывода каждой строки файла
        cout << line << "\n";
    }
    file.close(); // Закрытие файла
}

void individual_task() { // Функция для выполнения индивидуального задания
    ifstream file("students.txt"); // Открываем файл для чтения
    string line;
    double total_average = 0;
    int count = 0;
    while (getline(file, line)) { 
        int last_space = line.find_last_of(' '); // find_last_of ищет последнее вхождение пробела
        // stod преобразует строку в число
        total_average += stod(line.substr(last_space + 1)); // substr возвращает средний балл из строки
        count++;
    }
    total_average /= count; // Вычисляем общий средний балл
    file.close(); // Закрытие файла

    cout << "Общий средний балл всех студентов: " << total_average << "\n";
    cout << "Студенты со средним баллом выше общего среднего балла:\n";

    file.open("students.txt");
    ofstream above_average_file("above_average.txt"); // Создаём новый файл для тех у кого средний балл выше среднего
    while (getline(file, line)) { // Перебираем каждую строку файла
        int last_space = line.find_last_of(' '); // Находим последний пробел
        if (stod(line.substr(last_space + 1)) > total_average) { // Если найденный средний балл больше общего, то добавляем в новый файл
            above_average_file << line << "\n";
            cout << line << "\n";
        }
    }
    file.close(); // Закрытие файла
    above_average_file.close(); // Закрытие файла с теми 
}


int main() {
    setlocale(LC_ALL, "RU");

    int choice; 
    do { // Запускаем цикл do while 
        cout << "\n1. Создать файл\n2. Добавить студента\n3. Просмотреть\n4. Решить индивидуальное задание\n5. Выход\n";
        cin >> choice;
        switch (choice) { // Используем switch для выбора функции
        case 1:
            create();
            break;
        case 2:
            add();
            break;
        case 3:
            view();
            break;
        case 4:
            individual_task();
            break;
        }
    } while (choice != 5); // Продолжаем цикл пока не введена 5
    return 0;
}