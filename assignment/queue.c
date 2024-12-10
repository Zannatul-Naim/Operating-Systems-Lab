#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct node *next;
};

typedef struct Node node;
node *front, *rear;

int isEmpty() {
    return (front == NULL);
}

 void insert(int data) {
    node *newNode;
    newNode = (node *) malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty()) front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
 }

void delete() {
    if(isEmpty()) printf("Queue is Underflow!\n");
    else {
        node *temp = front;
        front = front -> next;

        printf("deleted Element is : %d\n", temp->data);
        free(temp);
    }
}
 void display() {
    if(isEmpty()) printf("Queue is Empty\n");
    else {
        node *temp = front;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
 }

void peek() {
    printf("Peeked element is : %d\n", front->data);
}

int main() {
    
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    display();
    delete();
    delete();
    delete();
    display();
    delete();
    delete();
    display();

    return 0;
 }