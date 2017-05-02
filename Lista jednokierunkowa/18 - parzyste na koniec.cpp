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

	bool zmiana = true;
	Lista *parzysta;
	Lista *oldtail = tail;
	while (head != NULL && zmiana)
	{
		zmiana = false;
		if ( (head->i) % 2 == 0)
		{
			parzysta = head;
			head = head->next;
			tail->next = parzysta;
			tail = parzysta;
			tail->next = NULL;

			zmiana = true;
		}
	}

	if (head != NULL && head->next != NULL)
	{
		Lista *prev = head;
		for (Lista *tmp = head->next; tmp != oldtail; tmp = tmp->next) // jeœli ogon jest parzysty - nie przenoœ
		{
			if ( (tmp->i) % 2 == 0)
			{
				parzysta = tmp;
				prev->next = parzysta->next;
				tail->next = parzysta;
				tail = parzysta;
				tail->next = NULL;
				tmp = prev; // po przesuniêciu zmienia siê nastêpnik prev, wiêc trzeba go sprawdziæ jeszcze raz 
				continue;
			}
			prev = prev->next; // przesuñ siê do przodu razem z tmp
		}
	}

	wypisz(head);
	cout << oldtail->i << " " << tail->i;
	system("pause");
}