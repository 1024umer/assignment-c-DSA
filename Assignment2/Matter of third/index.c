#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *find_third_last(struct Node *head) {
  if (head == NULL || head->next == NULL || head->next->next == NULL) {
    return NULL;
  }

  struct Node *current = head;

  while (current->next->next->next != NULL) {
    current = current->next;
  }

  return current;
}

void add_node(struct Node **head, int data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    struct Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  int data;
  struct Node *head = NULL;

  while (fscanf(fp, "%d", &data) != EOF) {
    add_node(&head, data);
  }

  struct Node *third_last_element = find_third_last(head);

  if (third_last_element == NULL) {
    printf("The linked list is too short\n");
  } else {
    printf("The third last element of the input.txt file is %d\n", third_last_element->data);
  }

  return 0;
}
