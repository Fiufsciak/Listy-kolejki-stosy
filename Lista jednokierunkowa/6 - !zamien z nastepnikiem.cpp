//TODO: Operacje dla kilku element�w r�wnych kluczowi (6 i 7)
#include <iostream>
#include <random>
#include "listawskaznik.hpp"

using namespace std;

struct Lista
{
Lista *next;
int i;
};

random_device dice;

int main()
{
	Lista *head = NULL;
	Lista *tail = NULL;

	int klucz;
	fill(tail, head, 100, 10);

	Lista *tmp = head;
	int iteracje = dice() % 10; // 10, bo lista ma 10 element�w
	for (int i = 0; i < iteracje; i++) // losowo przydziel W�A�CIWY klucz
	{
		tmp = tmp->next;
	}
	klucz = tmp->i;
	cout << "klucz to: " << klucz << endl;

	//system("pause");
	Lista *pointer;
	if (klucz == head->i)
	{
		pointer = NULL;
	}
	else
	{
		for (pointer = head; (pointer->next != NULL) && (pointer->next->i != klucz); pointer = pointer->next); // podo�a li�cie dwuelementowej

		if (pointer->next == NULL)
		{
			cout << "Z�y klucz!" << endl;
			system("pause");
			return -3; // brak klucza
		}
	}

	replacenext(tail, head, pointer);
	//cout << endl << showend(tail) << endl;
	wypisz(head);

	system("pause");
}