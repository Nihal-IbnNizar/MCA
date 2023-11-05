#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    struct Node* next;
}Node;

Node* head = NULL;

void insert(char name[100]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void deleteNode(char name[100]) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* temp;
    Node* current = head;
    if (strcmp(head->name, name) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        printf("%s has been deleted.\n", name);
        return;
    }

    Node* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%s not found in the linked list.\n", name);
        return;
    }

    temp = current;
    previous->next = current->next;
    free(temp);
    printf("%s has been deleted.\n", name);
}

void display() {
    Node* current = head;

    if (current == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list elements:\n");
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void sort() {
    Node *i, *j;
    char temp[100];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
    }

    printf("Linked list sorted in ascending order.\n");
}

void reverse() {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("Linked list reversed.\n");
}

int count() {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    int choice;
    char name[100];

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Sort\n");
        printf("5. Reverse\n");
        printf("6. Count\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Exiting the program.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter a name to insert: ");
                if (scanf("%s", name) != 1) {
                    printf("Invalid input. Please enter a valid name.\n");
                    break;
                }
                insert(name);
                break;
            case 2:
                printf("Enter a name to delete: ");
                if (scanf("%s", name) != 1) {
                    printf("Invalid input. Please enter a valid name.\n");
                    break;
                }
                deleteNode(name);
                break;
            case 3:
                display();
                break;
            case 4:
                sort();
                break;
            case 5:
                reverse();
                break;
            case 6:
                printf("Number of elements in the linked list: %d\n", count());
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
