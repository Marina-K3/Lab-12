#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
/*Создать однонаправленный список для целых чисел в порядке возрастания.(Использовать пример 12.1)
Написать следующие функции для работы со списком:
- countList - подсчет числа элементов;
- findMax - поиск максимального элемента списка;
- findMin - поиск минимального элемента списка;
– Удалить все повторения числа
- Удалить все вхождения числа
*/
using namespace std;
typedef struct Node {
	int value;
	struct Node* next;
}node;
node* list = NULL;
void add(int v) {
	/*
	p-рабочий указатель(добавление элемента)
	cur-текущий
	prev-предыдущий
	*/
	node* p, * cur = list, * prev = NULL;
	p = (node*)malloc(sizeof(node));//новый узел
	p->value = v;
	p->next = NULL;
	//поиск места для вставки элемента в порядке возрастания (если не первый)
	while (cur != NULL && v > cur->value) {
		prev = cur;
		cur = cur->next;
	}
	//если первый элемент
	if (prev == NULL) {
		p->next = list;//связь со списком
		list = p;
	}//вставить в середину или в конец
	else {
		prev->next = p;
		p->next = cur;
	}
}
int count() {
	node* p = list;
	int count = 0;
	if (p == NULL)cout << "\n List is empty";
	else {
		while (p != NULL) {
			count++;
			p = p->next;
		}
	}
	return count;
}
int findMax() {
	int max = NULL;
	node* p = list;
	if (p == NULL)cout << "\n List is empty";
	else {
		max = p->value;
		while (p != NULL) {
			if (max < p->value) max = p->value;
			p = p->next;
		}
	}
	return max;
}
int findMin() {
	int min = NULL;
	node* p = list;
	if (p == NULL)cout << "\n List is empty";
	else {
		min = p->value;
		while (p != NULL) {
			if (min > p->value) min = p->value;
			p = p->next;
		}
	}
	return min;
}
void removeRep() {
	int k = count();
	for (int i = 0; i < k - 1; i++) {
		node* prev = list, * cur = list->next, * p;
		// если удаляемый элемент после первого в списке
		if (list->value == cur->value) {
			p = list;
			list = list->next;
			free(p);
			k--;
		}
		else {

			while (cur != NULL && cur->value != prev->value) {
				prev = cur;
				cur = cur->next;
			}
			if (cur != NULL && cur->value == prev->value) {
				p = cur;
				prev->next = cur->next;
				free(p);
				k--;
			}

		}
	}
}


void removeAll() {
	int flag = 0;
	int f = 0;
	int k = count();
	for (int i = 0; i < k; i++) {
		node* prev = list, * cur = list->next, * p, * dop = NULL;
		// если удаляемый элемент первый в списке
		if (cur->value == list->value) {
			p = list;
			list = list->next;
			cur = cur->next;
			free(p);
			flag = 1;
		}
		else {
			// находим удаляемые элементы

			while (cur != NULL && cur->value != prev->value) {
				dop = prev;
				prev = cur;
				cur = cur->next;
			}
			if (cur != NULL) {
				p = cur;
				prev->next = cur->next;
				free(p);
				p = prev;
				dop->next = prev->next;
				free(p);
			}
		}
	}
	node* prev = list, * cur = list->next, * p;
	if (flag == 1 && list != NULL) {
		p = list;
		list = list->next;
		cur = cur->next;
		free(p);
	}
}

void print() {
	node* p = list;
	if (p == NULL)cout << "\n List is empty";
	else {
		while (p != NULL) {
			cout << p->value << " ";
			p = p->next;
		}
	}
}
int main() {
	while (1) {
		cout << "    MENU\n 1 - add an element to the list\n"
			<< " 2 - count the number\n 3 - find max\n 4 - find min\n"
			<< " 5 - Remove all repetitions of a number\n 6 - Remove all occurrences of a number\n 7 - Print\n 8 - Stop\n";
		int choice;
		cin >> choice;

		switch (choice) {
		case 1:
			int c;
			cout << " How many numbers do you want to add?";
			cin >> c;
			for (int i = 0; i < c; i++) {
				int v;
				cout << " Enter the number - ";
				cin >> v;
				add(v);
			}
			break;
		case 2:
			int u;
			u = count();
			cout << " Number of nodes in the list - " << u << endl;
			break;
		case 3:
			int max;
			max = findMax();
			cout << " Max - " << max << endl;
			break;
		case 4:
			int min;
			min = findMin();
			cout << " Min - " << min << endl;
			break;
		case 5:
			removeRep();
			break;
		case 6:
			removeAll();
			break;
		case 7:
			print();
			cout << "\n";
			break;
		case 8:
			return 0;
			break;
		}
	}
}

