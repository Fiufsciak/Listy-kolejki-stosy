#ifndef stostablica_hpp
#define stostablica_hpp

bool isFull(int top, const int rozmiar);
bool isEmpty(int top);
void push(int Stack[], int &top, const int rozmiar, int dodaj);
int pop(int Stack[], int &top);
int showtop(int Stack[], int top);

#endif