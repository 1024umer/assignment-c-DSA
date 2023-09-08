#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* linkedList = NULL;
    int numElements;

    printf("Enter the number of elements: ");
    scanf("%d", &numElements);
	int i;
    for (i = 0; i < numElements; ++i) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&linkedList, value);
    }

    printf("Linked List: ");
    displayList(linkedList);

    struct Node* current = linkedList;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
