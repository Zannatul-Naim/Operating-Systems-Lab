#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}*top, *tail;

typedef struct Node node;

node * getNode() {
    return ((node*)malloc(sizeof(node)));
}

void push(int data) {
    node *temp = getNode();

    temp -> data = data;

    if(top == NULL) {
        top = temp;
        tail = temp;
        top -> next = NULL;
        tail->next = NULL;
        top -> prev = NULL;
        tail -> prev = top;
    }
    else {
        temp -> next = top;
        temp -> prev = NULL;
        top -> prev = top;
        top = temp;
    }
}

void pop() {
    if(top == NULL) printf("Satck is Underflow! Nothing to pop!\n");
    else {
        printf("poped : %d\n", top->data);
        top = top->next;
    }
}

void pop_back() {
    if(top == NULL) {
        printf("Satck is Underflow! Nothing to pop!\n");
    } else {
        printf("poped from back: %d\n", tail->data);
        tail = tail->prev;
    }
}

void display() {
    if(top == NULL) printf("Stack Underflow!\n");
    else {
        node *temp;
        temp = top;
        printf("Stack elements : ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void peek() {
    if(top == NULL) printf("Stack Underflow\n");
    else printf("top element : %d\n", top->data);
}

void peek_last() {
    printf("%d\n", tail->data);
}

int main() {

    for(int i = 1; i <= 3; i++) push(i);
    display();
    peek_last();
    pop_back();
    peek_last();
    // pop();
    // pop();
    // pop();
    // pop();
    // display();
    // push(10);
    // push(100);
    // push(1000);
    // push(10000);
    // display();
    // peek();
    return 0;
}