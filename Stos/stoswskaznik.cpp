// IMPLEMENTACJA WSKAèNIKOWA (ZALECANA)
/////////////////////////////////////////
/*
Potrzebne:
1. Stos (Stack) zawierajπcy zmiennπ (i) i wskaünik do nastÍpnego wÍz≥a (next)
2. Wskaünik wierzcho≥ka stosu (top): DEKLAROWANY W FUNKCJI MAIN (lub inicjalizatorze) JAKO NULL NA POCZ•TKU
*/

#include <iostream>
#include "stoswskaznik.hpp"

using std::cout;
using std::endl;

struct Stack
{
	Stack *next;
	int i;
};

bool isEmpty(Stack *top)
{
	if(top == NULL)
	{
		cout << "Stos pusty!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void push(Stack *&top, int dodaj)
{
	if(isEmpty(top))
	{
		top = new Stack;
		top->i = dodaj;
		top->next = NULL;
		return;
	}

	Stack *tmp = new Stack;
	tmp->i = dodaj;
	tmp->next = top;
	top = tmp;
}

int pop(Stack *&top)
{
	if(isEmpty(top))
	{
		return -1;
	}

	int answer = top->i;
	Stack *tmp = top;
	top = top->next;
	delete tmp;
	return answer;
}

int showtop(Stack *top)
{
	if(isEmpty(top))
	{
		return -1;
	}

	return top->i;
}

//do testow
/*int main()
{
	Stack *top=NULL;
	showtop(top);
	push(top,2);
	push(top,3);
	cout << showtop(top) << endl;
	cout << endl << endl << isEmpty(top) << endl;
	cout << pop(top) << endl;
	cout << pop(top) << endl;
	cout << pop(top) << endl;
	cout << pop(top) << endl;

	system("pause");
}*/