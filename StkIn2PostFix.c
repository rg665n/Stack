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
    if (t=='+' || t=='-' || t=='*' || t=='/' || t=='^')
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

int getPrecedence(char t) {     //Here 1 is lowest priority and number higher than 1 has more priority
    if( t=='^') {
        return 3; //Highest Priority
    }
    else if (t=='*' || t=='/' ) //Higher Priority
        return 2; //Priority High
    else //(t=='+' || t=='-') //Lower Priority
        return 1; //Priority Low
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
    printf("%c pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
      return CHAR_MIN;
    }
    printf("%c poped out",stack->array[stack->top]);
    return stack->array[stack->top--];
}

// Function to get top item from stack
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return CHAR_MIN;
    return stack->array[stack->top];
}

void in2post (char *inexp) {
    char t;
    char postExp[25];
    int i,j;
    struct Stack* stack;
    i=j=0;
    printf("\nInput Infix Expression is : %s",inexp);
    stack = createStack(20);
    while(inexp[i] != '\0') {

        if(isParenthesis(inexp[i]) == 2) {  //Right Parenthesis
                printf("\nRight Parenthesis");
                while(peek(stack) != '(') { // pop until a left parenthesis encounters
                    if(peek(stack) != CHAR_MIN){
                       postExp[j] = pop(stack);
                       j++;
                    }
                }
                pop(stack); //Remove Left Parenthesis
        }

        else if(isParenthesis(inexp[i]) == 1 || isOperator(inexp[i]) == 1) {        //Operator or Left Parenthesis
            if(isParenthesis(inexp[i]) == 1 ) {
                printf("\nLeft Parenthesis");
                push(stack, inexp[i]);  // Push Left Parenthesis on Stack
            }
            if (isOperator(inexp[i]) == 1) {
                printf("\nOperator");
                while((getPrecedence(inexp[i]) <= getPrecedence(peek(stack))) && (peek(stack) != CHAR_MIN) && (isParenthesis(peek(stack)) != 1 )  ) {
                   postExp[j] = pop(stack);
                   j++;
                }
                push(stack, inexp[i]);
            }
        }
        else{  //if t is operand
            postExp[j] = inexp[i];
            printf("\n%c",postExp[j]);
            j++;
        }
        i++;

    }
    while(peek(stack) != CHAR_MIN) {
        postExp[j] = pop(stack);
        j++;
    }
    postExp[j] = '\0';
    printf("\nOperand List : %s\n",postExp);
    //printf("%c popped from stack\n", pop(stack));
    //printf("%c popped from stack\n", pop(stack));
    //printf("%c popped from stack\n", pop(stack));
    //printf("%c popped from stack\n", pop(stack));
}

int main()
{
     char inexp[25];
     printf("Please Enter Infix Expression : ");
     scanf("%s",inexp);
     printf("\n\nInput Infix Expression is : ");
     printf("\n%s",inexp);
     printf("\n Calling in2post\n\n");
     in2post(inexp);
return 0;
}
