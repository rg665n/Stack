// Array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Stack
struct Stack
{
    int top;
    unsigned stk_max;
    int* array;
};


struct Stack* createStack(unsigned stk_max)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->stk_max = stk_max;
    stack->top = -1;
    stack->array = (int*) malloc(stack->stk_max * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->stk_max - 1; }

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
    {
        printf("\nStack Overflow\n");
        getch();
        return;
    }

    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
      return INT_MIN;
    }

    return stack->array[stack->top--];
}

// Function to get top item from stack
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Driver program to test above functions
int main()
{
     int ch;
     struct Stack* stack;
     int item;
     while(ch!=5)
      {
      system("cls");
      printf("------------------------");
      printf("\n1.Create Stack ");
      printf("\n2.Push");
      printf("\n3.Pop");
      printf("\n4.Peek");
      printf("\n5.Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
        stack = createStack(5);
        break;
      case 2:
        printf("\n Enter value to Push in Stack : ");
        scanf("%d",&item);
        push(stack, item);
        break;
      case 3:
        printf("%d popped from stack\n", pop(stack));
        break;
      case 4:
        printf("Top item is %d\n", peek(stack));
        break;
      case 5:
        exit(1);
        break;
      default:
            printf("Enter a valid choice");
      }
        getch();
    }
return 0;
}
