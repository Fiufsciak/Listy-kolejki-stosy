#ifndef kolejkawskaznik_hpp
#define kolejkawskaznik_hpp

class Test;
struct Kolejka;
bool isEmpty(Kolejka *head);
void enqueue(Kolejka *&tail, Kolejka *&head, int wpisz); // dodaj na koniec
int dequeue(Kolejka *&tail, Kolejka *&head); // usun element z poczatku kolejki
int front(Kolejka *head); // wyswietl element na poczatku kolejki

#endif
