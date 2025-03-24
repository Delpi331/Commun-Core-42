#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stddef.h>
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

int find_max(t_node* stack) {
    int max_value = stack->value;
    while (stack != NULL) {
        if (stack->value > max_value)
            max_value = stack->value;
        stack = stack->next;
    }
    return max_value;
}

int is_sorted(t_node* stack) {
    while (stack != NULL && stack->next != NULL) {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void move_all_to_b(t_node** stack_a, t_node** stack_b) {
    while (*stack_a != NULL)
        push_to(stack_a, stack_b, "pb");
}

void move_max_to_a(t_node** stack_a, t_node** stack_b) {
    int max_value = find_max(*stack_b);
    while ((*stack_b)->value != max_value)
        rotate(stack_b, "rb");
    push_to(stack_b, stack_a, "pa");
}

void sort_stack(t_node** stack_a, t_node** stack_b) {
    if (is_sorted(*stack_a))
        return;
    move_all_to_b(stack_a, stack_b);
    while (*stack_b != NULL)
        move_max_to_a(stack_a, stack_b);
}

int main(int argc, char* argv[]) {
    t_node* stack_a;
    t_node* stack_b;
    int i;
    int j;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    while (i < argc) {
        j = 0;
        while (argv[i][j]) {
            if (argv[i][j] == '-' && argv[i][j + 1] == '-')
                return (printError(0), 0);
            j++;
        }
        push(&stack_a, atoi(argv[i++]));
    }
    ft_printf("Pila A original: ");
    print_stack(stack_a);
    ft_printf("Aqui estan los sorting steps: ");
    sort_stack(&stack_a, &stack_b);
    ft_printf("\n");
    ft_printf("Pila A ordenada: ");
    print_stack(stack_a);
    while (stack_a != NULL)
        pop(&stack_a);
    while (stack_b != NULL)
        pop(&stack_b);
    return 0;
}