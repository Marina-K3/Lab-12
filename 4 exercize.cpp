#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;
//1.	Реализовать стек на основе  структуры из лабораторной работы 11(или 8).
typedef struct Air {
	long int number;
	char dest[25];
	char time[10];
	char date[12];
	float price; /* данные для запоминания в стеке*/
	struct Air* next; /* указатель на следующий элемент*/
} air;
void Push(void);
void Pop(void);
void Display(void);
Air* top = NULL; /* указатель на стек*/
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		int choice;
		cout << "-----*Реализация стека*------\n"
			<< "  1- Добавить\n  2- Удалить\n  3- Вывести стек\n  0- Выйти\n";
		cin >> choice;
		switch (choice)
		{
		case 0: return 0;
			break;
		case 1:  Push();
			break;
		case 2: Pop();
			break;
		case 3: Display();
			break;
		default:
			break;
		}
	}
}

void Push(void) {/* Добавление элемента в стек*/
	Air* p;
	p = (Air*)malloc(sizeof(Air));
	long int num;
	cout << " *Номер рейса* - ";
	cin >> num;
	p->number = num;
	getchar();
	cout << " *Пункт назначения* - ";
	fgets(p->dest, 25, stdin);
	cout << " *Время вылета* - ";
	fgets(p->time, 10, stdin);
	cout << " *Дата вылета* - ";
	fgets(p->date, 12, stdin);
	float pr;
	cout << " *Цена* - ";
	cin >> pr;
	p->price = pr;
	p->next = top;
	top = p;
}

void Pop(void) {/* Удаление элемента из стека*/
	Air* p;
	if (top != NULL) {
		p = top;
		top = top->next;
		free(p);
	}
}

void Display(void) {/* Отобразить содержимое стека*/
	Air* p = top;
	int count = 1;
	if (p == NULL) printf(" Стек пустой");
	else printf(" Стек: ");
	while (p != NULL) {
		cout << "\n  ***\n Рейс № " << count << endl;
		cout << "\n *Номер рейса* - " << p->number << endl;
		cout << " *Пункт назначения* - " << p->dest;
		cout << " *Время вылета* - " << p->time;
		cout << " *Дата вылета* - " << p->date;
		cout << " *Цена* - " << p->price << endl;
		p = p->next;
		count++;
	}
}

