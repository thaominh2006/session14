//
// Created by Admin on 09/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
// ham khoi tao stack, ban dau se la null
Node* createStack()
{
    return NULL;
}
Node* pushStack(int value, Node* top)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Bo nho khong du de cap phat!");
        exit(1);
    }
    node -> data = value;
    node -> next = top;
    // node tro thanh top moi cua stack
    return node;
}
int isEmpty(Node* top)
{
    return top == NULL;
}
Node* popStack(Node* top)
{
    if (isEmpty(top))
    {
        printf("Stack rong, khong the xoa phan tu dau!\n");
        return -1;
    }
    Node* temp = top;
    top = top -> next;
    return top;
}
void printStack(Node* top)
{
    if (isEmpty(top))
    {
        printf("Ngan xep hien tai rong!");
        return;
    }
    Node* temp = top;
    while (temp != NULL)
    {
        printf("%d -> ",temp -> data);
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
        free(temp); // giai phong tung node
    }
}
int main()
{
    Node* stack = createStack();
    stack = pushStack(1, stack);
    stack = pushStack(2, stack);
    stack = pushStack(3, stack);
    stack = pushStack(4, stack);
    stack = pushStack(5, stack);
    printStack(stack);

    stack = popStack(stack);
    printStack(stack);
    freeStack(stack);
    return 0;
}
