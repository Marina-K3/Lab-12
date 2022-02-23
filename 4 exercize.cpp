#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;
//1.	����������� ���� �� ������  ��������� �� ������������ ������ 11(��� 8).
typedef struct Air {
	long int number;
	char dest[25];
	char time[10];
	char date[12];
	float price; /* ������ ��� ����������� � �����*/
	struct Air* next; /* ��������� �� ��������� �������*/
} air;
void Push(void);
void Pop(void);
void Display(void);
Air* top = NULL; /* ��������� �� ����*/
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		int choice;
		cout << "-----*���������� �����*------\n"
			<< "  1- ��������\n  2- �������\n  3- ������� ����\n  0- �����\n";
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

void Push(void) {/* ���������� �������� � ����*/
	Air* p;
	p = (Air*)malloc(sizeof(Air));
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
	p->next = top;
	top = p;
}

void Pop(void) {/* �������� �������� �� �����*/
	Air* p;
	if (top != NULL) {
		p = top;
		top = top->next;
		free(p);
	}
}

void Display(void) {/* ���������� ���������� �����*/
	Air* p = top;
	int count = 1;
	if (p == NULL) printf(" ���� ������");
	else printf(" ����: ");
	while (p != NULL) {
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

