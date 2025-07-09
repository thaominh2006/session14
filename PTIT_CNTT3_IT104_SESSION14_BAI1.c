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
void printStack(Node* top)
{
    printf("Cac phan tu co trong stack hien tai la: ");
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
    printf("NULL");
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
    stack = pushStack(5, stack);
    stack = pushStack(8, stack);
    stack = pushStack(4, stack);
    stack = pushStack(1, stack);
    stack = pushStack(2, stack);

    printStack(stack);
    freeStack(stack);

    return 0;
}
