#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 1. INSERTION: At the beginning
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

// 2. INSERTION: At the end
void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// 3. DELETION: Remove a node with a specific value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* curr = *head;

    // Search for the node to delete
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    if (curr == NULL) return; // Key not found

    // If node to be deleted is head node
    if (*head == curr) {
        *head = curr->next;
    }

    // Change next only if node to be deleted is NOT the last node
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }

    // Change prev only if node to be deleted is NOT the first node
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }

    free(curr);
}

// Helper function to print the list
void printList(struct Node* node) {
    printf("Forward:  ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtHead(&head, 5);      // List: 5 <-> 10 <-> 20
    insertAtTail(&head, 30);     // List: 5 <-> 10 <-> 20 <-> 30

    printf("Original List:\n");
    printList(head);

    printf("\nDeleting 20...\n");
    deleteNode(&head, 20);
    printList(head);

    return 0;
}