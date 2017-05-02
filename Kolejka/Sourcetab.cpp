#include <iostream>
#include "kolejkatablica.hpp"
using namespace std;

int main()
{
	int tablica[5];
	int size = 5;
	int rozmiar = 0;
	int head = -1;
	int tail = -1;

	dequeue(head, tail, tablica, size, rozmiar);
	enqueue(head, tail, tablica, size, rozmiar, 1);
	enqueue(head, tail, tablica, size, rozmiar, 2);
	enqueue(head, tail, tablica, size, rozmiar, 3);
	enqueue(head, tail, tablica, size, rozmiar, 4);
	enqueue(head, tail, tablica, size, rozmiar, 5);
	enqueue(head, tail, tablica, size, rozmiar, 6);
	cout << dequeue(head, tail, tablica, size, rozmiar) << endl;
	cout << dequeue(head, tail, tablica, size, rozmiar) << endl;
	cout << dequeue(head, tail, tablica, size, rozmiar) << endl;
	cout << dequeue(head, tail, tablica, size, rozmiar) << endl; // head = tail = size
	enqueue(head, tail, tablica, size, rozmiar, 6);
	//cout << dequeue(head, tail, tablica, size, rozmiar) << endl; // head = tail = -1
	cout << head << tail;


	/*for (int i = 0; i < size; i++)
	{
		cout << tablica[i] << endl;
	}*/

	system("pause");
}