#include <iostream>
#include <chrono>
#include <ctime>
#include "listawskaznik.hpp"

using namespace std;

struct Lista
{
	Lista *next;
	int i;
};

//wady?: jeden pusty przebieg na koñcu (potrzebny?)
void bubblesortasc2(Lista *&tail, Lista *&head)
{
	bool swapped = true;
	Lista *koniec = NULL;
	if (head == NULL || head->next == NULL)
	{
		cout << "Nie ma nic do posortowania!" << endl;
		return;
	}

	if (head->next == tail) // lista dwuelementowa
	{
		if (head->i > head->next->i) // lista malej¹ca
		{
			replacenext(tail, head, NULL); // uwzglêdnia zmianê ogona
			return;
		}
	}

	Lista *tmpkoniec = NULL;
	Lista *tmp = NULL;
	while (swapped) // drugi argument: pêtla for ju¿ siê nigdy nie wykona, lista posortowana
	{
		swapped = false;
		tmp = NULL;
		cout << "while ";
		if (head->i > head->next->i) // pierwsze porównanie, wymaga szczególnej uwagi z powodu funkcji replacenext()
		{
			cout << "head ";
			replacenext(tail, head, tmp);
			//tmpkoniec = head->next->next;
			swapped = true;
		}
		for (Lista *tmp = head; tmp->next->next != koniec; tmp = tmp->next)
		{
			cout << "for ";
			if (tmp->next->i > tmp->next->next->i)
			{
				replacenext(tail, head, tmp);
				tmpkoniec = tmp->next->next; // przynajmniej jeden (ostatni) element bêdzie ju¿ na swoim miejscu w bubblesort
				swapped = true;
			}
		}
		cout << endl;
		koniec = tmpkoniec;
	}
}

void bubblesortdesc2(Lista *&tail, Lista *&head)
{
	bool swapped = true;
	Lista *koniec = NULL;
	if (head == NULL || head->next == NULL)
	{
		cout << "Nie ma nic do posortowania!" << endl;
		return;
	}

	if (head->next == tail) // lista dwuelementowa
	{
		if (head->i < head->next->i) // lista rosn¹ca
		{
			replacenext(tail, head, NULL); // uwzglêdnia zmianê ogona
			return;
		}
	}

	Lista *tmpkoniec = NULL;
	Lista *tmp = NULL;
	while (swapped) // drugi argument: pêtla for ju¿ siê nigdy nie wykona, lista posortowana
	{
		swapped = false;
		tmp = NULL;
		cout << "while ";
		if (head->i < head->next->i) // pierwsze porównanie, wymaga szczególnej uwagi z powodu funkcji replacenext()
		{
			cout << "head ";
			replacenext(tail, head, tmp);
			//tmpkoniec = head->next->next;
			swapped = true;
		}
		for (Lista *tmp = head; tmp->next->next != koniec; tmp = tmp->next)
		{
			cout << "for ";
			if (tmp->next->i < tmp->next->next->i)
			{
				replacenext(tail, head, tmp);
				tmpkoniec = tmp->next->next; // przynajmniej jeden (ostatni) element bêdzie ju¿ na swoim miejscu w bubblesort
				swapped = true;
			}
		}
		cout << endl;
		koniec = tmpkoniec;
	}
}
void combsort(Lista *&tail, Lista *&head);

int main()
{
	Lista *head = NULL;
	Lista *tail = NULL;
	chrono::time_point<chrono::system_clock> start, end;
	fill(tail, head, 100, 3);
	/*addend(tail, head, 10);
	addend(tail, head, 9);
	addend(tail, head, 7);
	addend(tail, head, 6);
	addend(tail, head, 5);
	addend(tail, head, 4);
	addend(tail, head, 3);
	addend(tail, head, 2);
	addend(tail, head, 1);*/ // przypadek pesymistyczny (widaæ jak algorytm sukcesywnie zmniejsza liczbê iteracji)
	start = chrono::system_clock::now();
	//bubblesortasc2(tail, head);
	combsort(tail, head);
	end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	//bubblesortdesc2(tail, head);
	wypisz(head);
	cout << tail->i << endl;
	cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	//cout << 3 / 1.3;
	system("pause");
}

//TODO: wariant z podan¹ d³ugoœci¹
void combsort(Lista *&tail, Lista *&head)
{
	int lenght = 0;
	int gap = 0;
	for (Lista *tmp = head; tmp != NULL; tmp = tmp->next, lenght++); // policz elementy w liœcie
	if (lenght < 3) // lista nie istnieje lub jest za ma³a, by gap by³ wiêkszy od 1
	{
		bubblesortasc2(tail, head);
		return;
	}
	gap = lenght;
	while(true)
	{
		gap = gap / 1.3; // dla lenght=2 bêdzie 1
		if (gap == 1)
		{
			break;
		}

		Lista *prev1 = NULL;
		Lista *prev2 = head;
		for (int i = 0; i < gap - 1; i++)
		{
			prev2 = prev2->next;
			//drugi = drugi->next; // przesuñ 'drugi' tak, aby sprawdzaæ elementy o gap
		}

		if (head->i > prev2->next->i) // specjalne traktowanie z uwagi na to, ¿e poprzednik g³owy to NULL (prev2->next nie wyjdzie poza listê)
		{
			cout << "Zamieniono " << head->i << " z " << prev2->next->i << endl;
			swap(tail, head, prev1, prev2);
		}
		//drugi = drugi->next; // mo¿e byæ równy NULL (np. lista 3-elementowa)
		prev2 = prev2->next;
		if (prev2 == tail)
		{
			break;
		}
		prev1 = head;

		for (; prev2->next != NULL; prev1 = prev1->next, prev2 = prev2->next)
		{
			if (prev1->next->i > prev2->next->i)
			{
				cout << "Zamieniono " << prev1->next->i << " z " << prev2->next->i << endl;
				swap(tail, head, prev1, prev2);
			}
		}
	}
	bubblesortasc2(tail, head);
	return;
}