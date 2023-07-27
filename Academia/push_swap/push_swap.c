/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:01:36 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:08:19 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	sort_operations(int size, t_stack *stack_a, t_stack *stack_b,
		 t_stacks_info stacks)
{
	if (size == 5 || size == 4)
		sort_5_numbers(stack_a, stack_b, size);
	else if (size == 3)
		sort_3_size(stack_a, stack_a->numbers);
	else if (size == 2 && stack_a->numbers[0] > stack_a->numbers[1])
		swap(stack_a, 1);
	else if (size > 3)
		sort_stack_a(&stacks, 0);
}

int	main(int argc, const char *argv[])
{
	t_stacks_info	stacks;
	const int		size = argc - 1;

	stacks.sorted_a = 0;
	if (!init_stacks(&stacks.a, &stacks.b, size)
		|| !get_stack(size, &argv[1], stacks.a.numbers))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		if (!is_sort(stacks.a))
			sort_operations(size, &stacks.a, &stacks.b, stacks);
	}
	if (stacks.a.numbers)
		free(stacks.a.numbers);
	if (stacks.b.numbers)
		free(stacks.b.numbers);
	return (0);
}
