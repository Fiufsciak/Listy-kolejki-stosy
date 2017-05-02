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

	fill(tail, head, 100, 10);
	int n = 4; // ile za podanym kluczem kasowaæ
	int klucz;

	int iteracje = dice() % 10; // 10, bo lista ma 10 elementów
	Lista *tmp = head;
	for (int i = 0; i < iteracje; i++) // losowo przydziel W£AŒCIWY klucz
	{
		tmp = tmp->next;
	}
	klucz = tmp->i;
	cout << "klucz to: " << klucz << endl;

	Lista *usun = head;
	for (; (usun->next != NULL && usun->i != klucz); usun = usun->next);

	if (usun == tail)
	{
		cout << "Nie mozna nic usunac!" << endl;
		system("pause");
		return -1; // nie mo¿na nic usun¹æ za ogonem
	}

	for (int i = 0; (i < n) && (usun->next != NULL); i++)
	{
		remove(tail, head, usun);
	}

	wypisz(head);

	system("pause");
}