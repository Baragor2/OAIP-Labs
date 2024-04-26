#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Node {
	int key;
	char string_data[50];
	Node* left_child;
	Node* right_child;
};

// Функция для создания узла
Node* getNewNode(int key, char* info) {
	Node* t = new Node;
	t->key = key;

	// Копируем информацию в узел
	strcpy_s(t->string_data, info);

	t->left_child = t->right_child = NULL;
	return t;
}

// Добавить элемент в дерево
int pushElement(Node*& root, int key, char* info) {
	Node* temp, * prev = NULL;

	// Если дерево пустое, то создаём корень
	if (root == NULL) {
		root = getNewNode(key, info);
		return 0;
	}


	temp = root;
	while (temp != NULL) {
		prev = temp;

		if (key == temp->key) {
			cout << "Уже есть узел с таким ключом " << key << " ключ.\n";
			return -1;
		}
		else {
			if (key < temp->key) temp = temp->left_child;
			else temp = temp->right_child;
		}
	}

	temp = getNewNode(key, info);
	if (key < prev->key) prev->left_child = temp;
	else prev->right_child = temp;
	return 0;
}


// Функция для получения данных по ключу
Node* searchNode(Node* root, int data) {
	// Если пусто возвращаем NULL
	if (root == NULL) {
		return NULL;
	}
	// Если нашли нужный узел, возвращаем
	else if (root->key == data) {
		return root;
	}
	// Если заданный ключ меньше текущего, то ищем по левому узлу
	else if (data <= root->key) {
		return searchNode(root->left_child, data);
	}
	// Если больше, то по правому
	else {
		return searchNode(root->right_child, data);
	}
}

// Вывести дерево
void printTree(const string& prefix, const Node* node, bool isLeft) {
	if (node != nullptr) {
		cout << prefix;
		cout << (isLeft ? "|-- " : "\\-- ");
		cout << node->key << endl;

		// Рекурсивно вызываем для левого и правого узла
		printTree(prefix + (isLeft ? "|   " : "    "), node->left_child, true);
		printTree(prefix + (isLeft ? "|   " : "    "), node->right_child, false);
	}
}

// Функция для подсчёта высоты дерева
int heightBT(Node* node)
{
	if (node == NULL)
		return 0;

	// Рекурсивно вызываем и возвращаем высоту
	return 1 + max(heightBT(node->left_child), heightBT(node->right_child));
}

// Функция для проверки на сбалансированность
bool isBalanced(Node* root)
{
	int left_child_height;
	int right_child_height;

	// Если дерево пустое
	if (root == NULL)
		return 1;

	// Получаем длины левого и правого поддеревьев 
	left_child_height = heightBT(root->left_child);
	right_child_height = heightBT(root->right_child);

	// Сравниваем длину левого и правого поддерева и рекурсивно вызываем функцию
	if (abs(left_child_height - right_child_height) <= 1 && isBalanced(root->left_child) && isBalanced(root->right_child))
		return 1;

	// Если ни одна проверка не сработала, то дерево не сбалансировано 
	return 0;
}

// Функция для сохранения ключей дерева
int g_arr_pointer = 0;
void inorderStore(Node* root, Node** nodes) {
	if (root == NULL) return;
	// Рекурсивно вызываем, увелчиваем счётчик и добавляем в список
	inorderStore(root->left_child, nodes);
	nodes[g_arr_pointer++] = root;
	inorderStore(root->right_child, nodes);
}

// Функция для прямого обхода
void inorderOut(Node* root) {
	if (root == NULL) return;
	inorderOut(root->left_child);
	cout << root->key << " ";
	inorderOut(root->right_child);
}

// Функция для обратного обхода
void preorderOut(Node* root) {
	if (root == NULL) return;
	cout << root->key << " ";
	preorderOut(root->left_child);
	preorderOut(root->right_child);
}

// Функция для обратного обхода в убывающем порядке 
void postorderOut(Node* root) {
	if (root == NULL) return;
	postorderOut(root->left_child);
	postorderOut(root->right_child);
	cout << root->key << " ";
}

// Функция с основным функционалом балансировки
Node* buildBalancedTree(Node** nodes, int start, int end) {
	if (start > end) return NULL;

	// Вычисляем высоту до какой надо сбалансировать дерево
	int mid = (start + end) / 2;

	// Присваиваем корню новый узел
	Node* root = nodes[mid];

	// Рекурсивно вызываем для левого и правого дочерних узлов
	root->left_child = buildBalancedTree(nodes, start, mid - 1);
	root->right_child = buildBalancedTree(nodes, mid + 1, end);

	return root;
}

// Основная функция для балансировки дерева
Node* balanceTree(Node* root, int size) {
	Node** nodes = new Node * [size];
	Node* result;

	// Заполняем массив ключами узлов
	inorderStore(root, nodes);
	g_arr_pointer = 0;

	// Вызываем функцию, которая делает основную работу
	result = buildBalancedTree(nodes, 0, size - 1);

	// Очищаем массив
	delete[] nodes;
	return result;
}


// Функция для поиска минимума в дереве
Node* findMin(Node* root)
{
	if (root == NULL) return NULL;
	Node* temp = root;

	while (temp->left_child != NULL) {
		temp = temp->left_child;
	}
	return temp;
}

