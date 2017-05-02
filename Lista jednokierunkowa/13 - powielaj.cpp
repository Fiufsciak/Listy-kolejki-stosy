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
	fill(tail, head, 5, 10);

	Lista *start;
	for (start = head; start != NULL; start = start->next)
	{
		int iteracje = start->i;
		Lista *poprzednik = start;
		Lista *tmp = poprzednik;
		Lista *nastepnik = start->next;
		for (int i = 1; i < iteracje; i++)
		{
			/*poprzednik->next = new Lista;
			poprzednik = poprzednik->next;
			*poprzednik = *tmp;*/
			copy(poprzednik);
		}
		//poprzednik->next = nastepnik;
		start = poprzednik;
	}

	wypisz(head);
	system("pause");
}