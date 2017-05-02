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

int main()
{
	Test klasa;
	klasa.testuj(1);
	cout << klasa.head->liczba;
	system("pause");
	/*Kolejka *head = NULL;
	Kolejka *tail = NULL;

	//front(head);
	enqueue(tail, head, 2);
	enqueue(tail, head, 3);
	enqueue(tail, head, 4);
	cout << endl << endl << dequeue(tail, head) << endl;
	cout << dequeue(tail, head) << endl;
	cout << dequeue(tail, head) << endl;
	//cout << dequeue(tail, head) << endl;

	system("pause");*/
}