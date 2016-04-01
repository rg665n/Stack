//C program to transform Infix Expression into Prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>

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
    printf("\n%c Pushed to Stack", item);
}

// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
      return CHAR_MIN;
    }
    printf("\n%c Poped out of Stack",stack->array[stack->top]);
    return stack->array[stack->top--];
}

// Function to get top item from stack
char peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return CHAR_MIN;
    return stack->array[stack->top];
}

void in2pre (char *inexp) {
    char t;
    char preExp[25];
    char *rInExp;
    char *rPreExp;
    int i,j;
    struct Stack* stack;
    i=j=0;
    printf("\nInput Infix Expression is : %s",inexp);
    rInExp = strrev(inexp);
    printf("\nReversed input Infix Expression is : %s",rInExp);
    stack = createStack(25);
    while(rInExp[i] != '\0') {

        if(isParenthesis(rInExp[i]) == 1) {  //Left Parenthesis
                printf("\nLeft Parenthesis Encountered.");
                while(peek(stack) != ')') { // pop until a Right parenthesis encounters
                    if(peek(stack) != CHAR_MIN){
                       preExp[j] = pop(stack);
                       j++;
                    }
                }
                pop(stack); //Remove Left Parenthesis
        }

        else if(isParenthesis(rInExp[i]) == 2 || isOperator(rInExp[i]) == 1) {        //Operator or Right Parenthesis
            if(isParenthesis(rInExp[i]) == 2 ) {
                printf("\nRight Parenthesis Encountered.");
                push(stack, rInExp[i]);  // Push Right Parenthesis on Stack
            }
            if (isOperator(rInExp[i]) == 1) {
                printf("\nOperator Encountered.");
                while((getPrecedence(rInExp[i]) < getPrecedence(peek(stack))) && (peek(stack) != CHAR_MIN) && (isParenthesis(peek(stack)) != 2 )  ) {
                   preExp[j] = pop(stack);
                   j++;
                }
                push(stack, rInExp[i]);
            }
        }
        else{  //if t is operand
            preExp[j] = rInExp[i];
            printf("\nOperand : %c",preExp[j]);
            j++;
        }
        i++;

    }
    while(peek(stack) != CHAR_MIN) {
        preExp[j] = pop(stack);
        j++;
    }
    preExp[j] = '\0';
    printf("\nPreFix : %s\n",preExp);
    rPreExp = strrev(preExp);
    printf("\nFinal PreFix : %s\n",rPreExp);
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
     printf("\nInput Infix Expression is : ");
     printf("\n%s",inexp);
     printf("\nCalling in2pre......");
     in2pre(inexp);
return 0;
}
