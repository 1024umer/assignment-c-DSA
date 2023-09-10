#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void add(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void deleteNode() {
    if (head == NULL) {
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
}

int get_trump() {
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;

    if (head == NULL) {
        return -1; 
    }

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    if (fast_ptr == NULL) {
       
        printf("The Trump is: %d %d\n", slow_ptr->data, slow_ptr->next->data);
    } else {
     
        printf("The Trump is: %d\n", slow_ptr->data);
    }
    return 0; 
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char command[10];
    int value;

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "ADD") == 0) {
            fscanf(file, "%d", &value);
            add(value);
        } else if (strcmp(command, "DELETE") == 0) {
            deleteNode();
        }
    }

    fclose(file);

    int trump = get_trump();
    printf(" result is: %d\n", trump); 

    return 0;
}


