#ifndef listawskaznik_hpp
#define listawskaznik_hpp

struct Lista;
void fill(Lista *&tail, Lista *&head, int maks, int ile);
void wypisz(Lista *head);
bool isEmpty(Lista *head);
void addend(Lista *&tail, Lista *&head, int wpisz); // dodaj na koniec
void addfront(Lista *&tail, Lista *&head, int wpisz); // dodaje na pocz¹tek
int removefront(Lista *&head); // usun element z poczatku listy
int removeend(Lista *&tail, Lista *&head); // usun element z koñca listy
int remove(Lista *&tail, Lista *&head, Lista *pointer); // usuñ element (pointer to poprzednik usuwanego elementu)
void move(Lista *&tail, Lista *&head, Lista *&tail2, Lista *&head2, Lista *pointer); // przenieœ do innej listy, pointer - poprzednik przesuwanego elementu
int showfront(Lista *head); // wyswietl element na poczatku listy
int showend(Lista *tail); // wyswietl element na koñcu listy
void replacenext(Lista *&tail, Lista *&head, Lista *pointer); // zamieñ nastêpnik z poprzednikiem (kluczem) (poprzednik to pointer->next)
void replaceprev(Lista *&tail, Lista *&head, Lista *pointer); // zamieñ poprzednik z nastêpnikiem (kluczem) (nastêpnik to pointer->next->next)
void swap(Lista *&tail, Lista *&head, Lista *prev1, Lista *prev2); // zamieñ dwa elementy miejscami (u¿ywa dwóch poprzedników)
void bubblesortasc(Lista *&tail, Lista *&head); // sortowanie b¹belkowe rosn¹co
void bubblesortdesc(Lista *&tail, Lista *&head); // sortowanie b¹belkowe malej¹co
void insertasc(Lista *&tail, Lista *&head, int wpisz); // sortuj rosn¹co przy wstawianiu
void insertdesc(Lista *&tail, Lista *&head, int wpisz); // sortuj malej¹co przy wstawianiu
void copylist(Lista *&tail, Lista *head); // kopiuj listê
void copylistr(Lista *&tail, Lista *head); // kopiuj listê odwrotnie
void copy(Lista *&pointer); // kopiuj strukturê listy, na któr¹ wskazuje pointer
void mergesortedasc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3); // posortuj dwie listy do trzeciej
void mergesorteddesc(Lista *tail, Lista *head, Lista *tail2, Lista *head2, Lista *&tail3, Lista *&head3); // posortuj dwie listy do trzeciej

#endif
