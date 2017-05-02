// sortowanie dwóch list do trzeciej listy
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
	// WARIANT MALEJ¥CY (rosn¹cy w komentarzach)
	Lista *head = NULL;
	Lista *tail = NULL;
	fill(tail, head, 100, 10);
	bubblesortdesc(tail, head); //bubblesortasc(tail, head);
	wypisz(head);
	Lista *head2 = NULL;
	Lista *tail2 = NULL;
	fill(tail2, head2, 100, 10);
	bubblesortdesc(tail2, head2); //bubblesortasc(tail, head);
	wypisz(head2);

	Lista *head3 = NULL;
	Lista *tail3 = NULL;
	mergesorteddesc(tail, head, tail2, head2, tail3, head3); // mergesortedasc(tail, head, tail2, head2, tail3, head3);
	wypisz(head3);
	cout << tail3->i;

	system("pause");
}