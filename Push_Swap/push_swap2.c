#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf/ft_printf.h"

typedef struct s_node {
    int value;
    struct s_node* next;
} t_node;

void printError(int error) {
    if (error == 0)
        ft_printf("Error doble '-'");
    ft_printf("\n");
}

t_node* new_node(int value) {
    t_node* node = (t_node*)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void push(t_node** stack, int value) {
    t_node* node = new_node(value);
    if (!node)
        return;
    node->next = *stack;
    *stack = node;
}

int pop(t_node** stack) {
    if (*stack == NULL)
        return -1;
    t_node* temp = *stack;
    int value = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

void print_stack(t_node* stack) {
    while (stack != NULL) {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

void swap(t_node** stack, char* operation) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_node* first = *stack;
    t_node* second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    ft_printf("%s ", operation);
}

void push_to(t_node** from, t_node** to, char* operation) {
    if (*from == NULL)
        return;
    int value = pop(from);
    push(to, value);
    ft_printf("%s ", operation);
}

void rotate(t_node** stack, char* operation) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_node* first = *stack;
    *stack = first->next;
    first->next = NULL;
    t_node* last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    ft_printf("%s ", operation);
}

void reverse_rotate(t_node** stack, char* operation) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_node* last = *stack;
    t_node* prev = NULL;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    ft_printf("%s ", operation);
}

// Declaración de la función stack_size
int stack_size(t_node* stack) {
    int size = 0;
    while (stack != NULL) {
        size++;
        stack = stack->next;
    }
    return size;
}

int is_sorted(t_node* stack) {
    while (stack != NULL && stack->next != NULL) {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

// Función que particiona la pila en dos subpiles (menores y mayores que el pivote)
t_node* partition(t_node* stack, int pivot, t_node** left, t_node** right) {
    t_node* current = stack;
    while (current != NULL) {
        if (current->value < pivot) {
            push(left, current->value);
        } else if (current->value > pivot) {
            push(right, current->value);
        }
        current = current->next;
    }
    return stack;
}

// Función recursiva para ordenar usando QuickSort
void quick_sort_stack(t_node** stack) {
    if (*stack == NULL || (*stack)->next == NULL) {
        return; // La pila ya está ordenada o es un solo elemento
    }

    int pivot = (*stack)->value;
    t_node* left = NULL;
    t_node* right = NULL;
    *stack = partition(*stack, pivot, &left, &right); // Partición en subpiles

    // Recursión en las subpiles
    quick_sort_stack(&left); // Ordenamos la subpila izquierda
    quick_sort_stack(&right); // Ordenamos la subpila derecha

    // Colocamos los elementos de la subpila izquierda, pivote y subpila derecha de nuevo en la pila
    while (left != NULL) {
        push(stack, pop(&left));
    }

    push(stack, pivot); // Poner el pivote en la pila

    while (right != NULL) {
        push(stack, pop(&right));
    }
}

int main(int argc, char* argv[]) {
    t_node* stack_a = NULL;
    t_node* stack_b = NULL;
    int i;
    int j;

    i = 1;
    while (i < argc) {
        j = 0;
        while (argv[i][j]) {
            if (argv[i][j] == '-' && argv[i][j + 1] == '-')
                return (printError(0), 0);
            j++;
        }
        push(&stack_a, atoi(argv[i++])); // Insert elements into stack_a
    }
    
    ft_printf("Pila A original: ");
    print_stack(stack_a);
    ft_printf("Aqui estan los sorting steps: ");
    
    quick_sort_stack(&stack_a); // Apply quicksort
    
    ft_printf("\n");
    ft_printf("Pila A ordenada: ");
    print_stack(stack_a);
    
    while (stack_a != NULL)
        pop(&stack_a); // Clean up
    while (stack_b != NULL)
        pop(&stack_b); // Clean up
    
    return 0;
}