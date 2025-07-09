//
// Created by Admin on 09/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int x)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Bo nho khong du de cap phat dong!");
        exit(1);
    }
    node -> data = x;
    node -> next = NULL;
    return node;
}
typedef struct
{
    Node* head;
}Stack;
void initStack(Stack* s)
{
    s -> head = NULL;
}
void push(Stack* s, int x)
{
    Node *node = createNode(x);
    node -> next = s -> head;
    s -> head = node;
}
void printStack(Stack* s)
{
    Node* current = s -> head;
    while (current != NULL)
    {
        printf("%d ->", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}
void checkStack(Stack* s)
{
    if (s -> head == NULL)
    {
        printf("Ngan xep trong\n");
        return;
    }
    Node* current = s -> head;
    while (current != NULL)
    {
        printf("%d\n", current -> data);
        current = current -> next;
    }
}
void freeStack(Stack *s)
{
    Node* current = s -> head;
    while (current != NULL)
    {
        Node* temp = current;
        current = current -> next;
        free(temp);
    }
    s -> head = NULL;
}
int main()
{
    Stack s;
    initStack(&s);

    int stack[] = {3,6,1,9,8};
    for (int i = 0; i < 5; i++)
    {
        push(&s, stack[i]);
    }
    printStack(&s);
    checkStack(&s);
    freeStack(&s);
    return 0;
}
