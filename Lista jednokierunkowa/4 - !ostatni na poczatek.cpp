//TODO: Operacje tylko na strukturach
#include <iostream>
#include "listawskaznik.hpp"

using namespace std;

int main()
{
	Lista *head = NULL;
	Lista *tail = NULL;

	fill(tail, head, 100, 10);

	int przenies = removeend(tail, head);
	if (przenies == -1)
	{
		return -1; // niepowodzenie, pusta lista
	}
	addfront(tail, head, przenies);

	wypisz(head);
	system("pause");
}