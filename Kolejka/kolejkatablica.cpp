// IMPLEMENTACJA TABLICOWA
////////////////////////////////
/*
Potrzebne:
soon
*/
#include <iostream>
#include "kolejkatablica.hpp"

using namespace std;

bool isEmpty(int rozmiar)
{
	if (rozmiar == 0)
	{
		return true;
	}
	else return false;
}

bool isFull(int size, int rozmiar)
{
	if (rozmiar == size)
	{
		return true;
	}
	else return false;
}

void enqueue(int &head, int &tail, int tab[], int size, int &rozmiar, int dodaj) // dodaj na koniec
{
	if (isEmpty(rozmiar))
	{
		head++;
		tail++;
		rozmiar++;
		tab[head] = dodaj;
		return;
	}
	else if (isFull(size, rozmiar))
	{
		cout << "!Kolejka pelna!" << endl;
		return;
	}
	if (tail + 1 > size - 1) // ogon jest na koñcu tablicy
	{
		tail = 0;
		tab[tail] = dodaj;
		rozmiar++;
		return;
	}

	tail++;
	rozmiar++;
	tab[tail] = dodaj;
}

int dequeue(int &head, int &tail, int tab[], int size, int &rozmiar) // usun element z poczatku kolejki
{
	if (isEmpty(rozmiar))
	{
		cout << "!Kolejka pusta!" << endl;
		return -1;
	}
	else if (head == tail) // ostatni element
	{
		int answer = tab[head];
		head = -1;
		tail = -1;
		return answer;
	}
	if (head + 1 > size - 1) // g³owa na koñcu tablicy
	{
		int answer = tab[head];
		rozmiar--;
		head = 0;
		return answer;
	}

	int answer = tab[head];
	head++;
	rozmiar--;
	return answer;
}

int front(int head, int tab[]) // wyswietl element na poczatku kolejki
{
	return tab[head];
}