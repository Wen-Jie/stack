#include "unity.h"
#include "stack.h"

void setUp(void){}
void tearDown(void){}


//   stack->head----+--->NULL
//                  |
//   stack->tail----+
void test_stackCreate_stack_is_clear(void)
{
  Stack *stack = stackCreate();
  
  TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NULL(stack->head);
  TEST_ASSERT_NULL(stack->tail);
}

//                     -----------
//   newElement------>| 1 | NULL |
//                    -----------
void test_stackElementCreate_create_a_stack_element_for_value_1(void)
{
  StackElement *newElement = stackElementCreate(1);
  
  TEST_ASSERT_NOT_NULL(newElement);
  TEST_ASSERT_EQUAL(1, newElement->data);
  TEST_ASSERT_NULL(newElement->next); 
}

//                           -----------
//    newElement  ---+----->| 1 | NULL |
//                   |      -----------
//    stack->head ---+     
//                   |
//    stack->tail ---+
void test_stackAdd_add_newElement_to_stack_head_and_tail(void)
{
  Stack *stack = stackCreate();
  StackElement *newElement = stackElementCreate(1);
  
  stackAdd(stack, newElement);
  TEST_ASSERT_EQUAL(newElement->data, stack->head->data);
  TEST_ASSERT_NULL(stack->head->next);
  TEST_ASSERT_EQUAL(newElement->data, stack->tail->data);
  TEST_ASSERT_NULL(stack->tail->next);
}

//                       --------           -----------
//    newElement ----+->| 2 | +-|----+---->| 1 | NULL |
//                   |  --------     |     -----------
//    stack->head ---+               |
//    stack->tail--------------------+
void test_stackAdd_push_first_newElement_to_stack(void)
{
  Stack *stack = stackCreate();
  
  StackElement *firstElement = stackElementCreate(1);
  stackAdd(stack, firstElement);
  TEST_ASSERT_EQUAL(firstElement->data, stack->head->data);
  TEST_ASSERT_NULL(stack->head->next);
  TEST_ASSERT_EQUAL(firstElement->data, stack->tail->data);
  TEST_ASSERT_NULL(stack->tail->next);
  
  StackElement *newElement = stackElementCreate(2);
  stackAdd(stack, newElement);
  TEST_ASSERT_EQUAL(newElement->data, stack->head->data);
  TEST_ASSERT_NOT_NULL(stack->head->next); 
  TEST_ASSERT_EQUAL(firstElement->data, stack->tail->data);
  TEST_ASSERT_NULL(stack->tail->next);
}

//                      --------       --------          -----------
//    newElement ---+->| 3 | +-|----->| 2 | +-|---+---->| 1 | NULL |   
//                  |  --------       --------    |     -----------
//    stack->head --+                             |
//    stack->tail --------------------------------+
void test_stackAdd_push_second_newElement_to_stack(void)
{
  Stack *stack = stackCreate();
  
  StackElement *firstElement = stackElementCreate(1);
  stackAdd(stack, firstElement);
  TEST_ASSERT_EQUAL(firstElement->data, stack->head->data);
  TEST_ASSERT_NULL(stack->head->next);
  TEST_ASSERT_EQUAL(firstElement->data, stack->tail->data);
  TEST_ASSERT_NULL(stack->tail->next);
  
  StackElement *secondElement = stackElementCreate(2);
  stackAdd(stack, secondElement);
  TEST_ASSERT_EQUAL(secondElement->data, stack->head->data);
  TEST_ASSERT_NOT_NULL(stack->head->next); 
  TEST_ASSERT_EQUAL(firstElement->data, stack->tail->data);
  TEST_ASSERT_NULL(stack->tail->next);
  
  StackElement *newElement = stackElementCreate(3);
  stackAdd(stack, newElement);
  TEST_ASSERT_EQUAL(newElement->data, stack->head->data);
  TEST_ASSERT_NOT_NULL(stack->head->next); 
  TEST_ASSERT_EQUAL(firstElement->data, stack->tail->data);
  TEST_ASSERT_NULL(stack->tail->next);
}

//                    -----------          --------         -----------
//    topElement---->| 3 | NULL |    +--->| 2 | +-|---+--->| 1 | NULL |
//                   -----------     |    --------    |    -----------
//    stack->head--------------------+                |
//    stack->tail-------------------------------------+
void test_stackRemove_pop_top_element_of_the_stack(void)
{
  Stack *stack = stackCreate();
  
  StackElement *firstElement = stackElementCreate(1);
  stackAdd(stack, firstElement);
  StackElement *secondElement = stackElementCreate(2);
  stackAdd(stack, secondElement);
  StackElement *thirdElement = stackElementCreate(3);
  stackAdd(stack, thirdElement);
  
  StackElement *topElement = stackRemove(stack);
  TEST_ASSERT_EQUAL(thirdElement->data, topElement->data);
  TEST_ASSERT_NULL(topElement->next);
  free(topElement);
}
