#include <iostream>
#include "listawskaznik.hpp"

using namespace std;

struct Lista
{
	Lista *next;
	int i;
};

int main()
{
	Lista *head = NULL;
	Lista *tail = NULL;

	fill(tail, head, 100, 10);
	int n = 4; // co który element usuwaæ?

	Lista *start = head->next; // nie mo¿na zacz¹æ od head, trzeba by usun¹æ ka¿dy element (inna funkcja)
	Lista *prev = head; // potrzebne do "sklejenia" listy po usuniêciu
	int i = 1;
	while (start)
	{
		i++;
		for ( ; (i < n) && (start->next != NULL); i++, start = start->next)
		{
			//cout << "raz" << endl;
			prev = prev->next;
		}

		if (i != n) // przedwczesne wyjœcie z pêtli, start = tail (zapobiega przypadkowemu usuniêciu ostatniego elementu)
		{
			break;
		}
		remove(tail, head, prev);
		start = prev->next;
		i = 0;
	}

	wypisz(head);
	//cout << showend(tail);
	system("pause");
}