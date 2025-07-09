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
Node* pushStack(int value, Node* top)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Bo nho khong du de cap phat dong");
        exit(1);
    }
    node -> data = value;
    node -> next = top;
    return node;
}
int isEmpty(Node* top)
{
    return top == NULL;
}
void printStack(Node* top)
{
    Node* temp = top;
    while (temp != NULL)
    {
        printf("%d ->", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
void freeStack(Node* top)
{
    Node* temp;
    while (top != NULL)
    {
        temp = top;
        top = top -> next;
        free(temp);
    }
}
int main()
{
    Node* stack = NULL;
    stack = pushStack(5, stack);
    stack = pushStack(7, stack);
    stack = pushStack(9, stack);
    stack = pushStack(10, stack);
    stack = pushStack(11, stack);
    printStack(stack);

    int value;
    printf("Moi ban nhap mot so bat ky: ");
    scanf("%d", &value);

    stack = pushStack(value, stack);
    printf("Stack sau khi duoc them: ");
    printStack(stack);

    freeStack(stack);
    return 0;
}
