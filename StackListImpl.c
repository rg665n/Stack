// Linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *head)
{
    return !head;
}

void push(struct StackNode** head, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *head;
    *head = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** head)
{
    if (isEmpty(*head))
        return INT_MIN;
    struct StackNode* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* head)
{
    if (isEmpty(head))
        return INT_MIN;
    return head->data;
}

int main()
{
    struct StackNode* head = NULL;
    int ch;
    int item;
         while(ch!=4)
      {
      system("cls");
      printf("------------------------");
      printf("\n1.Push");
      printf("\n2.Pop");
      printf("\n3.Peek");
      printf("\n4.Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
        printf("\n Enter value to Push in Stack : ");
        scanf("%d",&item);
        push(&head, item);
        break;
      case 2:
        printf("%d popped from stack\n", pop(&head));
        break;
      case 3:
        printf("Top item is %d\n", peek(head));
        break;
      case 4:
        exit(1);
        break;
      default:
            printf("Enter a valid choice");
      }
        getch();
    }


    return 0;
}
