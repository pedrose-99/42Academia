/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:12:58 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:01:23 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_rotate_a(t_stacks_info *stacks, int *rotated_times)
{
	const int	pivot = get_median(
		stacks->a.numbers, 0, stacks->a.size - stacks->sorted_a);
	int			pushed_times;

	pushed_times = 0;
	while (*rotated_times < stacks->a.size - stacks->sorted_a)
	{
		if (stacks->a.numbers[0] <= pivot)
		{
			push(&stacks->b, &stacks->a, 1);
			pushed_times++;
		}
		else
		{
			rotate(&stacks->a, 1);
			(*rotated_times)++;
		}
	}
	return (pushed_times);
}

static int	push_reverse_rotate_a(t_stacks_info *stacks,
int rotated_times)
{
	const int	pivot = get_median(
		stacks->a.numbers, stacks->sorted_a, stacks->a.size);
	int			pushed_times;

	pushed_times = 0;
	if (stack_is_overrotated(&stacks->a, rotated_times))
		return (0);
	while (rotated_times > 0)
	{
		reverse_rotate(&stacks->a, 1);
		rotated_times--;
		if (stacks->a.numbers[0] <= pivot)
		{
			push(&stacks->b, &stacks->a, 1);
			pushed_times++;
		}
	}
	return (pushed_times);
}

void	sort_stack_a(t_stacks_info *stacks, int rotated_times)
{
	int	pushed_times;

	pushed_times = 0;
	if (stacks->a.size - stacks->sorted_a > 3 || rotated_times)
	{
		if (rotated_times == 0)
			pushed_times = push_rotate_a(stacks, &rotated_times);
		else
		{
			pushed_times = push_reverse_rotate_a(stacks, rotated_times);
			rotated_times = 0;
		}
	}
	if ((stacks->a.size - stacks->sorted_a > 3) || rotated_times)
		sort_stack_a(stacks, rotated_times);
	else
	{
		sort_top_3(&stacks->a,
			stacks->a.size - stacks->sorted_a);
		stacks->sorted_a += stacks->a.size - stacks->sorted_a;
	}
	if (pushed_times > 0)
		sort_stack_b(stacks, pushed_times);
}
