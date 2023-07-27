/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:13:10 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:01:30 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pop_smallest_number(t_stack *stack_final, t_stack *stack_origin,
const int number_to_pop)
{
	int	i;

	i = 0;
	while (i < stack_origin->size)
	{
		if (stack_origin->numbers[i] == number_to_pop)
			break ;
		i++;
	}
	if (i > stack_origin->size - i)
	{
		while (i++ < stack_origin->size)
			reverse_rotate(stack_origin, 1);
	}
	else
	{
		while (i--)
			rotate(stack_origin, 1);
	}
	push(stack_final, stack_origin, 1);
}

void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b, const int size)
{
	pop_smallest_number(stack_b, stack_a,
		get_smallest_number(stack_a->numbers, stack_a->size));
	if (size == 5)
		pop_smallest_number(stack_b, stack_a,
			get_smallest_number(stack_a->numbers, stack_a->size));
	if (stack_a->size == 3)
		sort_3_size(stack_a, stack_a->numbers);
	else
		sort_top_3(stack_a, 3);
	push(stack_a, stack_b, 1);
	if (size == 5)
		push(stack_a, stack_b, 1);
}

void	sort_3_size(t_stack *stack, int *numbers)
{
	if (numbers[0] > numbers[1] && numbers[0] > numbers[2])
	{
		if (numbers[1] > numbers[2])
		{
			rotate(stack, 1);
			swap(stack, 1);
		}
		else
			rotate(stack, 1);
	}
	else if (numbers[0] < numbers[1] && numbers[0] < numbers[2]
		&& numbers[1] > numbers[2])
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	else if (numbers[0] > numbers[1] || numbers[0] > numbers[2])
	{
		if (numbers[1] > numbers[2])
			reverse_rotate(stack, 1);
		else
			swap(stack, 1);
	}
}

void	sort_top_3(t_stack *stack, int size)
{
	if (stack->numbers[0] > stack->numbers[1])
		swap(stack, 1);
	if (size == 2)
		return ;
	if (stack->numbers[0] < stack->numbers[1]
		&& stack->numbers[0] < stack->numbers[2]
		&& stack->numbers[2] > stack->numbers[0]
		&& stack->numbers[2] > stack->numbers[1])
		return ;
	rotate(stack, 1);
	swap(stack, 1);
	reverse_rotate(stack, 1);
	if (stack->numbers[0] > stack->numbers[1])
		swap(stack, 1);
}
