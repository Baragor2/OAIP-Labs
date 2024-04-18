#include <iostream>
#include <string>

using namespace std;

// Объявление структуры стека
struct Stack {
	char info;
	Stack* next;
} *beg;

Stack* t, * Op = NULL;

int k = 0, l = 0;
char a, str1[50], str2[50];
double mas[5];

// Функция для добавления элемента в стек
Stack* InStack(Stack* p, char info) {
	Stack* t = new Stack;
	t->info = info;
	t->next = p;

	return t;
}

// Функция для удаления элемента стека
Stack* OutStack(Stack* p, char* info) {
	Stack* t = p;
	*info = t->info;
	p = p->next;
	delete t;

	return p;
}

// Функция для определения приоритета операции
int Prior(char a) {

	switch (a) {
	case '*': case '/': return 3;
	case '-': case '+': return 2;
	case '(': return 1;
	}

	return 0;
}

// Функция для формирования ОПЗ
void Post(char* str1) {

	// Перебираем пока не достигнем конца строки
	while (str1[k] != '\0') {

		if (str1[k] == ')') {

			while ((Op->info) != '(') {
				Op = OutStack(Op, &a);
				if (!Op) {
					a = '\0';
				}
				str2[l++] = a;
			}
			t = Op;
			Op = Op->next;
			delete t;
		}

		// Если буква добавляем в ОПЗ
		if (str1[k] >= 'a' && str1[k] <= 'z') { 
			str2[l++] = str1[k];
		}

		if (str1[k] == '(') {
			Op = InStack(Op, str1[k]);
		}

		if (str1[k] == '+' || str1[k] == '-' || str1[k] == '*' || str1[k] == '/') {

			// Пока стек не пуст и приоритет вершины стека больше или равен приоритету текущей операции: удаляем из стека и добавляем в ОПЗ
			while (Op != NULL && Prior(Op->info) >= Prior(str1[k])) {
				Op = OutStack(Op, &a);
				str2[l++] = a;
			}
			Op = InStack(Op, str1[k]);
		}
		k++;
	}

	while (Op != NULL) {
		Op = OutStack(Op, &a);
		str2[l++] = a;
	}
	str2[l] = '\0';
	cout << "Обратная польская запись: " << str2 << endl;
}

// Функция для расчёта результата
void result(char* Str) {
	char ch, ch1, ch2;
	double res = 0, op1, op2;
	char chr = 'z';
	for (int i = 0; i < strlen(Str); i++) {
		ch = Str[i];

		// Если текущий символ - буква, то добавляем его в стек beg
		if (ch >= 'a' && ch <= 'z') {
			beg = InStack(beg, ch);
		}
		// Иначе текущий символ - операция
		else {
			beg = OutStack(beg, &ch1);

			beg = OutStack(beg, &ch2);

			op1 = mas[int(ch1) - 97];

			op2 = mas[int(ch2) - 97];

			switch (ch) {
			case '+': 
				res = op2 + op1; 
				break;
			case '-': 
				res = op2 - op1; 
				break;
			case '*':
				res = op2 * op1; break;
			case '/': 
				res = op2 / op1; 
				break;
			}

			mas[int(chr) - 97] = res;
			beg = InStack(beg, chr);
			chr--;
		}
	}
	cout << "Численное значение = " << res << endl;
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RU");

	cout << "Введите выражение: ";
	cin >> str1;
	cout << "Введите 5 чисел: ";
	for(int i = 0; i < 5; i++) {
		cin >> mas[i];
	}
	Post(str1);
	result(str2);

	return 0;
}
