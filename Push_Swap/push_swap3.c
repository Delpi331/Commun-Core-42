#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
}	t_stack;

void sa(t_stack *stack)
{
    if (stack->size > 1)
    {
        int temp = stack->arr[0];
        stack->arr[0] = stack->arr[1];
        stack->arr[1] = temp;
    }
}

void pb(t_stack *a, t_stack *b)
{
    if (a->size > 0)
    {
        // Desplazar elementos de A a B
        int temp = a->arr[0];
        for (int i = 0; i < a->size - 1; i++)
            a->arr[i] = a->arr[i + 1];
        
        // Insertar el valor de A en B
        for (int i = b->size; i > 0; i--)
            b->arr[i] = b->arr[i - 1];
        
        b->arr[0] = temp;
        a->size--;
        b->size++;
    }
}
void ra(t_stack *a)
{
    if (a->size > 1)
    {
        int temp = a->arr[0];
        for (int i = 0; i < a->size - 1; i++)
            a->arr[i] = a->arr[i + 1];
        
        a->arr[a->size - 1] = temp;
    }
}
void pa(t_stack *a, t_stack *b)
{
    if (b->size > 0)
    {
        // Desplazar elementos de B a A
        int temp = b->arr[0];
        for (int i = 0; i < b->size - 1; i++)
            b->arr[i] = b->arr[i + 1];
        
        // Insertar el valor de B en A
        for (int i = a->size; i > 0; i--)
            a->arr[i] = a->arr[i - 1];
        
        a->arr[0] = temp;
        b->size--;
        a->size++;
    }
}

int has_smaller(t_stack *stack, int pivot)
{
    for (int i = 0; i < stack->size; i++)
    {
        if (stack->arr[i] < pivot)
            return 1;  // Hay un valor menor que el pivote
    }
    return 0;  // No hay valores menores
}

int get_pivot(t_stack *stack, int size) {
    // Pivote aleatorio entre el primer, el medio y el último valor
    int middle = size / 2;
    int first = stack->arr[0];
    int mid = stack->arr[middle];
    int last = stack->arr[size - 1];

    // Seleccionar el pivote aleatorio entre estos tres valores
    int pivot = first;
    if ((mid > first && mid < last) || (mid < first && mid > last)) pivot = mid;
    else if ((last > first && last < mid) || (last < first && last > mid)) pivot = last;
    return pivot;
}
int is_sorted(t_stack *stack)
{
    for (int i = 0; i < stack->size - 1; i++)
    {
        if (stack->arr[i] > stack->arr[i + 1])
            return 0;  // No está ordenada
    }
    return 1;  // Está ordenada
}
void	print_stack(t_stack *stack, char *name)
{
	int	i;

	ft_printf("%s: ", name);
	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d ", stack->arr[i]);
		i++;
	}
	ft_printf("\n");
}

void	swap_if_needed(t_stack *stack)
{
	if (stack->size > 1 && stack->arr[0] > stack->arr[1])
	{
		sa(stack);
		ft_printf("sa\n");
	}
}

int partition(t_stack *a, t_stack *b, int pivot) {
    int i = 0;
    int j = a->size - 1;

    // Mientras los punteros no se crucen
    while (i <= j) {
        // Buscar el primer elemento mayor o igual al pivote
        while (i <= j && a->arr[i] < pivot) {
            pb(a, b);  // Mover el elemento menor que el pivote a la pila B
            ft_printf("pb\n");
            i++;  // Mover el puntero hacia adelante
        }

        // Buscar el primer elemento menor que el pivote
        while (i <= j && a->arr[j] >= pivot) {
            j--;  // Mover el puntero hacia atrás
        }

        // Si los punteros no se han cruzado, intercambiamos
        if (i < j) {
            int temp = a->arr[i];
            a->arr[i] = a->arr[j];
            a->arr[j] = temp;
            i++;
            j--;
        }
    }

    return i;  // Esta es la nueva división, donde todo lo menor al pivote está a la izquierda
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	count;

	if (size <= 1)
		return ;
	if (size == 2)
		return (swap_if_needed(a));
	pivot = get_pivot(a, size);
	count = partition(a, b, pivot);
	quick_sort(a, b, size - count);
	while (count--)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	quick_sort(a, b, a->size);
	print_stack(a, "A");
}