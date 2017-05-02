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
	if (head->next == NULL)
	{
		return -1; // za ma�o element�w
	}

	Lista *tmp = head;
	int iteracje = dice() % 10; // 10, bo lista ma 10 element�w
	for (int i = 0; i < iteracje; i++) // losowo przydziel W�A�CIWY klucz
	{
		tmp = tmp->next;
	}
	klucz = tmp->i;
	cout << "klucz to: " << klucz << endl;

	Lista *pointer;
	if (klucz == head->next->i)
	{
		pointer = NULL;
	}
	else
	{
		for (pointer = head; (pointer->next->next != NULL) && (pointer->next->next->i != klucz); pointer = pointer->next); // podo�a li�cie dwuelementowej

		if (pointer == head)
		{
			return -2; // brak poprzednika, przerwij
		}
		if (pointer->next->next == NULL)
		{
			cout << "Z�y klucz!" << endl;
			system("pause");
			return -3; // brak klucza
		}
	}

	replaceprev(tail, head, pointer);
	//cout << showend(tail) << endl;
	wypisz(head);

	system("pause");
}