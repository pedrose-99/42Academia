/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:13:21 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:01:26 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_rotate_b(t_stacks_info *stacks, int *group_size,
int *rotated_times)
{
	const int	pivot = get_median(stacks->b.numbers, 0, *group_size);
	int			i;

	i = *group_size;
	while (i > 0)
	{
		if (!move_biggest_number_to_a(
				stacks, group_size, rotated_times, &i))
		{
			if (stacks->b.numbers[0] >= pivot)
			{
				push(&stacks->a, &stacks->b, 1);
				(*group_size)--;
			}
			else
			{
				rotate(&stacks->b, 1);
				(*rotated_times)++;
			}
			i--;
		}
	}
}

static void	push_reverse_rotate_b(t_stacks_info *stacks, int *group_size,
int rotated_times)
{
	int	pivot;
	int	j;

	j = 0;
	pivot = get_median(stacks->b.numbers, stacks->b.size - *group_size,
			stacks->b.size);
	while (rotated_times > 0)
	{
		reverse_rotate(&stacks->b, 1);
		rotated_times--;
		j++;
		move_biggest_number_to_a(stacks, group_size, &rotated_times, &j);
		if (stacks->b.numbers[0] >= pivot)
		{
			push(&stacks->a, &stacks->b, 1);
			j--;
			(*group_size)--;
		}
	}
}

void	sort_stack_b(t_stacks_info *stacks, int group_size)
{
	int	rotated_times;

	rotated_times = 0;
	while (group_size > 0)
	{
		if (rotated_times > stacks->b.size - rotated_times)
		{
			while (rotated_times++ < stacks->b.size)
				rotate(&stacks->b, 1);
			rotated_times = 0;
		}
		if (rotated_times == 0)
			push_rotate_b(stacks, &group_size, &rotated_times);
		else
		{
			push_reverse_rotate_b(stacks, &group_size, rotated_times);
			rotated_times = 0;
		}
		sort_stack_a(stacks, 0);
	}
}
