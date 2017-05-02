#include <iostream>
#include "listawskaznik.hpp"

using namespace std;

/*struct Lista
{
	Lista *next;
	int i;
};*/

int main()
{
	/*int i = 0;
	cout << (test(i)) << (test(i)) << (test(i)); system("pause");*/
	Lista *head = NULL;
	Lista *tail = NULL;
	addend(tail, head, 3);
	addend(tail, head, 2);
	addend(tail, head, 1); // 3->2->1
	//cout << head->i << head->next->i << head->next->next->i << endl; dlaczego to nie dzia³a bez zadeklarowanej struktury w Source.cpp?
	cout << showfront(head) << " ";
	cout << showend(tail) << " " << endl;
	/*cout << removefront(head); //<< " " << removefront(head) << " " << removefront(head) << endl; // dlaczego odwraca?!
	cout << removefront(head);
	cout << removefront(head);*/
	cout << removeend(tail, head) << " "; //<< " " << removeend(tail, head) << " " << removeend(tail, head) << " ";
	cout << removeend(tail, head) << " ";
	cout << removeend(tail, head) << " ";
	fill(tail, head, 100, 5);

	system("pause");
}