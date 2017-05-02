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

	bool usuniety = true;
	while (head != NULL && usuniety) // sprawd� przypadki, gdzie wyst�puje kilka parzystych kluczy, poczynaj�c od g�owy
	{
		usuniety = false;
		if ( (head->i) % 2 == 0)
		{
			remove(tail, head, NULL);
			usuniety = true;
		}
	}

	if (head != NULL) // po p�tli wy�ej head MUSI by� nieparzysty lub nie istnie�
	{
		usuniety = true;
		while ( (head->next) != NULL && usuniety) // sprawdzanie wszystkich przypadk�w, dla kt�rych niemo�liwe jest wykonanie p�tli for
		{
			usuniety = false;
			if ((head->next->i) % 2 == 0)
			{
				remove(tail, head, head);
				usuniety = true;
			}
		}
	}
	else
	{
		wypisz(head);
		cout << tail->i << endl;

		system("pause");
		return 1; // ca�a lista zosta�a usuni�ta, zej�cie ni�ej skutowa�oby wyj�tkiem
	}

	if (head->next != NULL) // aby unikn�� wyj�tku w warunku p�tli
	{
		Lista *prev = head;
		for (Lista *tmp = head->next; tmp->next != NULL; tmp = tmp->next) // usunie te� ogon
		{
			if ((tmp->next->i) % 2 == 0)
			{
				remove(tail, head, tmp);
				tmp = prev;
				continue; // po usuni�ciu nie zmieniamy prev i sprawdzamy jeszcze raz nast�pnik tmp
			}
			prev = prev->next;
		}
	}

	wypisz(head);
	cout << tail->i << endl;

	system("pause");
}