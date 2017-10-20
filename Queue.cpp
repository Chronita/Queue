//Queue

#include "stdafx.h" // include-����
#include <stdlib.h> //����������� ����������� ����������
#include <stdio.h> //  ��� �����-������
#include <conio.h> // ��� ������ � ��������
#include <iostream> // ������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������ 
using namespace std;
void error();


struct node {
	int d;// �������
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

