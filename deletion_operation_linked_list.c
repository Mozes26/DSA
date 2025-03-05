#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node with a given value
struct Node* deleteNode(struct Node* head, int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        head = temp->next;   // Changed head
        free(temp);          // Free old head
        return head;
    }

    // Search for the value to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not present in the linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return head;
    }

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory

    return head;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List: ");
    printList(head);

    int valueToDelete;
    printf("Enter the value to delete: ");
    scanf("%d", &valueToDelete);

    // Delete the node with the value entered by the user
    head = deleteNode(head, valueToDelete);
    printf("After deleting %d: ", valueToDelete);
    printList(head);

    return 0;
}
