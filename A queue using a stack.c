#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    unsigned capacity;
    int top;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

typedef struct {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(Queue* queue, int item) {
    push(queue->stack1, item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int peekQueue(Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    if (isEmpty(queue->stack2))
        return INT_MIN;
    return queue->stack2->array[queue->stack2->top];
}

void printQueue(Queue* queue) {
    int i;
    if (!isEmpty(queue->stack2)) {
        for (i = queue->stack2->top; i >= 0; i--) {
            printf("%d ", queue->stack2->array[i]);
        }
    }
    for (i = 0; i <= queue->stack1->top; i++) {
        printf("%d ", queue->stack1->array[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue(10);
    int choice, item;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item == INT_MIN)
                    printf("Queue is empty.\n");
                else
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                item = peekQueue(queue);
                if (item == INT_MIN)
                    printf("Queue is empty.\n");
                else
                    printf("Front item: %d\n", item);
                break;
            case 4:
                printQueue(queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
