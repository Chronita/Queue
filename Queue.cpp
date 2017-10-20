//Queue

#include "stdafx.h" // include-файл
#include <stdlib.h> //подключение стандартной библиотеки
#include <stdio.h> //  для ввода-вывода
#include <conio.h> // для работы с консолью
#include <iostream> // заголовочный файл с классами, функциями и переменными для организации ввода-вывода 
using namespace std;
void error();


struct node {
	int d;// элемент
	node *p;
};

node *first(int d)
{
	node *pv = new node;
	pv->d = d;
	pv->p = NULL;
	return pv;
}

int add(node **pend, int d)
{
	int temp = (*pend)->d;
	node *pv = new node;
	pv->d = d;
	pv->p = NULL;
	(*pend)->p = pv;
		*pend = pv;
	return temp;
}

int del(node **pbeg)
{
	int temp = (*pbeg)->d;
	node *pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}


int main()
{   int n,k;
	cout << "How many items will it be in the queue?   -> ";
	cin >> n;
	cout << endl;
	cout << "Input the 1-st item -> ";
	cin >> k;
	cout << endl;
	node *pbeg = first(k);
	node *pend = pbeg;
	cout << "Input data: ";
	cout << k;
	for (int i = 1; i < n; i++)    cout<<add(&pend, rand() % 9 + 1);
	cout << endl;
	cout << endl;
	cout << "Output data:  ";
	cout << k;
	for (int i = 1; i < n;i++)
		cout <<del(&pbeg) ;
	_getch();
	return 0;

}

