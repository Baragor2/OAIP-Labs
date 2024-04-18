#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Вывод русского текста в консоль

struct Book { // Создание структуры книги со всеми показателями
    int id;
    string author;
    string title;
    int year;
    string publish;
    int pages;
};


void create() { // Функция для создания файла
    ofstream file("library.txt"); // Создание файла
    cout << "\nФайл создан\n";
    file.close(); // Закрытие файла
}


void add() { // Функция для создания объекта структуры студент
    Book book;
    cout << "Введите id: "; // Последовательно запрашиваем информацию и добавляем в структуру
    cin >> book.id;
    cout << "Введите автора: ";
    cin >> book.author;
    cout << "Введите название: ";
    cin >> book.title;
    cout << "Введите год издания: ";
    cin >> book.year;
    cout << "Введите издательство: ";
    cin >> book.publish;
    cout << "Введите количество страниц: ";
    cin >> book.pages;

    // открываем файл в режиме добавления и записываем информацию о книге в файл
    ofstream file("library.txt", ios::app);
    file << book.id << " "
        << book.author << " "
        << book.title << " "
        << book.year << " "
        << book.publish << " "
        << book.pages << "\n";
    file.close(); // Закрытие файла
}


void del_book() { // Функция для удаления книги
    string book_for_del;
    cout << "Введите id книги, которую надо удалить: ";
    cin >> book_for_del;
    ifstream file("library.txt"); // Открываем файл для чтения
    ofstream temp_file("temp.txt"); // Создаём временный файл
    string line;
    while (getline(file, line)) {
        int first_space = line.find_first_of(' ');
        if (line.substr(0, first_space) != book_for_del) { // Если id в строке не равен id для удаления то добавляем в файл
            temp_file << line << "\n";
        }
    }
    file.close(); // Закрытие файла 
    temp_file.close(); // Закрытие файла
    remove("library.txt"); // Удаляем старый файл
    rename("temp.txt", "library.txt"); // Переименовываем временный файл
}


void view() { // Функция для вывода содержимого файла
    ifstream file("library.txt"); // Открываем файл для чтения
    string line;
    while (getline(file, line)) { // Цикл для вывода каждой строки файла
        cout << "\n" << line << "\n";
    }
    file.close(); // Закрытие файла
}


void edit() { // Функция для изменения данных книги
    string book_for_edit;
    cout << "Введите id книги, данные которой надо изменить: ";
    cin >> book_for_edit;
    ifstream file("library.txt"); // Открываем файл для чтения
    ofstream temp_file("temp.txt"); // Создаём временный файл
    string line;
    while (getline(file, line)) {
        int first_space = line.find_first_of(' ');
        if (line.substr(0, first_space) == book_for_edit) { // Если id в строке равна id для редактирования то запрашиваем данные
            Book book;
            cout << "Введите новое id: ";
            cin >> book.id;
            cout << "Введите нового автора: ";
            cin >> book.author;
            cout << "Введите новое название: ";
            cin >> book.title;
            cout << "Введите новый год издания: ";
            cin >> book.year;
            cout << "Введите новое издательство: ";
            cin >> book.publish;
            cout << "Введите новое число страниц: ";
            cin >> book.pages;

            temp_file << book.id << " " // Записываем данные во временный файл
                << book.author << " "
                << book.title << " "
                << book.year << " "
                << book.publish << " "
                << book.pages << "\n";
        }
        else {
            temp_file << line << "\n"; // Иначе просто добавляем строку во временный файл
        }
    }
    file.close(); // Закрытие файла
    temp_file.close(); // Закрытие файла
    remove("library.txt"); // Удаляем старый файл
    rename("temp.txt", "library.txt"); // Переименовываем временный файл
}


