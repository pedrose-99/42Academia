/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:06:01 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:01:44 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_sort(const t_stack stack)
{
	int		i;

	i = 1;
	if (stack.size > 1)
	{
		while (i < stack.size)
		{
			if (stack.numbers[i] < stack.numbers[i - 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	init_stacks(t_stack *stack_a, t_stack *stack_b, const int size)
{
	stack_a->numbers = (int *)malloc(size * sizeof(int));
	stack_b->numbers = (int *)malloc(size * sizeof(int));
	if (!stack_a->numbers || !stack_b->numbers)
		return (0);
	stack_a->size = size;
	stack_b->size = 0;
	stack_a->type = 0;
	stack_b->type = 1;
	return (1);
}

int	get_median(const int *numbers, const int start, const int end)
{
	const int	mean_num_of_swaps = ((end - start) / 2);
	int			swaps;
	int			index;
	int			median;
	int			i;

	index = start;
	swaps = 0;
	median = numbers[index];
	while (swaps != mean_num_of_swaps)
	{
		median = numbers[index++];
		swaps = 0;
		i = start;
		while (i < end)
		{
			if (numbers[i++] <= median)
				swaps++;
		}
		swaps = end - start - swaps;
		if (swaps < 0)
			swaps *= -1;
	}
	return (median);
}

int	stack_is_overrotated(t_stack *stack, int rotated_times)
{
	if (rotated_times > stack->size - rotated_times)
	{
		while (rotated_times++ < stack->size)
			rotate(stack, 1);
		return (1);
	}
	else
		return (0);
}

int	get_smallest_number(const int *numbers, const int size)
{
	int	num;
	int	i;

	i = 0;
	num = numbers[0];
	while (i < size)
	{
		if (numbers[i] < num)
			num = numbers[i];
		i++;
	}
	return (num);
}
