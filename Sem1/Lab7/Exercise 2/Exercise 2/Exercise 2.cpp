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
    cout << "\nФайл создан\n";
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


void del_stud() { // Функция для удаления студента
    string stud_for_del; 
    cout << "Введите фамилию студента, которого надо удалить: ";
    cin >> stud_for_del;
    ifstream file("students.txt"); // Открываем файл для чтения
    ofstream temp_file("temp.txt"); // Создаём временный файл
    string line;
    while (getline(file, line)) {
        int first_space = line.find_first_of(' ');
        if (line.substr(0, first_space) != stud_for_del) { // Если фамилия в строке не равна фамилии для удаления то добавляем в файл
            temp_file << line << "\n";
        }
    }
    file.close(); // Закрытие файла 
    temp_file.close(); // Закрытие файла
    remove("students.txt"); // Удаляем старый файл
    rename("temp.txt", "students.txt"); // Переименовываем временный файл
}


void view() { // Функция для вывода содержимого файла
    ifstream file("students.txt"); // Открываем файл для чтения
    string line;
    while (getline(file, line)) { // Цикл для вывода каждой строки файла
        cout << "\n" << line << "\n";
    }
    file.close(); // Закрытие файла
}


void edit() { // Функция для изменения данных студента
    string stud_for_edit;
    cout << "Введите фамилию студента, данные которого надо изменить: ";
    cin >> stud_for_edit;
    ifstream file("students.txt"); // Открываем файл для чтения
    ofstream temp_file("temp.txt"); // Создаём временный файл
    string line;
    while (getline(file, line)) {
        int first_space = line.find_first_of(' ');
        if (line.substr(0, first_space) == stud_for_edit) { // Если фамилия в строке равна фамилии для редактирования то запрашиваем данные
            Student student;
            cout << "Введите новую фамилию: ";
            cin >> student.surname;
            cout << "Введите новый номер группы: ";
            cin >> student.group_number;
            cout << "Введите новую оценку по физике: ";
            cin >> student.physics_grade;
            cout << "Введите новую оценку по математике: ";
            cin >> student.math_grade;
            cout << "Введите новую оценку по информатике: ";
            cin >> student.cs_grade;

            // Вычисляем новый средний балл
            student.average_grade = (student.physics_grade + student.math_grade + student.cs_grade) / 3.0;

            temp_file << student.surname << " " // Записываем данные во временный файл
                << student.group_number << " "
                << student.physics_grade << " "
                << student.math_grade << " "
                << student.cs_grade << " "
                << student.average_grade << "\n";
        }
        else {
            temp_file << line << "\n"; // Иначе просто добавляем строку во временный файл
        }
    }
    file.close(); // Закрытие файла
    temp_file.close(); // Закрытие файла
    remove("students.txt"); // Удаляем старый файл
    rename("temp.txt", "students.txt"); // Переименовываем временный файл
}


// Функция для сортировки студентов
void sort_students(Student* students, int count, int parameter) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            bool condition;
            switch (parameter) { // Делаем сравнение по выбранному параметру
            case 1: 
                condition = students[j].surname > students[j + 1].surname; 
                break;
            case 2: 
                condition = students[j].group_number > students[j + 1].group_number;
                break;
            case 3: 
                condition = students[j].physics_grade > students[j + 1].physics_grade; 
                break;
            case 4: 
                condition = students[j].math_grade > students[j + 1].math_grade; 
                break;
            case 5: 
                condition = students[j].cs_grade > students[j + 1].cs_grade; 
                break;
            case 6: 
                condition = students[j].average_grade > students[j + 1].average_grade; 
                break;
            default:  // Если ни одна проверка не прошла, то false
                condition = false;
            }
            if (condition) { // Если true, то меняем местами
                swap(students[j], students[j + 1]);
            }
        }
    }
}


// Функция для вывода отсортированных студентов
void sort() {
    cout << "Выберите параметр для сортировки:\n1. Фамилия\n2. Номер группы\n3. Оценка по физике\n4. Оценка по математике\n5. Оценка по информатике\n6. Средний балл\n";
    int parameter;
    cin >> parameter;

    ifstream file("students.txt");
    
    Student students[100]; // Объявляем массив студентов и счетчик студентов.
    int count = 0;

    // Считываем информацию о каждом студенте из файла и увеличиваем счетчик на 1 для каждого студента.
    while (file >> students[count].surname >> students[count].group_number >> students[count].physics_grade >> students[count].math_grade >> students[count].cs_grade >> students[count].average_grade) {
        count++;
    }
    file.close();
    
    // Используем функцию sort_students для сортировки
    sort_students(students, count, parameter);

    // Выводим данные на экран
    for (int i = 0; i < count; i++) {
        cout << students[i].surname << " "
            << students[i].group_number << " "
            << students[i].physics_grade << " "
            << students[i].math_grade << " "
            << students[i].cs_grade << " "
            << students[i].average_grade << "\n";
    }
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
        cout << "\n1. Создать файл\n2. Добавить студента\n3. Просмотреть\n4. Решить индивидуальное задание\n5. Удалить\n6. Редактировать\n7. Сортировка\n8. Выход\n";
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
            case 5:
                del_stud();
                break;
            case 6:
                edit();
                break;
            case 7:
                sort();
                break;
        }
    } while (choice != 8); // Продолжаем цикл пока не введена 5
    return 0;
}