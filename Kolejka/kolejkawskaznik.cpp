// IMPLEMENTACJA WSKAèNIKOWA
////////////////////////////////
/*
Potrzebne:
1. Struktura danych (Kolejka) zawierajπca wskaünik do nastÍpnego elementu (next) i wartoúÊ typu int (i)
2. Wskaünik na poczπtek kolejki (head) - DEKLAROWANY W MAIN JAKO NULL
3. Wskaünik na koniec kolejki (tail) - DEKLAROWANY W MAIN JAKO NULL
*/
#include <iostream>
#include "kolejkawskaznik.hpp"

using namespace std;

class Test
{
public:
	struct Struktura
	{
		Struktura *nastepny;
		int liczba = -1;
	};
	Struktura *head = NULL;
	int testuj(int n)
	{
		head = new Struktura;
		head->liczba = n;
		head->nastepny = NULL;
		return n;
	}
};

struct Kolejka
{
	Kolejka *next;
	int i = 0;
};

bool isEmpty(Kolejka *head)
{
	if (head == NULL)
	{
		return true;
	}
	else return false;
}

void enqueue(Kolejka *&tail, Kolejka *&head, int wpisz) // dodaj na koniec
{
	if (isEmpty(head))
	{
		tail = new Kolejka;
		tail->i = wpisz;
		tail->next = NULL;
		head = tail;
		return;
	}
	tail->next = new Kolejka; // polacz z nastepnym
	tail = tail->next; // zmien wsk na ostatni element
	tail->next = NULL; // ostatni nie jest polaczony
	tail->i = wpisz;
}

int dequeue(Kolejka *&tail, Kolejka *&head) // usun element z poczatku kolejki
{
	if (isEmpty(head))
	{
		cout << "!Kolejka pusta!";
		return -1;
	}
	Kolejka *tmp = head;
	int answer = head->i;
	head = head->next;
	//delete tmp;
	return answer;
}

int front(Kolejka *head) // wyswietl element na poczatku kolejki
{
	if (isEmpty(head))
	{
		cout << "!Kolejka pusta!";
		return -1;
	}
	cout << head->i;
}

//do testÛw
/*main()
{
Kolejka kolejka;
Kolejka *head=NULL;
Koelejka *tail=NULL;

front(head);
enqueue(tail, head, 2);
enqueue(tail, head, 3);
enqueue(tail, head, 4);
cout << endl << endl << dequeue(tail, head) << endl;
cout << dequeue(tail, head) << endl;
cout << dequeue(tail, head) << endl;
cout << dequeue(tail, head) << endl;

}*/
