/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create Linked List
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate List
struct Node* rotateRight(struct Node* head, int k) {
    if(head == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    // Find length and last node
    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make circular
    temp->next = head;

    // Reduce k if greater than length
    k = k % length;

    int steps = length - k;
    temp = head;

    // Move to (n-k)th node
    for(int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;
    temp->next = NULL;

    return head;
}

int main() {
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    struct Node* head = createList(n);

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated Linked List: ");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}