/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:53:16 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:00:44 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	pop(t_stack *stack)
{
	const int	number_on_top = stack->numbers[0];
	int			i;

	i = 0;
	if (stack->size > 0)
	{
		while (i < stack->size - 1)
		{
			stack->numbers[i] = stack->numbers[i + 1];
			i++;
		}
		stack->size--;
	}
	return (number_on_top);
}

void	push(t_stack *stack_final, t_stack *stack_origin, const int write_move)
{
	int	i;

	i = stack_final->size;
	while (i > 0)
	{
		stack_final->numbers[i] = stack_final->numbers[i - 1];
		i--;
	}
	stack_final->numbers[0] = pop(stack_origin);
	stack_final->size++;
	if (write_move)
	{
		if (stack_final->type == 0)
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
}

void	swap(t_stack *stack, const int write_move)
{
	int		aux;

	aux = stack->numbers[0];
	stack->numbers[0] = stack->numbers[1];
	stack->numbers[1] = aux;
	if (write_move)
	{
		if (stack->type == 0)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	rotate(t_stack *stack, const int write_move)
{
	const int	aux = stack->numbers[0];
	int			i;

	i = 0;
	if (stack->size > 1)
	{
		while (i < stack->size - 1)
		{
			stack->numbers[i] = stack->numbers[i + 1];
			i++;
		}
		stack->numbers[stack->size - 1] = aux;
	}
	if (write_move)
	{
		if (stack->type == 0)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_stack *stack, const int write_move)
{
	const int	aux = stack->numbers[stack->size - 1];
	int			i;

	i = stack->size - 1;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = aux;
	if (write_move)
	{
		if (stack->type == 0)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}
