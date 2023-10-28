#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack data structure for operators
typedef struct
{
    char data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, char data)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    StackNode *node = stack->top;
    stack->top = node->next;
    char data = node->data;
    free(node);
    return data;
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->top->data;
}

int isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int infixToPostfix(char *infix, char *postfix)
{
    Stack *stack = createStack();
    int i, j;
    for (i = 0, j = -1; infix[i]; i++)
    {
        if (isOperand(infix[i]))
        {
            postfix[++j] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[++j] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
            {
                return -1; // Invalid expression
            }
            else
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
            {
                postfix[++j] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack))
    {
        postfix[++j] = pop(stack);
    }
    postfix[++j] = '\0';
    return 0; // Conversion successful
}

int evaluatePostfix(char *postfix)
{
    Stack *stack = createStack();
    int i;
    for (i = 0; postfix[i]; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(stack, postfix[i] - '0');
        }
        else if (postfix[i] != ' ')
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;
            switch (postfix[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                // Invalid operator
                return 0;
            }
            push(stack, result);
        }
    }
    return pop(stack);
}

int main()
{
    char infix[100];
    char postfix[100];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    if (infixToPostfix(infix, postfix) == 0)
    {
        printf("Postfix expression: %s\n", postfix);
        int result = evaluatePostfix(postfix);
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Invalid infix expression.\n");
    }

    return 0;
}

