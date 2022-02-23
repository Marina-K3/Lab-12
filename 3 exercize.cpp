//1.	����������� ������� �� ������  ��������� �� ������������ ������ 11(��� 8).
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
		cout << "-----*���������� �������*------\n"
			<< "  1- ��������\n  2- �������\n  3- ������� �������\n  0- �����\n";
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
	p = (Queue*)malloc(sizeof(Queue)); /* ������� �������*/
	long int num;
	cout << " *����� �����* - ";
	cin >> num;
	p->number = num;
	getchar();
	cout << " *����� ����������* - ";
	fgets(p->dest, 25, stdin);
	cout << " *����� ������* - ";
	fgets(p->time, 10, stdin);
	cout << " *���� ������* - ";
	fgets(p->date, 12, stdin);
	float pr;
	cout << " *����* - ";
	cin >> pr;
	p->price = pr;
	p->next = NULL; /* ���������� ������� ����� �������*/
	if (head == NULL) /* ���� ������� �����... */
		head = p; /* head ��������� �� ��������� �������*/
	else tail->next = p; /* ��������� ����� ��. � ����� �������*/
	tail = p; 
}
void print() {
	Queue* p = head;
	if (p == NULL)
		printf("������� �����");
	else
		printf("  �������: ");
	int count = 1;
	while (p != NULL)
	{
		cout << "\n  ***\n ���� � " << count << endl;
		cout << "\n *����� �����* - " << p->number << endl;
		cout << " *����� ����������* - " << p->dest;
		cout << " *����� ������* - " << p->time;
		cout << " *���� ������* - " << p->date;
		cout << " *����* - " << p->price << endl;
		p = p->next;
		count++;
	}
}
void del() {
	Queue* p = head; /* p ��������� �� ������ �������*/
	if (head != NULL)
	{ /* ���� ������� �� �����... */
		head = head->next; /* head ��������� �� ��������� ��. */
		if (head == NULL) /* ���� ������� ��������1 �������*/
			tail = NULL; /* tail ����� ����*/
		free(p); /* ������� �������*/
	}

}