// IMPLEMENTACJA WSKAèNIKOWA
////////////////////////////////
/*
Potrzebne:
1. Struktura danych (Lista) zawierajπca wskaünik do nastÍpnego elementu (next) i wartoúÊ typu int (i)
2. Random device (rd) do tworzenia listy o losowych wartoúciach
3. Wskaünik na poczπtek listy (head) - DEKLAROWANY W MAIN JAKO NULL
4. Wskaünik na koniec listy (tail) - DEKLAROWANY W MAIN JAKO NULL
*/
/*
NIEWYJAåNIONE: uøycie removefront, -end w jednym cout odwraca ich dzia≥anie?! (moøliwa kolejnoúÊ operatorÛw)
cout << () << () << ();
Najpierw przerabia wszystkie funkcje, a pÛüniej wypisuje od prawej (patrz int test)?
*/
#include <iostream>
#include <random>
#include "listawskaznik.hpp"

using namespace std;

random_device rd;

struct Lista
{
	Lista *next;
	int i = 0;
};

void fill(Lista *&tail, Lista *&head, int maks, int ile)
{
	cout << "Utworzono liste:" << endl; // head ---> tail
	for (int i = 0; i < ile; i++)
	{
		int stworz = rd() % maks;
		addend(tail, head, stworz);
		cout << stworz << " ";
	}
	cout << endl;
}

void wypisz(Lista *head)
{
	while (head)
	{
		cout << showfront(head) << " ";
		head = head->next;
	}
	cout << " -> NULL" << endl;
}

bool isEmpty(Lista *head) // OK
{
	if (head == NULL)
	{
		// cout << "!Lista pusta!" << endl;
		return true;
	}
	else return false;
}

void addend(Lista *&tail, Lista *&head, int wpisz) // dodaj na koniec OK
{
	if (isEmpty(head))
	{
		head = new Lista;
		head->i = wpisz;
		head->next = NULL;
		tail = head;
		return;
	}
	tail->next = new Lista; // polacz z nastepnym
	tail = tail->next; // zmien wsk na ostatni element
	tail->next = NULL; // ostatni nie jest polaczony
	tail->i = wpisz;
}

void addfront(Lista *&tail, Lista *&head, int wpisz) // dodaje na poczπtek OK
{
	if (isEmpty(head))
	{
		head = new Lista;
		head->i = wpisz;
		head->next = NULL;
		tail = head;
		return;
	}
	Lista *tmp = new Lista;
	tmp->i = wpisz;
	tmp->next = head;
	head = tmp;
}

int removefront(Lista *&head) // usun element z poczatku listy
{
	if (isEmpty(head))
	{
		return -1;
	}
	Lista *tmp = head;
	int answer = head->i;
	head = head->next;
	delete tmp;
	return answer;
}

int removeend(Lista *&tail, Lista *&head) //usun element z koÒca listy
{
	if (isEmpty(head)) // lista pusta
	{
		return -1;
	}

	if (head->next == NULL) // lista jednoelementowa
	{
		int answer = head->i;
		delete head;
		head = NULL;
		return answer;
	}

	Lista *tmp; // przynajmniej dwa elementy
	for (tmp = head; tmp->next->next != NULL; tmp = tmp->next); //zapamietaj przedostatni, zeby polaczyc
	int answer = tmp->next->i; // wartoúÊ ostatniego elementu
	delete tmp->next; // usuÒ ostatni
	tail = tmp; // ogon rÛwna siÍ przedostatniemu
	tail->next = NULL;
	return answer;
}

int remove(Lista *&tail, Lista *&head, Lista *pointer) // pointer - poprzednik usuwanego elementu
{
	if (isEmpty(head)) // nie ma czego usunπÊ
	{
		return -1;
	}

	if (pointer == NULL) // usuwamy head, dzia≥a teø dla jednego elementu
	{
		int answer = head->i;
		Lista *tmp = head; // head (tmp) -> ....
		head = head->next; // NULL -> nowy head...
		delete tmp;
		return answer;
	}

	// dzia≥a dla ostatniego elementu (jeúli pointer jest przedostatni)
	Lista *usun = pointer->next; // element do usuniÍcia
	Lista *polacz = pointer->next->next; // ...pointer -> !usun! -> polacz...
	pointer->next = polacz; // pointer -> polacz
	int answer = usun->i;
	delete usun;
	if (polacz == NULL) // usuniÍto stary ogon
	{
		tail = pointer;
	}
	return answer;
}

