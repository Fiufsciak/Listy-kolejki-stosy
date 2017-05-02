// IMPLEMENTACJA WSKA�NIKOWA
////////////////////////////////
/*
Potrzebne:
1. Struktura danych (Lista) zawieraj�ca wska�nik do nast�pnego elementu (next) i warto�� typu int (i)
2. Random device (rd) do tworzenia listy o losowych warto�ciach
3. Wska�nik na pocz�tek listy (head) - DEKLAROWANY W MAIN JAKO NULL
4. Wska�nik na koniec listy (tail) - DEKLAROWANY W MAIN JAKO NULL
*/
/*
NIEWYJA�NIONE: u�ycie removefront, -end w jednym cout odwraca ich dzia�anie?! (mo�liwa kolejno�� operator�w)
cout << () << () << ();
Najpierw przerabia wszystkie funkcje, a p�niej wypisuje od prawej (patrz int test)?
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

void addfront(Lista *&tail, Lista *&head, int wpisz) // dodaje na pocz�tek OK
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

int removeend(Lista *&tail, Lista *&head) //usun element z ko�ca listy
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
	int answer = tmp->next->i; // warto�� ostatniego elementu
	delete tmp->next; // usu� ostatni
	tail = tmp; // ogon r�wna si� przedostatniemu
	tail->next = NULL;
	return answer;
}

int remove(Lista *&tail, Lista *&head, Lista *pointer) // pointer - poprzednik usuwanego elementu
{
	if (isEmpty(head)) // nie ma czego usun��
	{
		return -1;
	}

	if (pointer == NULL) // usuwamy head, dzia�a te� dla jednego elementu
	{
		int answer = head->i;
		Lista *tmp = head; // head (tmp) -> ....
		head = head->next; // NULL -> nowy head...
		delete tmp;
		return answer;
	}

	// dzia�a dla ostatniego elementu (je�li pointer jest przedostatni)
	Lista *usun = pointer->next; // element do usuni�cia
	Lista *polacz = pointer->next->next; // ...pointer -> !usun! -> polacz...
	pointer->next = polacz; // pointer -> polacz
	int answer = usun->i;
	delete usun;
	if (polacz == NULL) // usuni�to stary ogon
	{
		tail = pointer;
	}
	return answer;
}

void move(Lista *&tail, Lista *&head, Lista *&tail2, Lista *&head2, Lista *pointer) // przenie� do innej listy, pointer - poprzednik przesuwanego elementu
{
	if (isEmpty(head)) // nie ma czego przesuwa�
	{
		return;
	}

	Lista *przenies;
	if (pointer == NULL) // przenosimy head, dzia�a te� dla jednego elementu
	{
		przenies = head; // head (przenies) -> ....
		head = head->next; // NULL -> nowy head...
	}
	else
	{
		// dzia�a dla ostatniego elementu (je�li pointer jest przedostatni)?
		przenies = pointer->next; // element do przeniesienia
		Lista *polacz = pointer->next->next; // ...pointer -> !przenies! -> polacz...
		pointer->next = polacz; // pointer -> polacz

		if (polacz == NULL) // przeniesiono stary ogon
		{
			tail = pointer;
		}
	}

	//Wydzielono element do przeniesienia (przenies) oraz "sklejono" star� list� po wydzieleniu
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

int showend(Lista *tail) // wyswietl element na ko�cu listy
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
	if (isEmpty(head) || head->next == NULL) // je�li pierwszy argument prawdziwy, NIE sprawdzaj drugiego!
	{
		return; // za ma�o element�w, brak interakcji
	}

	if (pointer == NULL) // pierwszy element, nie trzeba u�ywa� pointera
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
	if (nastepnik == NULL) // ostatni element, brak nast�pnika
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
void replaceprev(Lista *&tail, Lista *&head, Lista *pointer) // ...pointer -> poprzednik -> !nast�pnik (klucz)! -> q...
{
	// BRAK OBS�UGI PIERWSZEGO ELEMENTU, jako �e head nie ma nast�pnika (trzeba r�cznie obs�u�y� wyj�tek)
	if (isEmpty(head) || head->next == NULL) // je�li pierwszy argument prawdziwy, NIE sprawdzaj drugiego!
	{
		return; // za ma�o element�w, brak interakcji
	}

	if (pointer == NULL) // drugi element, nie trzeba u�ywa� pointera
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

	// dzia�a tak�e dla ostatniego elementu
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

// kolejno��: prev1 ZAWSZE przed prev2
//TODO: zamiana bez kolejno�ci?
void swap(Lista *&tail, Lista *&head, Lista *prev1, Lista *prev2) // przy za�o�eniu, �e tail NIGDY nie powinien by� prev
{
	if (prev2 == NULL)
	{
		return; // lista zero-/jednoelementowa, nie ma czego zamienia�
	}
	if ((prev1 == NULL && prev2 == head) || ((prev1 != NULL) && (prev1->next == prev2))) // zamiana element�w obok siebie
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
		Lista *polacz2 = prev2->next->next; // nast�pniki zamienianych element�w

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

void bubblesortasc(Lista *&tail, Lista *&head) //!USPRAWNI�
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
		if (head->i > head->next->i) // lista malej�ca
		{
			replacenext(tail, head, NULL); // uwzgl�dnia zmian� ogona
			return;
		}
	}

	while (swap) // ulepszony bubblesort sprawdzaj�cy, czy jest jeszcze sens dzia�a�
	{
		swap = false;
		tmp = NULL;
		if (head->i > head->next->i) // pierwsze por�wnanie, wymaga szczeg�lnej uwagi z powodu funkcji replacenext()
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
	// wariant malej�cy
	if (head->next == tail) // lista dwuelementowa
	{
		if (head->i < head->next->i) // lista rosn�ca
		{
			replacenext(tail, head, NULL);
			/*// head -> tail -> NULL
			head->next = NULL; // head -> NULL | tail -> NULL
			tail->next = head; // head -> NULL | tail -> head -> NULL
			head = tail; // head -> ??? -> NULL
			tail = head->next; // head -> tail -> NULL*/
		}
	}

	while (swap) // ulepszony bubblesort sprawdzaj�cy, czy jest jeszcze sens dzia�a�
	{
		swap = false;
		tmp = NULL;
		if (head->i < head->next->i) // pierwsze por�wnanie, wymaga szczeg�lnej uwagi z powodu funkcji replacenext()
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

void insertdesc(Lista *&tail, Lista *&head, int wpisz) // sortuj malej�co przy wstawianiu
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
		return; // nie ma czego kopiowa�
	}

	Lista *oldtail = tail;
	for (Lista *start = head; start != oldtail->next; start = start->next)
	{
		tail->next = new Lista;
		tail = tail->next;
		*tail = *start; // skopiuj struktur�
		tail->next = NULL; // pozb�d� si� powi�zania z poprzedniej struktury
	}
}

