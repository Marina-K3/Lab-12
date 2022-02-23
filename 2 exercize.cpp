#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <iostream>
//Реализовать список на основе  структуры из лабораторной работы 11(или 8).
//- функции добавления элемента(в алфавитном порядке)
//- функция удаления элемента
//- вывод всего списка на экран
//- выход из программы
using namespace std;
typedef struct Node {

	struct Node* next;

	int number;
	char dest[25];
	char time[10];
	char date[12];
	float price;

}node;

int menu();
int input();
int del(int d);
int outpout();
node* list = NULL;
int main() {
	while (1) {
		switch (menu()) {
		case 1:
			input();
			break;
		case 2:
			long int d; // d - deleted number
			cout << " Enter the number of the flight to be deleted -  ";
			cin >> d;
			del(d);
			break;
		case 3: outpout();
			break;
		case 4:
			return 0;
			break;
		}
	}

}

int menu() {
	int choice;
	printf("\n   Menu\n");
	printf(" 1 - Structure inpute\n 2 - Delete\n 3 - Outpout\n 4 - Stop\n ");
	scanf_s("%d", &choice);
	return choice;
}
int input() {
	node* p, * cur = list, * prev = NULL;
	p = (node*)malloc(sizeof(node));
	long int num;
	cout << "     ****\n   Enter the data of the flight:\n Number - ";
	cin >> num;
	p->number = num;
	getchar();
	cout << " Destination - ";
	fgets(p->dest, 25, stdin);
	cout << " Departure time - ";
	fgets(p->time, 10, stdin);
	cout << " Date of flight - ";
	fgets(p->date, 12, stdin);
	float pr;
	cout << " Price - ";
	cin >> pr;
	p->price = pr;
	//если уже сформирован список
	while (cur != NULL && pr > cur->price) {
		prev = cur;
		cur = cur->next;
	}
	//если не сформирован список
	if (prev == NULL) {
		p->next = list;
		list = p;
	}
	//вставить в середину списка или в конец
	else {
		prev->next = p;
		p->next = cur;
	}
	return 0;
}

int del(int d) {
	node* prev = list, * cur = list->next, * p;
	// если удаляемый элемент первый
	if (d == list->number) {
		p = list;
		list = list->next;
		free(p);
	}
	else {
		// если не первый находим циклом
		while (cur != NULL && cur->number != d) {
			prev = cur;
			cur = cur->next;

		}
		if (cur != NULL) {
			p = cur;
			prev->next = cur->next;
			free(p);
		}
	}
	return 0;
}
int outpout() {
	node* p = list;
	int count = 1;
	if (p == NULL)cout << " the list is empty";
	else {
		while (p != NULL) {
			cout << "\n  ***\n List number " << count << endl;
			cout << "\n Number - " << p->number << endl;
			cout << " Destination - " << p->dest;
			cout << " Departure time - " << p->time;
			cout << " Date of flight - " << p->date;
			cout << " Price - " << p->price << endl;
			count++;
			p = p->next;
		}
	}
	return 0;
}