// Функция для удаления узла по ключу
Node* deleteNode(Node* root, int key) {
	if (root == NULL) return NULL;

	// По рекурсии вызываем если текущий ключ меньше того, который ищем, то идём влево, если больше, то вправо
	if (key < root->key) {
		root->left_child = deleteNode(root->left_child, key);
	}
	else if (key > root->key) {
		root->right_child = deleteNode(root->right_child, key);
	}
	else {
		// Если у узла нет детей, то просто удаляем
		if (root->left_child == NULL and root->right_child == NULL) {
			delete root;
			root = NULL;
		}

		// Если у удаляемого ключа только один дочерний
		else if (root->left_child == NULL) {
			Node* temp = root;
			root = root->right_child;
			delete temp;
		}
		else if (root->right_child == NULL) {
			Node* temp = root;
			root = root->left_child;
			delete temp;
		}

		// Если у удаляемого ключа два дочерних
		else {
			Node* temp = findMin(root->right_child);
			root->key = temp->key;
			strcpy_s(root->string_data, temp->string_data);
			root->right_child = deleteNode(root->right_child, temp->key);
		}
	}
	return root;
}


void IndividualTask(Node* node, int level, vector<int>& leaves) {
	if (node == NULL)
		return;

	if (node->left_child == NULL && node->right_child == NULL) {
		if (leaves.size() <= level)
			leaves.resize(level + 1);
		leaves[level]++;
	}

	IndividualTask(node->left_child, level + 1, leaves);
	IndividualTask(node->right_child, level + 1, leaves);
}

void printLeaves(const vector<int>& leaves) {
	for (int i = 0; i < leaves.size(); i++)
		cout << "Уровень " << i << ": " << leaves[i] << " листьев" << endl;
}


int main() {
	setlocale(LC_ALL, "RU");
	Node* root = NULL, * temp;
	int counter = 0, inp;
	int qDes;
	int key = 0;
	char dataInput[50];
	int num_levels;
	int* leaf_counter;
	vector<int> leaves;

	while (true) {
		cout << "1.Добавить узлы\n2.Сбалансировать дерево\n3.Вывести дерево\n"
			<< "4.Поиск по ключу\n5.Удалить по ключу\n6.Обход дерева\n"
			<< "7.Индивидуальное задание\n9.Выход\n";
		cin >> inp;
		while (inp < 0 && inp > 8) {
			cout << "\nНеверный ввод";
		}

		switch (inp) {
		// Добавить узлы в дерево
		case 1:
			cout << "\nСколько узлов добавить?\n>>";
			cin >> inp;
			for (int i = 0; i < inp; ++i) {
				cout << "\nЭлемент: " << i + 1 << ":";
				cout << "\nВведите данные для элемента\n>>";
				cin >> dataInput;
				cout << "\nВведите ID для элемента\n>>";
				cin >> key;
				while (pushElement(root, key, dataInput) == -1) {
					cout << "\nВведите ID для элемента\n>>";
					cin >> key;
				}
				counter++; // Увеличиваем счётчик
			}
			break;

		// Сбалансировать дерево
		case 2:
			cout << "\nИсходное дерево:\n";
			printTree("", root, false);

			// Если в дерево только корень или если оно пустое
			if (root == NULL || (root->left_child == NULL && root->right_child == NULL)) {
				cout << "\nВ дереве нечего балансировать\n";
			}
			else if (isBalanced(root)) {
				cout << "\nДерево уже сбалансировано\n";

			}
			else {
				root = balanceTree(root, counter);
				cout << "\nСбалансированное дерево\n";
				printTree("", root, false);
				cout << "\n\n";
			}
			break;

		// Вывести дерево
		case 3:

			if (root == NULL) {
				cout << "\nДерево пустое\n\n";
				break;
			}
			printTree("", root, false);
			cout << "\n\n";
			break;

		// Получить значение узла по ключу
		case 4:
			printTree("", root, false);
			cout << "\n\nВведите ключ узла:\n>>";
			cin >> inp;
			temp = searchNode(root, inp);

			if (temp == NULL) {
				cout << "\nДанные не найдены\n";
				break;
			}

			cout << "\n\nИнформация из узла " << inp << ": " << temp->string_data << "\n\n";
			break;

		// Удаление узла
		case 5:
			printTree("", root, false);
			cout << "\nВведите ключ узла для удаления\n>>";
			cin >> inp;

			if (!searchNode(root, inp)) {
				cout << "Нет узла с таким ключом " << inp << endl;
			}
			else {
				deleteNode(root, inp);
			}
			break;

		// Обход дерева
		case 6:
			cout << "\nВыберите тип обхода дерева:\n1.Прямой обход"
				<< "\n2.Обратный обход\n3.Обратный в порядке убывания\n";
			cin >> inp;

			if (inp == 1) {
				cout << "\nПрямой обход:\n";
				inorderOut(root);
			}
			else if (inp == 2) {
				cout << "\nОбратный обход:\n";
				preorderOut(root);
			}
			else if (inp == 3) {
				cout << "\nОбратный в порядке убывания:\n";
				postorderOut(root);
			}
			else {
				cout << "\nНеверный ввод.\n";
			}
			cout << "\n\n";
			break;

		// Индивидуальное задание (определить число листьев на каждом уровне)
		case 7:
			IndividualTask(root, 0, leaves);
			printLeaves(leaves);
			break;

		case 9: default:
			return 0;
		}

	}
	return 0;
}