void move(Lista *&tail, Lista *&head, Lista *&tail2, Lista *&head2, Lista *pointer) // przenieú do innej listy, pointer - poprzednik przesuwanego elementu
{
	if (isEmpty(head)) // nie ma czego przesuwaÊ
	{
		return;
	}

	Lista *przenies;
	if (pointer == NULL) // przenosimy head, dzia≥a teø dla jednego elementu
	{
		przenies = head; // head (przenies) -> ....
		head = head->next; // NULL -> nowy head...
	}
	else
	{
		// dzia≥a dla ostatniego elementu (jeúli pointer jest przedostatni)?
		przenies = pointer->next; // element do przeniesienia
		Lista *polacz = pointer->next->next; // ...pointer -> !przenies! -> polacz...
		pointer->next = polacz; // pointer -> polacz

		if (polacz == NULL) // przeniesiono stary ogon
		{
			tail = pointer;
		}
	}

	//Wydzielono element do przeniesienia (przenies) oraz "sklejono" starπ listÍ po wydzieleniu
	//DODAWANIE DO NOWEJ LISTY:

	if (head2 == NULL)
	{
		head2 = przenies;
		head2->next = NULL;
		tail2 = head2;
		return;
	}
	tail2->next = przenies; // tail2 -> przenies
	tail2 = przenies;
	tail2->next = NULL; // ??? -> tail2 -> NULL
}

int showfront(Lista *head) // wyswietl element na poczatku listy
{
	if (isEmpty(head))
	{
		return -1;
	}
	return head->i;
}

int showend(Lista *tail) // wyswietl element na koÒcu listy
{
	if (isEmpty(tail))
	{
		return -1;
	}
	return tail->i;
}

// JEDEN PRZED
void replacenext(Lista *&tail, Lista *&head, Lista *pointer) // ...pointer -> !poprzednik (klucz)! -> nastepnik -> q... --- ...pointer -> nastepnik -> poprzednik -> q... (zamiana struktur)
{
	if (isEmpty(head) || head->next == NULL) // jeúli pierwszy argument prawdziwy, NIE sprawdzaj drugiego!
	{
		return; // za ma≥o elementÛw, brak interakcji
	}

	if (pointer == NULL) // pierwszy element, nie trzeba uøywaÊ pointera
	{
		Lista *tmp = head->next; // !head! -> tmp -> q...
		head->next = tmp->next; // head -> q... | tmp -> q...
		tmp->next = head; // head -> q... | tmp -> head -> q...
		head = tmp; // nowy head -> !stary head! -> q...
		if (head == tail) // lista dwuelementowa
		{
			tail = head->next;
		}
		return;
	}

	Lista *nastepnik = pointer->next->next;
	if (nastepnik == NULL) // ostatni element, brak nastÍpnika
	{
		return;
	}
	// q - reszta
	Lista *poprzednik = pointer->next; // ...pointer -> !poprz! -> nast -> q...
	pointer->next = poprzednik->next; // pointer -> nast -> q | poprz -> nast -> q
	poprzednik->next = nastepnik->next; // poprz -> q | pointer -> nast -> q
	nastepnik->next = poprzednik; // nast -> poprz | ...pointer -> nast -> !poprz! -> q
	if (nastepnik == tail) // zmieniono ogon
	{
		tail = nastepnik->next;
	}
}

// DWA PRZED
void replaceprev(Lista *&tail, Lista *&head, Lista *pointer) // ...pointer -> poprzednik -> !nastÍpnik (klucz)! -> q...
{
	// BRAK OBS£UGI PIERWSZEGO ELEMENTU, jako øe head nie ma nastÍpnika (trzeba rÍcznie obs≥uøyÊ wyjπtek)
	if (isEmpty(head) || head->next == NULL) // jeúli pierwszy argument prawdziwy, NIE sprawdzaj drugiego!
	{
		return; // za ma≥o elementÛw, brak interakcji
	}

	if (pointer == NULL) // drugi element, nie trzeba uøywaÊ pointera
	{
		Lista *tmp = head->next;
		Lista *q = head->next->next; // NULL -> head -> !tmp! -> q...

		head->next = q; // head -> q | tmp -> q
		tmp->next = head; // head -> q | tmp -> head
		head = tmp; // !nowy head! -> stary head -> q...
		if (head == tail) // lista dwuelementowa
		{
			tail = head->next;
		}
		return;
	}

	// dzia≥a takøe dla ostatniego elementu
	Lista *poprzednik = pointer->next;
	Lista *nastepnik = pointer->next->next;
	Lista *q = nastepnik->next;

	poprzednik->next->next = poprzednik; // pointer -> poprzednik -> nastepnik | nastepnik -> poprzednik
	poprzednik->next = q; // pointer -> poprzednik -> q | nastepnik -> poprzednik
	pointer->next = nastepnik; // ...pointer -> !nastepnik! -> poprzednik -> q...
	if (nastepnik == tail) // gdy zmieniono ogon
	{
		tail = nastepnik->next;
	}
}

