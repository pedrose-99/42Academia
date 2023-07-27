/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <pserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:13:32 by pserrano          #+#    #+#             */
/*   Updated: 2021/09/28 16:03:54 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int			size;
	int			*numbers;
	int			type;
}				t_stack;

typedef struct s_stacks_info
{
	t_stack		a;
	t_stack		b;
	int			sorted_a;
}		t_stacks_info;

void	push(t_stack *stack_final, t_stack *stack_origin,
			const int write_move);
void	swap(t_stack *stack, const int write_move);
void	rotate(t_stack *stack, const int write_move);
void	reverse_rotate(t_stack *stack, const int write_move);
int		is_sort(t_stack stack);
int		init_stacks(t_stack *stack_a, t_stack *stack_b, const int size);
int		get_median(const int *numbers, const int start, const int end);
int		stack_is_overrotated(t_stack *stack, int rotated_times);
int		get_smallest_number(const int *numbers, const int size);
void	sort_top_3(t_stack *stack, int size);
void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b, int size);
void	sort_3_size(t_stack *stack, int *numbers);
int		get_stack(const int size, const char **argv, int *stack_a);
void	sort_stack_b(t_stacks_info *stacks, int group_size);
void	sort_stack_a(t_stacks_info *stacks, int rotated_times);
int		move_biggest_number_to_a(t_stacks_info *stacks, int *group_size,
			int *rotated_times, int *i);
int		ft_strlen(char *s);
#endif
