//1.	Реализовать очередь на основе  структуры из лабораторной работы 11(или 8).
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
 struct Queue {

	struct Queue* next;

	long int number;
	char dest[25];
	char time[10];
	char date[12];
	float price;

}queue;
Queue* head = NULL, * tail = NULL;
void Add();
void del();
void print();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		int choice;
		cout << "-----*Реализация очереди*------\n"
			<< "  1- Добавить\n  2- Удалить\n  3- Вывести очередь\n  0- Выйти\n";
		cin >> choice;
		switch (choice)
		{
		case 0: return 0;
			break;
		case 1:  Add();
			break;
		case 2: del();
			break;
		case 3: print();
			break;
		default:
			break;
		}
	}
}
void Add() {
	Queue* p;
	p = (Queue*)malloc(sizeof(Queue)); /* создать элемент*/
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
	p->next = NULL; /* установить признак конца очереди*/
	if (head == NULL) /* если очередь пуста... */
		head = p; /* head указывает на созданный элемент*/
	else tail->next = p; /* поставить новый эл. в конец очереди*/
	tail = p; 
}
void print() {
	Queue* p = head;
	if (p == NULL)
		printf("Очередь пуста");
	else
		printf("  Очередь: ");
	int count = 1;
	while (p != NULL)
	{
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
void del() {
	Queue* p = head; /* p указывает на голову очереди*/
	if (head != NULL)
	{ /* если очередь не пуста... */
		head = head->next; /* head указывает на следующий эл. */
		if (head == NULL) /* если очередь содержит1 элемент*/
			tail = NULL; /* tail равен нулю*/
		free(p); /* удалить элемент*/
	}

}