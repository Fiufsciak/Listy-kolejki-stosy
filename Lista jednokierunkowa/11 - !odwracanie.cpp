//TODO: Operacje na samych strukturach
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
	fill(tail, head, 100, 2);
	
	Lista *tmp = head; // "niezmienny head"
	while (tmp->next != NULL)
	{
		int przenies = remove(tail, head, tmp); // usuñ z koñca...
		addfront(tail, head, przenies); // ...i przenieœ na pocz¹tek
	}

	wypisz(head);

	system("pause");
}