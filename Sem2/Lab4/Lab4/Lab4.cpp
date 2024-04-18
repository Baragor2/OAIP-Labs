#include <iostream>
#include <queue>

// Определение структуры для элементов очереди
struct Queue {
    int info;
    Queue* next;
    Queue* prev;
};

// Функция для перестановки адресов двух соседних элементов, слелдующих за элементом с известным указателем
void Sort_p(Queue** p) {
    Queue* t = NULL;
    Queue* t1;
    Queue* r;
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next) {
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
                if (r->next) r->next->prev = r;
                if (t1->next) t1->next->prev = t1;
            }
        }
        t = t1->next;
    } while ((*p)->next->next != t);
}

//Функция для обмена информацей между текущим и следующим элементами
void Sort_info(Queue* p) {
    Queue* t = NULL;
    Queue* t1;
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

void moveBetweenTopAndMin(Queue* source, Queue* dest) {
    if (source == NULL || source->next == NULL) {
        return; // Недостаточно элементов для переноса
    }

    //Поиск минимального элемента
    int minVal = source->info;
    Queue* temp = source;
    while (temp != NULL) {
        minVal = std::min(minVal, temp->info);
        temp = temp->next;
    }

    //Перенос элементов между вершиной и минимальным элементом
    temp = source;
    while (temp->next != NULL && temp->next->info != minVal) {
        dest->next = new Queue{ temp->next->info, NULL, dest };
        dest = dest->next;
        temp = temp->next;
    }
}

// Функция для добавления элемента в начало очереди
void push_front(Queue** head, int new_info) {
    Queue* new_node = new Queue;
    new_node->info = new_info;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}

// Функция для добавления элемента в конец очереди
void push_back(Queue** head, int new_info) {
    Queue* new_node = new Queue;
    Queue* last = *head;
    new_node->info = new_info;
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

// Функция для вывода всех элементов с начала
void print_from_front(Queue* node) {
    while (node != NULL) {
        std::cout << node->info << " ";
        node = node->next;
    }
}

// Функция для вывода всех элементов с конца
void print_from_back(Queue* node) {
    if (node == NULL)
        return;
    while (node->next != NULL) {
        node = node->next;
    }
    while (node != NULL) {
        std::cout << node->info << " ";
        node = node->prev;
    }
}


int main() {
    setlocale(LC_ALL, "RU");
    using namespace std;

    Queue* myQueue = NULL;
    int n;
    cout << "Введите количество элементов в очереди: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> val;
        myQueue = new Queue{ val, myQueue, NULL };
        if (myQueue->next) myQueue->next->prev = myQueue;
    }

    // Создаем новую очередь для переноса элементов
    Queue* newQueue = new Queue{ 0, NULL, NULL };

    // Переносим элементы между вершиной и минимальным элементом
    moveBetweenTopAndMin(myQueue, newQueue);

    // Выводим элементы новой очереди
    cout << "Элементы между вершиной и минимальным: ";
    Queue* temp = newQueue->next;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;


    Sort_info(myQueue);

    // Вывод отсортированных элементов
    cout << "Функция для обмена информацей между текущим и следующим элементами: ";
    temp = myQueue;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;


    // Сортировка по значениям элементов
    Sort_p(&myQueue);

    // Вывод отсортированных элементов
    cout << "Функция для перестановки адресов двух соседних элементов, слелдующих за элементом с известным указателем: ";
    temp = myQueue;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;

    // Добавление элемента в начало очереди
    cout << "Введите элемент для добавления в начало очереди: ";
    int front_val;
    cin >> front_val;
    push_front(&myQueue, front_val);

    // Добавление элемента в конец очереди
    cout << "Введите элемент для добавления в конец очереди: ";
    int back_val;
    cin >> back_val;
    push_back(&myQueue, back_val);

    cout << "Функция для вывода всех элементов с начала: ";
    print_from_front(myQueue);
    cout << endl;

    cout << "Функция для вывода всех элементов с конца: ";
    print_from_back(myQueue);

    // Очистка памяти
    while (myQueue != NULL) {
        temp = myQueue;
        myQueue = myQueue->next;
        delete temp;
    }
    while (newQueue != NULL) {
        temp = newQueue;
        newQueue = newQueue->next;
        delete temp;
    }

    return 0;
}
