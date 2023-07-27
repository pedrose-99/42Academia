/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_big_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:13:38 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:01:04 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_biggest_num(const int *numbers, const int start, const int end)
{
	int	biggest_num;
	int	i;

	i = start;
	biggest_num = numbers[start];
	while (i < end)
	{
		if (numbers[i] > biggest_num)
			biggest_num = numbers[i];
		i++;
	}
	return (biggest_num);
}

int	move_biggest_number(t_stacks_info *stacks, int *group_size,
int *rotated_times, int *i)
{
	const int	biggest_num = get_biggest_num(stacks->b.numbers, 0,
			stacks->b.size);

	if (biggest_num == stacks->b.numbers[stacks->b.size - 1]
		&& *rotated_times > 1)
	{
		(*rotated_times)--;
		(*i)++;
		reverse_rotate(&stacks->b, 1);
	}
	else if (biggest_num == stacks->b.numbers[1] && *i > 1)
		swap(&stacks->b, 1);
	else if (biggest_num == stacks->b.numbers[0] && *i > 0)
	{
		(*i)--;
		(*group_size)--;
		push(&stacks->a, &stacks->b, 1);
		stacks->sorted_a++;
	}
	else
		return (0);
	return (1);
}

int	can_insert_next_number(t_stacks_info *stacks, int group_size, int i)
{
	const int	smallest_number_a = get_smallest_number(stacks->a.numbers,
			stacks->a.size - stacks->sorted_a);
	const int	biggest_number_b_tail = get_biggest_num(stacks->b.numbers,
		stacks->b.size - i - 1, stacks->b.size);
	int			biggest_number_b;

	biggest_number_b = get_biggest_num(
			stacks->b.numbers, 0, group_size);
	if (biggest_number_b_tail > biggest_number_b)
		biggest_number_b = biggest_number_b_tail;
	return (biggest_number_b < smallest_number_a);
}

int	move_biggest_number_to_a(t_stacks_info *stacks, int *group_size,
int *rotated_times, int *i)
{
	int	done;

	done = 0;
	if (can_insert_next_number(stacks, *group_size, *rotated_times))
	{
		sort_stack_a(stacks, 0);
		while (*group_size > 0)
		{
			if (move_biggest_number(stacks, group_size, rotated_times, i))
				done = 1;
			else
				return (done);
		}
	}
	return (done);
}
