//
// Created by Admin on 09/07/2025.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node*next;
}Node;

Node*createNode(int data) {
    Node* node=(Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}
typedef struct {
    Node *head;
} Stack;
void initStack(Stack*s) {
    s -> head = NULL;
}

void push(Stack*s,int x) {
    Node* node = createNode(x);
    node -> next = s -> head;
    s -> head = node;
}

void printStack(Stack *s) {
    Node*current=s->head;
    while(current!=NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int top(Stack *s) {
    if (s->head==NULL) {
        printf("Ngan xep trong");
        return -1;
    }
    return s->head->data;
}

int main() {
    Stack s;
    initStack(&s);

    int arr[]={5,4,3,2,1};
    for (int i=0; i<5; i++) {
        push(&s,arr[i]);
    }
    printStack(&s);

    int x=top(&s);
    if (x!=-1) {
        printf("ptu tren dinh ngan xep: %d\n", x);
    }

    return 0;
}
