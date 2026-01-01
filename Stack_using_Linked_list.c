#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Push operation */
void push(int x) {
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = top;
    top = new;
}

/* Pop operation */
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

/* Display stack */
void display() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack Empty\n");
        return;
    }
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
