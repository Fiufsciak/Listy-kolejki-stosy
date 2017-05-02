#ifndef stoswskaznik_hpp
#define stoswskaznik_hpp

struct Stack;
bool isEmpty(Stack *top);
void push(Stack *&top, int dodaj);
int pop(Stack *&top);
int showtop(Stack *top);

#endif
