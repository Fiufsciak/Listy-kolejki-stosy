#ifndef kolejkatablica_hpp
#define kolejkatablica_hpp

bool isEmpty(int rozmiar);
bool isFull(int size, int rozmiar);
void enqueue(int &head, int &tail, int tab[], int size, int &rozmiar, int dodaj); // dodaj na koniec
int dequeue(int &head, int &tail, int tab[], int size, int &rozmiar); // usun element z poczatku kolejki
int front(int head, int tab[]); // wyswietl element na poczatku kolejki


#endif
