// IMPLEMENTACJA TABLICOWA
/////////////////////////////
/*
Potrzebne:
1. Tablica danych (Stack): DEKLAROWANA W MAIN
2. Wskaünik wierzcho≥ka stosu (int top): DEKLAROWANA W MAIN, ZACZ•∆ OD -1
3. Rozmiar tablicy (const int rozmiar): DEKLAROWANA W MAIN
*/

#include <iostream>
#include "stostablica.hpp"

using std::cout;
using std::endl;

bool isFull(int top, const int rozmiar)
{
	if (top == rozmiar - 1)
	{
		return true;
	}

	else return false;
}

bool isEmpty(int top)
{
	if (top == -1)
	{
		return true;
	}

	else
	{
		cout << "Stos pusty!" << endl;
		return false;
	}
}

void push(int Stack[], int &top, const int rozmiar, int dodaj)
{
	if (isFull(top, rozmiar) == false)
	{
		Stack[top + 1] = dodaj;
		top++;
	}
}

int pop(int Stack[], int &top)
{
	if (isEmpty(top) != true)
	{
		top--;
		return Stack[top + 1];
	}

	return -1;
}

int showtop(int Stack[], int top)
{
	if (isEmpty(top) != false)
	{
		return Stack[top];
	}

	return -1;
}