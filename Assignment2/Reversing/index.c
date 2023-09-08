#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int transaction_id;
    int transaction_amount;
    struct node* next;
};

struct node* head = NULL;

void add(int transaction_id, int transaction_amount) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->transaction_id = transaction_id;
    new_node->transaction_amount = transaction_amount;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d,%d\n", temp->transaction_id, temp->transaction_amount);
        temp = temp->next;
    }
}

void delete_transaction(int transaction_id) {
    struct node* temp = head;
    struct node* prev = NULL;

    while (temp != NULL && temp->transaction_id != transaction_id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        free(temp);
    }
}

int main() {
    FILE* fp;
    int numberOfTransactions, numberOfFraudulentTransactions;
    int transaction_id, transaction_amount;
    int* fraudulent_transaction_ids;
    int i, j;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(fp, "%d %d", &numberOfTransactions, &numberOfFraudulentTransactions);

    fraudulent_transaction_ids = (int*)malloc(sizeof(int) * numberOfFraudulentTransactions);

    for (i = 0; i < numberOfTransactions; i++) {
        fscanf(fp, "%d,%d", &transaction_id, &transaction_amount); 
        add(transaction_id, transaction_amount);
    }

    for (j = 0; j < numberOfFraudulentTransactions; j++) {
        fscanf(fp, "%d", &fraudulent_transaction_ids[j]);
        delete_transaction(fraudulent_transaction_ids[j]);
    }

    print_list();

    fclose(fp);

    free(fraudulent_transaction_ids);

    return 0;
}