// kolejnoúÊ: prev1 ZAWSZE przed prev2
//TODO: zamiana bez kolejnoúci?
void swap(Lista *&tail, Lista *&head, Lista *prev1, Lista *prev2) // przy za≥oøeniu, øe tail NIGDY nie powinien byÊ prev
{
	if (prev2 == NULL)
	{
		return; // lista zero-/jednoelementowa, nie ma czego zamieniaÊ
	}
	if ((prev1 == NULL && prev2 == head) || ((prev1 != NULL) && (prev1->next == prev2))) // zamiana elementÛw obok siebie
	{
		replacenext(tail, head, prev1);
		return;
	}

	Lista *zamien2;
	Lista *zamien1;
	if (prev1 == NULL) // zamiana miejscami head
	{
		zamien1 = head;
		Lista *polacz1 = head->next;
		zamien2 = prev2->next;
		Lista *polacz2 = prev2->next->next;
		// head(zamien1) -> polacz1
		head = zamien2;
		zamien2->next = polacz1; // zamien2 -> polacz1
		// prev2 -> zamien2 -> polacz1 | polacz2
		prev2->next = zamien1; // prev2 -> zamien1(stary head)
		zamien1->next = polacz2; // prev2 -> zamien1(stary head) -> polacz2
	}
	else
	{
		zamien1 = prev1->next;
		zamien2 = prev2->next; // elementy do zamienienia miejscami
		Lista *polacz1 = prev1->next->next;
		Lista *polacz2 = prev2->next->next; // nastÍpniki zamienianych elementÛw

		// prev1 -> zamien1 -> polacz1
		prev1->next = zamien2; // prev1 -> zamien2 -> polacz2
		zamien2->next = polacz1; // prev1 -> zamien2 -> polacz1
		// prev2 -> zamien2 -> !polacz1 | polacz2
		prev2->next = zamien1; // prev2 -> zamien1 -> polacz1
		zamien1->next = polacz2; // prev2 -> zamien1 -> polacz2
	}
	//cout << zamien2 << " " << tail;
	if (zamien2 == tail) // zamieniono miejscami tail
	{
		tail = zamien1;
	}
}

void bubblesortasc(Lista *&tail, Lista *&head) //!USPRAWNI∆
{
	bool swap = true;
	Lista *tmp = head;

	if (head == NULL || head->next == NULL)
	{
		cout << "Nie ma nic do posortowania!" << endl;
		return;
	}

	if (head->next == tail) // lista dwuelementowa
	{
		if (head->i > head->next->i) // lista malejπca
		{
			replacenext(tail, head, NULL); // uwzglÍdnia zmianÍ ogona
			return;
		}
	}

	while (swap) // ulepszony bubblesort sprawdzajπcy, czy jest jeszcze sens dzia≥aÊ
	{
		swap = false;
		tmp = NULL;
		if (head->i > head->next->i) // pierwsze porÛwnanie, wymaga szczegÛlnej uwagi z powodu funkcji replacenext()
		{
			//cout << "head ";
			replacenext(tail, head, tmp);
			swap = true;
		}
		for (tmp = head; tmp->next->next != NULL; tmp = tmp->next)
		{
			//cout << "for ";
			if (tmp->next->i > tmp->next->next->i)
			{
				replacenext(tail, head, tmp);
				swap = true;
			}
		}
		//cout << endl;
	}
}

void bubblesortdesc(Lista *&tail, Lista *&head)
{
	bool swap = true;
	Lista *tmp = head;
	if (head == NULL || head->next == NULL)
	{
		cout << "Nie ma nic do posortowania!" << endl;
		return;
	}
	// wariant malejπcy
	if (head->next == tail) // lista dwuelementowa
	{
		if (head->i < head->next->i) // lista rosnπca
		{
			replacenext(tail, head, NULL);
			/*// head -> tail -> NULL
			head->next = NULL; // head -> NULL | tail -> NULL
			tail->next = head; // head -> NULL | tail -> head -> NULL
			head = tail; // head -> ??? -> NULL
			tail = head->next; // head -> tail -> NULL*/
		}
	}

	while (swap) // ulepszony bubblesort sprawdzajπcy, czy jest jeszcze sens dzia≥aÊ
	{
		swap = false;
		tmp = NULL;
		if (head->i < head->next->i) // pierwsze porÛwnanie, wymaga szczegÛlnej uwagi z powodu funkcji replacenext()
		{
			replacenext(tail, head, tmp);
			swap = true;
		}
		for (tmp = head; tmp->next->next != NULL; tmp = tmp->next)
		{
			if (tmp->next->i < tmp->next->next->i)
			{
				replacenext(tail, head, tmp);
				swap = true;
			}
		}
	}
}

