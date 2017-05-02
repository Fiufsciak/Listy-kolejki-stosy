// TODO: Program mo¿e przenieœæ kilka elementów, jeœli s¹ równe kluczowi
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
	Lista *head2 = NULL;
	Lista *tail2 = NULL; // lista, do której bêdziemy wstawiaæ usuniête klucze

	fill(tail, head, 100, 10);
	int klucz;

	int iteracje = dice() % 10; // 10, bo lista ma 10 elementów
	Lista *tmp = head;
	for (int i = 0; i < iteracje; i++) // losowo przydziel W£AŒCIWY klucz
	{
		tmp = tmp->next;
	}
	klucz = tmp->i;
	cout << "klucz to: " << klucz << endl;

	Lista *przenies = NULL; // poprzednik usuwanego elementu
	if (head == NULL)
	{
		cout << "Lista pusta!" << endl;
		system("pause");
		return -1;
	}

	// TODO: Program mo¿e przenieœæ kilka elementów, jeœli s¹ równe kluczowi
	if (klucz == head->i) // wyj¹tek: kluczem jest g³owa
	{
		move(tail, head, tail2, head2, przenies);
	}
	//Lista *prev = head;
	//for (Lista *sprawdz = head->next; sprawdz->next != NULL; sprawdz = sprawdz->next) // sprawdz zatrzyma siê na ogonie
	for (przenies = head; przenies->next != NULL; przenies = przenies->next)
	{
		//if (sprawdz->i == klucz)
		if (przenies->next->i == klucz)
		{
			move(head, tail, head2, tail2, przenies); // (..., prev);
			break;
			//sprawdz = prev; // po przeniesieniu sprawdz odnosi³by siê do drugej listy
			//continue; // bez zmiany prev
		}
		//prev = prev->next;
	}

	wypisz(head);
	wypisz(head2);
	system("pause");
}