#include <stdio.h>
#include <stdlib.h>

// Определение структуры для элемента стека
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Определение структуры для стека
typedef struct {
    Node* top;
} Stack;

// Функция для создания пустого стека
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Функция для проверки, пуст ли стек
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Функция для добавления элемента в стек (положить на вершину стека)
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Функция для удаления элемента с вершины стека и возврата его значения
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст!\n");
        exit(EXIT_FAILURE);
    }
    Node* topNode = stack->top;
    int data = topNode->data;
    stack->top = topNode->next;
    free(topNode);
    return data;
}

// Функция для получения значения элемента с вершины стека без его удаления
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст!\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Освобождение памяти, занимаемой стеком
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Вершина стека: %d\n", peek(stack));

    printf("Извлеченные элементы из стека: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    freeStack(stack);

    return 0;
}
