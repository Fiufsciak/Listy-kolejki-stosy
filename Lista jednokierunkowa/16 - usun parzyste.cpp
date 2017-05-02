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
	while (head != NULL && usuniety) // sprawdŸ przypadki, gdzie wystêpuje kilka parzystych kluczy, poczynaj¹c od g³owy
	{
		usuniety = false;
		if ( (head->i) % 2 == 0)
		{
			remove(tail, head, NULL);
			usuniety = true;
		}
	}

	if (head != NULL) // po pêtli wy¿ej head MUSI byæ nieparzysty lub nie istnieæ
	{
		usuniety = true;
		while ( (head->next) != NULL && usuniety) // sprawdzanie wszystkich przypadków, dla których niemo¿liwe jest wykonanie pêtli for
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
		return 1; // ca³a lista zosta³a usuniêta, zejœcie ni¿ej skutowa³oby wyj¹tkiem
	}

	if (head->next != NULL) // aby unikn¹æ wyj¹tku w warunku pêtli
	{
		Lista *prev = head;
		for (Lista *tmp = head->next; tmp->next != NULL; tmp = tmp->next) // usunie te¿ ogon
		{
			if ((tmp->next->i) % 2 == 0)
			{
				remove(tail, head, tmp);
				tmp = prev;
				continue; // po usuniêciu nie zmieniamy prev i sprawdzamy jeszcze raz nastêpnik tmp
			}
			prev = prev->next;
		}
	}

	wypisz(head);
	cout << tail->i << endl;

	system("pause");
}