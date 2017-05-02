#ifndef listawskaznik_hpp
#define listawskaznik_hpp

struct Lista;
void fill(Lista *&tail, Lista *&head, int maks, int ile);
void wypisz(Lista *head);
bool isEmpty(Lista *head);
void addend(Lista *&tail, Lista *&head, int wpisz); // dodaj na koniec
void addfront(Lista *&tail, Lista *&head, int wpisz); // dodaje na pocz�tek
int removefront(Lista *&head); // usun element z poczatku listy
int removeend(Lista *&tail, Lista *&head); // usun element z ko�ca listy
int remove(Lista *&tail, Lista *&head, Lista *pointer); // usu� element (pointer to poprzednik usuwanego elementu)
void move(Lista *&tail, Lista *&head, Lista *&tail2, Lista *&head2, Lista *pointer); // przenie� do innej listy, pointer - poprzednik przesuwanego elementu
int showfront(Lista *head); // wyswietl element na poczatku listy
int showend(Lista *tail); // wyswietl element na ko�cu listy
void replacenext(Lista *&tail, Lista *&head, Lista *pointer); // zamie� nast�pnik z poprzednikiem (kluczem) (poprzednik to pointer->next)
void replaceprev(Lista *&tail, Lista *&head, Lista *pointer); // zamie� poprzednik z nast�pnikiem (kluczem) (nast�pnik to pointer->next->next)
void swap(Lista *&tail, Lista *&head, Lista *prev1, Lista *prev2); // zamie� dwa elementy miejscami (u�ywa dw�ch poprzednik�w)
void bubblesortasc(Lista *&tail, Lista *&head); // sortowanie b�belkowe rosn�co
void bubblesortdesc(Lista *&tail, Lista *&head); // sortowanie b�belkowe malej�co
void insertasc(Lista *&tail, Lista *&head, int wpisz); // sortuj rosn�co przy wstawianiu
void insertdesc(Lista *&tail, Lista *&head, int wpisz); // sortuj malej�co przy wstawianiu
void copylist(Lista *&tail, Lista *head); // kopiuj list�
void copylistr(Lista *&tail, Lista *head); // kopiuj list� odwrotnie
void copy(Lista *&pointer); // kopiuj struktur� listy, na kt�r� wskazuje pointer
void mergesortedasc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3); // posortuj dwie listy do trzeciej
void mergesorteddesc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3); // posortuj dwie listy do trzeciej

#endif
