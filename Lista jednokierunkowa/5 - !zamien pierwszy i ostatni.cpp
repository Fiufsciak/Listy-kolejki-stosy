//TODO: Operacje tylko na strukturach
#include <iostream>
#include "listawskaznik.hpp"

using namespace std;


int main()
{
	Lista *head = NULL;
	Lista *tail = NULL;

	fill(tail, head, 100, 10);
	int pierwszy = removefront(head);
	int ostatni = removeend(tail, head);
	if (pierwszy == -1 || ostatni == -1)
	{
		return -1; // niepowodzenie, lista ma mniej ni¿ dwa elementy
	}
	addfront(tail, head, ostatni);
	addend(tail, head, pierwszy);
	wypisz(head);

	system("pause");
}