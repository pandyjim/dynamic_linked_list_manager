
//Developed by JIMIT PANDYA

//Developed a C program to manage various operations on Dynamic link list. 
//You could display the list, modify it as well as search within the database.




#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(Node *head, int data, int position) {
    Node *newNode = createNode(data);
    Node *current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node of the linked list
Node *deleteFirstNode(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
void deleteLastNode(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node *current = head;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
}

// Function to delete a node at a specific position in the linked list
void deleteAtPosition(Node *head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = head;
    Node *previous = NULL;
    for (int i = 1; i < position && current != NULL; i++) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }
    previous->next = current->next;
    free(current);
}

// Function to display the linked list
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to search for a key in the linked list
void search(Node *head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element found.\n");
            return;
        }
        current = current->next;
    }
    printf("Element not found.\n");
}

// Function to free the memory allocated for the linked list
void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    int choice, data, position, key;
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete first node\n5. Delete last node\n6. Delete at position\n");
        printf("7. Display\n8. Search\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFirstNode(head);
                break;
            case 5:
                deleteLastNode(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 9:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