void selection_sort(int param) {
    ifstream file("library.txt");

    Book books[100]; // Объявляем массив книг и счетчик книг.
    int count = 0;

    // Считываем информацию о каждой книге из файла и увеличиваем счетчик на 1 для каждой книги.
    while (file >> books[count].id >> books[count].author >> books[count].title >> books[count].year >> books[count].publish >> books[count].pages) {
        count++;
    }
    file.close();


    int min;
    for (int i = 0; i < count - 1; i++) {
        min = i;
        for (int j = i + 1; j < count; j++) {
            switch (param) { // делаем сравнение по выбранному параметру
            case 1:
                if (books[j].id < books[min].id) min = j;
                break;
            case 2:
                if (books[j].author < books[min].author) min = j;
                break;
            case 3:
                if (books[j].title < books[min].title) min = j;
                break;
            case 4:
                if (books[j].year < books[min].year) min = j;
                break;
            case 5:
                if (books[j].publish < books[min].publish) min = j;
                break;
            case 6:
                if (books[j].pages < books[min].pages) min = j;
                break;
            }
        }
        swap(books[i], books[min]);
    }

    // Выводим данные на экран
    for (int i = 0; i < count; i++) {
        cout << books[i].id << " "
            << books[i].author << " "
            << books[i].title << " "
            << books[i].year << " "
            << books[i].publish << " "
            << books[i].pages << "\n";
    }
}


bool compare(Book a, Book b, int param) { // Функция для сравнения двух книг по определённому параметру
    switch (param) {
    case 1:
        return a.id < b.id;
    case 2:
        return a.author < b.author;
    case 3:
        return a.title < b.title;
    case 4:
        return a.year < b.year;
    case 5:
        return a.publish < b.publish;
    case 6:
        return a.pages < b.pages;
    }
    return false;
}


int partition(Book books[], int low, int high, int param) { // Алгоритм быстрой сортировки
    Book pivot = books[high];
    int i = low;
    int j = high - 1;

    while (i <= j) {
        while (compare(books[i], pivot, param)) i++;
        while (compare(pivot, books[j], param)) j--;
        if (i <= j) {
            swap(books[i], books[j]);
            i++;
            j--;
        }
    }
    swap(books[i], books[high]);
    return i;
}


void quick_sort(Book books[], int low, int high, int param) { // Базовая функция быстрой сортировки
    if (low < high) {
        int pi = partition(books, low, high, param);

        quick_sort(books, low, pi - 1, param);
        quick_sort(books, pi + 1, high, param);
    }

}


void sort() { // Базовая функция для выбора способа сортировки
    int choice, param;
    cout << "\nВыберите поле для сортировки:\n1. ID\n2. Автор\n3. Название\n4. Год издания\n5. Издательство\n6. Количество страниц\n";
    cin >> param;
    do {
        cout << "\n1. Сортировка выбором\n2. Быстрая сортировка\n3. Выход\n";
        cin >> choice;
        switch (choice) {
        case 1:
            selection_sort(param);
            break;
        case 2:
            ifstream file("library.txt");
            Book books[100];
            int count = 0;

            while (file >> books[count].id >> books[count].author >> books[count].title >> books[count].year >> books[count].publish >> books[count].pages) {
                count++;
            }
            file.close();
            quick_sort(books, 0, count - 1, param);

            for (int i = 0; i < count; i++) {
                cout << books[i].id << " "
                    << books[i].author << " "
                    << books[i].title << " "
                    << books[i].year << " "
                    << books[i].publish << " "
                    << books[i].pages << "\n";
            }

            break;
        }
    } while (choice != 3);
}


