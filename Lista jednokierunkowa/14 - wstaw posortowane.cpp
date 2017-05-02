#include <iostream>
#include <random>
#include "listawskaznik.hpp"

using namespace std;

struct Lista
{
	Lista *next;
	int i;
};

random_device dice;

int main()
{
	Lista *head = NULL;
	Lista *tail = NULL;
	//ROSN¥CO
	for (int i = 0; i < 10; i++)
	{
		int wpisz = dice() % 100;
		cout << wpisz << endl;
		insertasc(tail, head, wpisz);
		wypisz(head);
	}
	cout << endl;

	Lista *head2 = NULL;
	Lista *tail2 = NULL;
	//MALEJ¥CO
	for (int i = 0; i < 10; i++)
	{
		int wpisz = dice() % 100;
		cout << wpisz << endl;
		insertdesc(tail2, head2, wpisz);
		wypisz(head2);
	}

	system("pause");
}