void insertasc(Lista *&tail, Lista *&head, int wpisz) // sortuj rosnaco przy wstawianiu
{
	if (head == NULL)
	{
		addfront(tail, head, wpisz);
		return;
	}

	if (head->i > wpisz)
	{
		Lista *polacz = head; // polacz -> NULL
		head = new Lista; // NEW | polacz -> NULL
		head->i = wpisz;
		head->next = polacz; // head -> polacz -> NULL
		return;
	}
		
	Lista *tmp;
	for (tmp = head; tmp->next != NULL; tmp = tmp->next)
	{
		if (tmp->next->i > wpisz)
		{
			Lista *polacz = tmp->next; // tmp -> polacz
			tmp->next = new Lista; // tmp -> NEW | polacz
			tmp->next->i = wpisz;
			tmp->next->next = polacz; // tmp -> next -> polacz
			break;
		}
	}

	if (tmp == tail) // nalezy wstawic liczbe na ostatnie miejsce
	{
		tail->next = new Lista; // tail -> NEW
		tail->next->i = wpisz;
		tail->next->next = NULL; // tail -> NEW -> NULL
		tail = tail->next; // ??? -> tail -> NULL
	}
}

void insertdesc(Lista *&tail, Lista *&head, int wpisz) // sortuj malejπco przy wstawianiu
{
	if (head == NULL)
	{
		addfront(tail, head, wpisz);
		return;
	}

	if (head->i < wpisz)
	{
		Lista *polacz = head; // polacz -> NULL
		head = new Lista; // NEW | polacz -> NULL
		head->i = wpisz;
		head->next = polacz; // head -> polacz -> NULL
		return;
	}

	Lista *tmp;
	for (tmp = head; tmp->next != NULL; tmp = tmp->next)
	{
		if (tmp->next->i < wpisz)
		{
			Lista *polacz = tmp->next; // tmp -> polacz
			tmp->next = new Lista; // tmp -> NEW | polacz
			tmp->next->i = wpisz;
			tmp->next->next = polacz; // tmp -> next -> polacz
			break;
		}
	}

	if (tmp == tail) // nalezy wstawic liczbe na ostatnie miejsce
	{
		tail->next = new Lista; // tail -> NEW
		tail->next->i = wpisz;
		tail->next->next = NULL; // tail -> NEW -> NULL
		tail = tail->next; // ??? -> tail -> NULL
	}
}

void copylist(Lista *&tail, Lista *head)
{
	if (head == NULL)
	{
		return; // nie ma czego kopiowaÊ
	}

	Lista *oldtail = tail;
	for (Lista *start = head; start != oldtail->next; start = start->next)
	{
		tail->next = new Lista;
		tail = tail->next;
		*tail = *start; // skopiuj strukturÍ
		tail->next = NULL; // pozbπdü siÍ powiπzania z poprzedniej struktury
	}
}

void copylistr(Lista *&tail, Lista *head)
{
	if (head == NULL)
	{
		return; // nie ma czego kopiowaÊ
	}

	Lista *oldtail = tail;
	for (Lista *start = head; start != oldtail->next; start = start->next)
	{
		Lista *polacz = oldtail->next;
		oldtail->next = new Lista;
		Lista *dodaj = oldtail->next;
		*dodaj = *start;
		dodaj->next = polacz; // dzia≥a takøe dla pierwszej iteracji (utworzenie nowego ogona z NULL

		if (start == head) // tworzenie nowego ogona
		{
			tail = dodaj;
		}

	}
}

void copy(Lista *&pointer) // kopiuj strukturÍ listy, na ktÛrπ wskazuje pointer
// !DziÍki referencji automatycznie ZMIENIA TAIL
{
	Lista *tmp = pointer; 
	Lista *polacz = pointer->next; // pointer -> polacz
	pointer->next = new Lista; // pointer -> []
	pointer = pointer->next; // ??? (tmp) -> [] (pointer)
	*pointer = *tmp; // tmp -> kopia
	pointer->next = polacz; // tmp -> kopia -> polacz
}

