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
		int przenies = remove(tail, head, tmp); // usu� z ko�ca...
		addfront(tail, head, przenies); // ...i przenie� na pocz�tek
	}

	wypisz(head);

	system("pause");
}