#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

Stack *stackCreate()
{
  Stack *stack = malloc(sizeof(Stack));
  
  stack->head = NULL;
  stack->tail = NULL;
  
  return stack;
}

StackElement *stackElementCreate(int value)
{
  StackElement *newElement = malloc(sizeof(StackElement));
  newElement->data = value;
  newElement->next = NULL;
  
  return newElement;
}

void stackAdd(Stack *stack, StackElement *elem)
{
  assert(stack != NULL);
  
  StackElement *currentElement = malloc(sizeof(StackElement));
   
  if(stack->head == NULL && stack->tail == NULL)
  {
    stack->head = elem;
    stack->tail = elem;
    currentElement = elem;
  }
  else
  {
    stack->head = elem;
    stack->head->next = currentElement;
    currentElement = stack->head;
  }
}

StackElement *stackRemove(Stack *stack)
{
  assert(stack != NULL);
  
  StackElement *topElement = malloc(sizeof(StackElement));

  topElement = stack->head;
  stack->head = topElement->next;
  topElement->next = NULL;
  
  return topElement;
}