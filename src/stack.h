#ifndef stack_H
#define stack_H

typedef struct StackElement StackElement;

struct StackElement
{
  StackElement *next;
  int data;
};

typedef struct
{
  StackElement *head;
  StackElement *tail;
}Stack;

Stack *stackCreate();
StackElement *stackElementCreate(int value);
void stackAdd(Stack *stack, StackElement *elem);
StackElement *stackRemove(Stack *stack);

#endif // stack_H
