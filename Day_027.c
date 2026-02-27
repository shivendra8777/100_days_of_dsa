/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create linked list
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

// Get length of list
int getLength(struct Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2) {
        while(diff--) head1 = head1->next;
    } else {
        while(diff--) head2 = head2->next;
    }

    // Traverse both together
    while(head1 != NULL && head2 != NULL) {
        if(head1 == head2)   // compare address
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;  // No intersection
}

int main() {
    int n, m;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list:\n");
    struct Node* head1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list:\n");
    struct Node* head2 = createList(m);

    // For demonstration purpose only:
    // Manually connect second list to first list at value 30
    struct Node* temp1 = head1;
    while(temp1 != NULL && temp1->data != 30)
        temp1 = temp1->next;

    struct Node* temp2 = head2;
    while(temp2->next != NULL)
        temp2 = temp2->next;

    if(temp1 != NULL)
        temp2->next = temp1;   // create intersection

    int result = findIntersection(head1, head2);

    if(result != -1)
        printf("Intersection Point: %d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}