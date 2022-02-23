//13.	Создать два стека для символов.Максимальный размер 
//стеков вводится с экрана.Создать функции 
//для ввода и вывода элементов стека.Вводить символы с 
//экрана в первый стек.В случае совпадения 
//вводимого символа с вершиной стека вводить во второй стек
#include<iostream>
#include<windows.h>
#include"Stek and fun.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1) {
		cout << " 1 - Записать в стек\n 2 - Распечатать стеки\n 0 - Выход из программы " << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: int size;
			cout << " Введите размер стека - ";
			cin >> size;
			cout << " Введите элементы: \n";
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