void linear_search() { // Функция линейного поиска
    int param;
    cout << "\nВыберите параметр для поиска:\n1. ID\n2. Автор\n3. Название\n4. Год издания\n5. Издательство\n6. Количество страниц\n";
    cin >> param;

    string value;
    cout << "Введите значение для поиска: ";
    cin >> value;

    ifstream file("library.txt");
    Book books[100];
    int count = 0;
    while (file >> books[count].id >> books[count].author >> books[count].title >> books[count].year >> books[count].publish >> books[count].pages) {
        count++;
    }
    file.close();

    for (int i = 0; i < count; i++) {
        switch (param) {
        case 1:
            if (to_string(books[i].id) == value) {
                cout << "ID книги: " << books[i].id << "\n";
                return;
            }
            break;
        case 2:
            if (books[i].author == value) {
                cout << "ID книги: " << books[i].id << "\n";
                return;
            }
            break;
        case 3:
            if (books[i].title == value) {
                cout << "ID книги: " << books[i].id << "\n";
                return;
            }
            break;
        case 4:
            if (to_string(books[i].year) == value) {
                cout << "ID книги: " << books[i].id << "\n";
                return;
            }
            break;
        case 5:
            if (books[i].publish == value) {
                cout << "ID книги: " << books[i].id << "\n";
                return;
            }
            break;
        case 6:
            if (to_string(books[i].pages) == value) {
                cout << "ID книги: " << books[i].id << "\n";
                return;
            }
            break;
        }
    }
    cout << "Книга не найдена.\n";
}


void binary_search() { // Функция бинарного поиска
    int param;
    cout << "\nВыберите параметр для поиска:\n1. ID\n2. Автор\n3. Название\n4. Год издания\n5. Издательство\n6. Количество страниц\n";
    cin >> param;

    string value;
    cout << "Введите значение для поиска: ";
    cin >> value;

    ifstream file("library.txt");
    Book books[100];
    int count = 0;
    while (file >> books[count].id >> books[count].author >> books[count].title >> books[count].year >> books[count].publish >> books[count].pages) {
        count++;
    }
    file.close();

    // Сортируем книги перед бинарным поиском
    quick_sort(books, 0, count - 1, param);

    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string mid_value;
        switch (param) {
        case 1:
            mid_value = to_string(books[mid].id);
            break;
        case 2:
            mid_value = books[mid].author;
            break;
        case 3:
            mid_value = books[mid].title;
            break;
        case 4:
            mid_value = to_string(books[mid].year);
            break;
        case 5:
            mid_value = books[mid].publish;
            break;
        case 6:
            mid_value = to_string(books[mid].pages);
            break;
        }

        if (mid_value == value) {
            cout << "ID книги: " << books[mid].id << "\n";
            return;
        }

        if (mid_value < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << "Книга не найдена.\n";
}


void search() { // Базовая функция для выбора способа поиска
    int choice;
    do {
        cout << "\n1. Линейный поиск\n2. Бинарный поиск\n3. Выход\n";
        cin >> choice;
        switch (choice) {
        case 1:
            linear_search();
            break;
        case 2:
            binary_search();
        }
    } while (choice != 3);
}


void individual_task() { // Функция для выполнения индивидуального задания
    ifstream file("library.txt");
    Book books[100];
    int count = 0;

    int value;
    cout << "Введите год издания после которого необходимы книги: ";
    cin >> value;
    
    while (file >> books[count].id >> books[count].author >> books[count].title >> books[count].year >> books[count].publish >> books[count].pages) {
        count++;
    }
    file.close();
    quick_sort(books, 0, count - 1, 2);

    for (int i = 0; i < count; i++) {
        if (books[i].year > value) {
            cout << books[i].id << " "
                << books[i].author << " "
                << books[i].title << " "
                << books[i].year << " "
                << books[i].publish << " "
                << books[i].pages << "\n";
        }
    }
}


int main() {
    setlocale(LC_ALL, "RU");

    int choice;
    do { // Запускаем цикл do while 
        cout << "\n1. Создать файл\n2. Добавить книгу\n3. Просмотреть\n4. Решить индивидуальное задание\n5. Удалить\n6. Редактировать\n7. Поиск\n8. Сортировка\n9. Выход\n";
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
            del_book();
            break;
        case 6:
            edit();
            break;
        case 7:
            search();
            break;
        case 8:
            sort();
            break;
        }
    } while (choice != 9); // Продолжаем цикл пока не введена 9
    return 0;
}