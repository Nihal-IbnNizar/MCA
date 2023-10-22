#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];  
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

void insert(char e[100]) {
    struct node *t;
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        strcpy(head->data, e);
        head->next = head;
        head->prev = head;
    } else {
        t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = (struct node *)malloc(sizeof(struct node));
        strcpy(t->next->data, e);
        t->next->next = head;
        t->next->prev = t;
        head->prev = t->next;
    }
}

void disp() {
    struct node *t;
    if (head == NULL) {
        printf("\nCIRCULAR DOUBLY LINKED LIST IS EMPTY!!");
    } else {
        t = head;
        printf("\n");
        do {
            printf("%s\t", t->data);
            t = t->next;
        } while (t != head);
    }
}

void delete(char e[100]) {
    struct node *t;
    if (head == NULL) {
        printf("\nCIRCULAR DOUBLY LINKED LIST IS EMPTY!!");
    } else if (strcmp(head->data, e) == 0 && head->next == head) {
        head = NULL;
    } else if (strcmp(head->data, e) == 0) {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    } else {
        t = head->next;
        while (t != head && strcmp(t->data, e) != 0) {
            t = t->next;
        }
        if (t == head) {
            printf("\nELEMENT NOT FOUND!!");
        } else {
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
    }
}

int menu() {
    int ch;
    printf("\n---CIRCULAR DOUBLY LINKED LIST OPERATIONS---\n");
    printf("1-Insert\n2-Delete\n3-Display\n4-Exit\nENTER YOUR CHOICE: ");
    scanf("%d", &ch);

    return ch;
}

void process() {
    int ch;
    char e[100];
    for (ch = menu(); ch != 4; ch = menu()) {
        switch (ch) {
            case 1:
                printf("\nEnter the string to insert: ");
                scanf("%s", e);
                insert(e);
                break;
            case 2:
                printf("\nEnter the string to delete: ");
                scanf("%s", e);
                delete(e);
                break;
            case 3:
                disp();
                break;
            default:
                printf("\nWRONG CHOICE!!");
                break;
        }
    }
}

int main() {
    process();
    return 0;
}
