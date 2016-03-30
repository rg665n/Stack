//C program to transform Infix Expression into Postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Stack
struct Stack
{
    int top;
    unsigned stk_max;
    char* array;
};

struct Stack* createStack(unsigned stk_max)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->stk_max = stk_max;
    stack->top = -1;
    stack->array = (char*) malloc(stack->stk_max * sizeof(char));
    return stack;
}

//Check if input is operator
int isOperator(char t) {
    if (t=='+' || t=='-' || t=='*' || t=='/')
        return 1;
    return 0;
}

int isParenthesis(char t) {
    if(t=='(') // Left Parenthesis
        return 1;
    if(t==')') //Right Parenthesis
        return 2;
    return 0; //Not Parenthesis
}

int getPrecedence(char t) {
    if (t=='*' || t=='/') //Higher Priority
        return 1; //Priority 1
    else //(t=='+' || t=='-') //Lower Priority
        return 2; //Priority 2
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{   return stack->top == stack->stk_max - 1; }

int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
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
char pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
      return CHAR_MIN;
    }

    return stack->array[stack->top--];
}

// Function to get top item from stack
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return CHAR_MIN;
    return stack->array[stack->top];
}

int main()
{
     char exp[20];
     printf("Please Enter Infix Expression : ");
     scanf("%s",exp);
     printf("\n\nInput Infix Expression is : ");
     printf("\n%s",exp);
     printf("\n%c",exp[0]);
     printf("\n%c",exp[1]);
     printf("\n%c",exp[2]);


return 0;
}
