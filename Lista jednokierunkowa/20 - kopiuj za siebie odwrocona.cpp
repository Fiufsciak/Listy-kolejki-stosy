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
	
	copylistr(tail, head);
	wypisz(head);
	cout << tail->i;

	system("pause");
}