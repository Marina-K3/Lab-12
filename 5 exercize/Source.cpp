//13.	������� ��� ����� ��� ��������.������������ ������ 
//������ �������� � ������.������� ������� 
//��� ����� � ������ ��������� �����.������� ������� � 
//������ � ������ ����.� ������ ���������� 
//��������� ������� � �������� ����� ������� �� ������ ����
#include<iostream>
#include<windows.h>
#include"Stek and fun.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		cout << " 1 - �������� � ����\n 2 - ����������� �����\n 0 - ����� �� ��������� " << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: int size;
			cout << " ������� ������ ����� - ";
			cin >> size;
			cout << " ������� ��������: \n";
			for (int i = 0; i < size; i++) {
				char c;
				cin >> c;
				Push(c);
			}
			break;
		case 2: Print();
			break;
		case 0: return 0;
			break;
		default: cout << "Error";
			break;
		}
	}
}