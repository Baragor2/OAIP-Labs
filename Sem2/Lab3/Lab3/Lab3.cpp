#include <iostream>
#include <stack>

// Определение структуры для элементов стека
struct Stack {
    int info;
    Stack* next;
};

// Функция для перестановки адресов двух соседних элементов, слелдующих за элементом с известным указателем
void Sort_p(Stack** p) {
    Stack* t = NULL;
    Stack* t1;
    Stack* r;
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next) {
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        }
        t = t1->next;
    } while ((*p)->next->next != t);
}

//Функция для обмена информацей между текущим и следующим элементами
void Sort_info(Stack* p) {
    Stack* t = NULL;
    Stack* t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next) {
            if (t1->info > t1->next->info) {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        }
        t = t1;
    } while (p->next != t);
}

void moveBetweenTopAndMin(Stack* source, Stack* dest) {
    if (source == NULL || source->next == NULL) {
        return; // Недостаточно элементов для переноса
    }

    //Поиск минимального элмента
    int minVal = source->info;
    Stack* temp = source;
    while (temp != NULL) {
        minVal = std::min(minVal, temp->info);
        temp = temp->next;
    }

    //Перенос элементов между вершиной и минимальным элементом
    temp = source;
    while (temp->next != NULL && temp->next->info != minVal) {
        dest->next = new Stack{ temp->next->info, NULL };
        dest = dest->next;
        temp = temp->next;
    }
}

    
int main() {
    setlocale(LC_ALL, "RU");
    using namespace std;

    Stack* myStack = NULL;
    int n;
    cout << "Введите количество элементов в стеке: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> val;
        myStack = new Stack{ val, myStack };
        }

    // Создаем новый стек для переноса элементов
    Stack* newStack = new Stack{ 0, NULL };

    // Переносим элементы между вершиной и минимальным элементом
    moveBetweenTopAndMin(myStack, newStack);

    // Выводим элементы нового стека
    cout << "Элементы между вершиной и минимальным: ";
    Stack* temp = newStack->next;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
        cout << endl;


    Sort_info(myStack);

    // Вывод отсортированных элементов
    cout << "Функция для обмена информацей между текущим и следующим элементами: ";
    temp = myStack;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;


    // Сортировка по значениям элементов
    Sort_p(&myStack);

    // Вывод отсортированных элементов
    cout << "Функция для перестановки адресов двух соседних элементов, слелдующих за элементом с известным указателем: ";
    temp = myStack;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;


    // Очистка памяти
    while (myStack != NULL) {
        temp = myStack;
        myStack = myStack->next;
        delete temp;
    }
    while (newStack != NULL) {
        temp = newStack;
        newStack = newStack->next;
        delete temp;
    }

    return 0;
}