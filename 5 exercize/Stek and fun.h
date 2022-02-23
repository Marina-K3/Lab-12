

#pragma once
#include <iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
typedef struct Stek1 {
	char first;
	struct Stek1* next;
}st1;
Stek1* head1 = NULL;//указатель на начало стека1


typedef struct Stek2 {
	char second;
	struct Stek2* next;
}st2;
Stek2* head2 = NULL;//указатель на начало стека2


void Push2 (char);

extern void Push(char c) {
	Stek1* p = new Stek1;
	if (head1 == NULL) {
		p->first = c;
		p->next = head1;
		head1 = p;
	}
	else {
		if (c != head1->first) {
			p->first = c;
			p->next = head1;
			head1 = p;
		}
		else Push2(c);
	}
}

void Push2(char c) {
	Stek2* p = new Stek2;
	p->second = c;
	p->next = head2;
	head2 = p;
}

extern void Print() {
	Stek1* p = head1;
	if (p == NULL) cout<<" Стек 1 пустой";
	else printf(" Стек 1: \n");
	while (p != NULL) {
		cout << p->first << " " << endl;
		p = p->next;
	}
	Stek2* p1 = head2;
	if (p1 == NULL) cout << " Стек 2 пустой";
	else cout<<" Стек 2: \n";
	while (p1 != NULL) {
		cout << p1->second << " " << endl;
		p1 = p1->next;
	}
}