//Wskaüniki obu list pozostajπ, ale wskazujπ na stare g≥owy i ogony (ktÛre naleøπ teraz do wiÍkszej, posortowanej listy)
void mergesortedasc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3) // posortuj dwie listy do trzeciej
{
	if (head3 == NULL)
	{
		head3 = new Lista;
		head3->next = NULL;
		head3->i = -1; // utworzenie struktury z wartoúciπ -1, bÍdzie pomocna, gdy docelowa lista jest pusta przed scaleniem
		tail3 = head3;
	}

	Lista *tmp = head;
	Lista *tmp2 = head2;
	Lista *skok;
	Lista *dokoncz;
	while (1) // warunek koÒczπcy w pÍtli
	{
		if (tmp->i < tmp2->i)
		{
			skok = tmp->next;
			tail3->next = tmp;
			tail3 = tmp;
			tail3->next = NULL;
			tmp = skok;
		}
		else
		{
			skok = tmp2->next;
			tail3->next = tmp2;
			tail3 = tmp2;
			tail3->next = NULL;
			tmp2 = skok;
		}

		// Jedna z list musi skoÒczyÊ siÍ szybciej
		if (tmp == NULL)
		{
			dokoncz = tmp2;
			break;
		}
		else if (tmp2 == NULL)
		{
			dokoncz = tmp;
			break;
		}
	}

	for (; dokoncz != NULL; dokoncz = skok) // dopisz pozosta≥π listÍ na koniec wyjúciowej (posortowana)
	{
		skok = dokoncz->next;
		tail3->next = dokoncz;
		tail3 = dokoncz;
		tail3->next = NULL;
	}

	if (head3->i == -1)
	{
		Lista *usun = head3;
		head3 = head3->next;
		delete usun; // pozbπdü siÍ struktury pomocniczej z poczπtku
	}
	// zwrot posortowanej listy przez referencjÍ
}

void mergesorteddesc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3) // posortuj dwie listy do trzeciej
{
	if (head3 == NULL)
	{
		head3 = new Lista;
		head3->next = NULL;
		head3->i = -1; // utworzenie struktury z wartoúciπ -1, bÍdzie pomocna, gdy docelowa lista jest pusta przed scaleniem
		tail3 = head3;
	}

	Lista *tmp = head;
	Lista *tmp2 = head2;
	Lista *skok;
	Lista *dokoncz;
	while (1) // warunek koÒczπcy w pÍtli
	{
		if (tmp->i > tmp2->i)
		{
			skok = tmp->next;
			tail3->next = tmp;
			tail3 = tmp;
			tail3->next = NULL;
			tmp = skok;
		}
		else
		{
			skok = tmp2->next;
			tail3->next = tmp2;
			tail3 = tmp2;
			tail3->next = NULL;
			tmp2 = skok;
		}

		// Jedna z list musi skoÒczyÊ siÍ szybciej
		if (tmp == NULL)
		{
			dokoncz = tmp2;
			break;
		}
		else if (tmp2 == NULL)
		{
			dokoncz = tmp;
			break;
		}
	}

	for (; dokoncz != NULL; dokoncz = skok) // dopisz pozosta≥π listÍ na koniec wyjúciowej (posortowana)
	{
		skok = dokoncz->next;
		tail3->next = dokoncz;
		tail3 = dokoncz;
		tail3->next = NULL;
	}

	if (head3->i == -1)
	{
		Lista *usun = head3;
		head3 = head3->next;
		delete usun; // pozbπdü siÍ struktury pomocniczej z poczπtku
	}
	// zwrot posortowanej listy przez referencjÍ
}
/*int test(int &i)
{
i++;
cout << "i jest rowne: " << i << endl;
return i;
}*/

//do testÛw
/*int main()
{
	//int i = 0;
	//cout << (test(i)) << (test(i)) << (test(i)); system("pause");
	Lista *head = NULL;
	Lista *tail = NULL;
	addend(tail, head, 3);
	addend(tail, head, 2);
	addend(tail, head, 1); // 3->2->1
	cout << head->i << head->next->i << head->next->next->i << endl;
	//cout << removefront(head); //<< " " << removefront(head) << " " << removefront(head) << endl; // dlaczego odwraca?!
	//cout << removefront(head);
	//cout << removefront(head);
	cout << removeend(tail, head) << " "; //<< " " << removeend(tail, head) << " " << removeend(tail, head) << " ";
	cout << removeend(tail, head) << " ";
	cout << removeend(tail, head) << " ";

	system("pause");
}*/