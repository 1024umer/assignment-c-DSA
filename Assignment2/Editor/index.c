#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 5

struct Node {
  int data;
  struct Node *next;
};

struct Stack {
  struct Node *top;
  int size;
};

void push(struct Stack *stack, int data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

int pop(struct Stack *stack) {
  if (stack->size == 0) {
    return -1;
  }

  int data = stack->top->data;
  struct Node *top_node = stack->top;
  stack->top = stack->top->next;
  free(top_node);
  stack->size--;

  return data;
}

void print_list(struct Node *head) {
  struct Node *current = head;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}


void add_number(struct Node **head, int number) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = number;
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


void delete_tail(struct Node **head) {
  if (*head == NULL) {
    return;
  } else if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
  } else {
    struct Node *current = *head;
    while (current->next->next != NULL) {
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
  }
}


void add_index(struct Node **head, int index, int number) {
  if (index < 0) {
    return;
  }

  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = number;

  if (index == 0) {
    new_node->next = *head;
    *head = new_node;
  } else {
    struct Node *current = *head;
    int i;
    for (i = 0; i < index - 1 && current != NULL; i++) {
      current = current->next;
    }

    if (current == NULL) {
      return; 
    }

    new_node->next = current->next;
    current->next = new_node;
  }
}


void delete_index(struct Node **head, int index) {
  if (*head == NULL || index < 0) {
    return;
  }

  if (index == 0) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
  } else {
    struct Node *current = *head;
    int i;
    for (i = 0; i < index - 1 && current->next != NULL; i++) {
      current = current->next;
    }

    if (current->next == NULL) {
      return; 
    }

    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
  }
}



void move_forward(struct Node **head, int steps) {
    if (*head == NULL || steps < 0) {
        return;
    }

    struct Node *current = *head;
    int i;
    for (i = 0; i < steps && current != NULL; i++) {
        current = current->next;
    }
    *head = current;
}

void move_backward(struct Node **head, int steps) {
    if (*head == NULL || steps < 0) {
        return;
    }

    struct Node *current = *head;
    int i;
    for (i = 0; i < steps && current != NULL; i++) {
        current = current->next;
    }
    *head = current;
}


void add_immediate(struct Node **head, int number) {
  if (*head == NULL) {
    return;
  }

  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = number;
  new_node->next = (*head)->next;
  (*head)->next = new_node;
}

void delete_immediate(struct Node **head) {
  if (*head == NULL || (*head)->next == NULL) {
    return;
  }

  struct Node *temp = (*head)->next;
  (*head)->next = temp->next;
  free(temp);
}

void update_index(struct Node **head, int index, int number) {
  if (*head == NULL || index < 0) {
    return;
  }

  struct Node *current = *head;
  int i;
  for (i = 0; i < index && current != NULL; i++) {
    current = current->next;
  }

  if (current != NULL) {
    current->data = number;
  }
}


void update_immediate(struct Node **head, int number) {
  if (*head == NULL) {
    return;
  }

  (*head)->data = number;
}


void shift(struct Node **head, int index) {
  if (*head == NULL || index < 0) {
    return;
  }

  struct Node *current = *head;
  int i;
  for (i = 0; i < index && current != NULL; i++) {
    current = current->next;
  }

  if (current != NULL && current->next != NULL) {
    int temp = current->data;
    current->data = current->next->data;
    current->next->data = temp;
  }
}

int main() {
  struct Node *head = NULL;
  struct Stack stack;
  stack.top = NULL;
  stack.size = 0;

  
FILE *fp = fopen("input.txt", "r");
if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
} else {
    printf("File opened successfully\n");
}

  int operation, undo_index, undo_number; 
  char line[100];
while (fgets(line, sizeof(line), fp)) {
    printf("Read line: %s", line); 
    int command, index, number;
    sscanf(line, "%d %d %d", &command, &index, &number);

    switch (command) {
      case 1: 
        operation = pop(&stack);
        push(&stack, 1); 
        add_number(&head, number);
        break;
      case 2: 
        operation = pop(&stack);
        push(&stack, 2); 
        delete_tail(&head);
        break;
      case 3: 
        push(&stack, 3); 
        add_index(&head, index, number);
        break;
      case 4: 
        push(&stack, 4); 
        delete_index(&head, index);
        break;
      case 5: 
        push(&stack, 5); 
        move_forward(&head, index);
        break;
      case 6: 
        push(&stack, 6); 
        move_backward(&head, index);
        break;
      case 7: 
        push(&stack, 7); 
        add_immediate(&head, number);
        break;
      case 8: 
        push(&stack, 8); 
        delete_immediate(&head);
        break;
      case 9: 
        print_list(head);
        break;
      case 10: 
        push(&stack, 10); 
        update_index(&head, index, number);
        break;
      case 11: 
        push(&stack, 11); 
        update_immediate(&head, number);
        break;
      case 12: 
        push(&stack, 12); 
        shift(&head, index);
        break;
      case 13: 
        
        switch (operation) {
          case 1:
            delete_tail(&head);
            break;
          case 2:
            add_number(&head, undo_number);
            break;
          case 3:
            delete_index(&head, undo_index);
            break;
          case 4:
            add_index(&head, undo_index, undo_number);
            break;
          case 5:
            move_forward(&head, undo_index);
            break;
          case 6:
            move_backward(&head, undo_index);
            break;
          case 7:
            delete_immediate(&head);
            break;
          case 8:
            add_immediate(&head, undo_number);
            break;
          case 9:
            
            break;
          case 10:
            update_index(&head, undo_index, undo_number);
            break;
          case 11:
            update_immediate(&head, undo_number);
            break;
          case 12:
            shift(&head, undo_index);
            break;
        }
        break;
    }
  }

  fclose(fp);

  
  struct Node *current = head;
  while (current != NULL) {
    struct Node *temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}
