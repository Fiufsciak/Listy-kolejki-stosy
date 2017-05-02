//TODO: zamiana bez kolejno�ci?
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

	int max = head->i;
	int min = max;
	Lista *prevmax=NULL;
	Lista *prevmin=NULL;
	int lokacjamin = -1;
	int lokacjamax = -1;
	int i = 0;
	for (Lista *tmp = head; tmp->next != NULL; tmp = tmp->next, i++) // je�li istnieje kilka element�w minmax, zamie� te wyst�puj�ce w pierwszej kolejno�ci
	{
		int porownaj = tmp->next->i;
		if (porownaj > max)
		{
			max = porownaj;
			prevmax = tmp;
			lokacjamax = i;
		}
		else if (porownaj < min) // max nigdy nie b�dzie mniejsze od min, wi�c mo�na u�y� 'else if'
		{
			min = porownaj;
			prevmin = tmp;
			lokacjamin = i;
		}
	}

	if (lokacjamin < lokacjamax)
	{
		swap(tail, head, prevmin, prevmax);
	}
	else if (lokacjamax < lokacjamin)
	{
		swap(tail, head, prevmax, prevmin);
	}
	else
	{
		cout << "Minimum i maksimum sa na tej samej pozycji!" << endl;
		system("pause");
		return -1;
	}

	wypisz(head);
	cout << tail->i << endl;

	system("pause");
}