void copylistr(Lista *&tail, Lista *head)
{
	if (head == NULL)
	{
		return; // nie ma czego kopiowa�
	}

	Lista *oldtail = tail;
	for (Lista *start = head; start != oldtail->next; start = start->next)
	{
		Lista *polacz = oldtail->next;
		oldtail->next = new Lista;
		Lista *dodaj = oldtail->next;
		*dodaj = *start;
		dodaj->next = polacz; // dzia�a tak�e dla pierwszej iteracji (utworzenie nowego ogona z NULL

		if (start == head) // tworzenie nowego ogona
		{
			tail = dodaj;
		}

	}
}

void copy(Lista *&pointer) // kopiuj struktur� listy, na kt�r� wskazuje pointer
// !Dzi�ki referencji automatycznie ZMIENIA TAIL
{
	Lista *tmp = pointer; 
	Lista *polacz = pointer->next; // pointer -> polacz
	pointer->next = new Lista; // pointer -> []
	pointer = pointer->next; // ??? (tmp) -> [] (pointer)
	*pointer = *tmp; // tmp -> kopia
	pointer->next = polacz; // tmp -> kopia -> polacz
}

//Wska�niki obu list pozostaj�, ale wskazuj� na stare g�owy i ogony (kt�re nale�� teraz do wi�kszej, posortowanej listy)
void mergesortedasc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3) // posortuj dwie listy do trzeciej
{
	if (head3 == NULL)
	{
		head3 = new Lista;
		head3->next = NULL;
		head3->i = -1; // utworzenie struktury z warto�ci� -1, b�dzie pomocna, gdy docelowa lista jest pusta przed scaleniem
		tail3 = head3;
	}

	Lista *tmp = head;
	Lista *tmp2 = head2;
	Lista *skok;
	Lista *dokoncz;
	while (1) // warunek ko�cz�cy w p�tli
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

		// Jedna z list musi sko�czy� si� szybciej
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

	for (; dokoncz != NULL; dokoncz = skok) // dopisz pozosta�� list� na koniec wyj�ciowej (posortowana)
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
		delete usun; // pozb�d� si� struktury pomocniczej z pocz�tku
	}
	// zwrot posortowanej listy przez referencj�
}

void mergesorteddesc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3) // posortuj dwie listy do trzeciej
{
	if (head3 == NULL)
	{
		head3 = new Lista;
		head3->next = NULL;
		head3->i = -1; // utworzenie struktury z warto�ci� -1, b�dzie pomocna, gdy docelowa lista jest pusta przed scaleniem
		tail3 = head3;
	}

	Lista *tmp = head;
	Lista *tmp2 = head2;
	Lista *skok;
	Lista *dokoncz;
	while (1) // warunek ko�cz�cy w p�tli
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

		// Jedna z list musi sko�czy� si� szybciej
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

	for (; dokoncz != NULL; dokoncz = skok) // dopisz pozosta�� list� na koniec wyj�ciowej (posortowana)
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
		delete usun; // pozb�d� si� struktury pomocniczej z pocz�tku
	}
	// zwrot posortowanej listy przez referencj�
}
/*int test(int &i)
{
i++;
cout << "i jest rowne: " << i << endl;
return i;
}*/

//do test�w
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