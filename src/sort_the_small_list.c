/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_small_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/22 10:27:17 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_the_small_list(t_stack **stack_a, t_stack **stack_b)
{
	t_data	data;

	data.min = 0;
	data.min_pos = 0;
	if (!*stack_a)
		return ;
	if (size_of_list(stack_a) == 3)
		sort_three(stack_a);
	else
	{
		while (size_of_list(stack_a) != 3)
		{
			search_smallest_small_list(stack_a, &data);
			while ((*stack_a)->content != data.min)
				search_best_instruct(stack_a, &data);
			push_into_stack(stack_a, stack_b, 'b');
		}
		if (size_of_list(stack_a) == 3)
			sort_three(stack_a);
		while (*stack_b)
			push_into_stack(stack_b, stack_a, 'a');
	}
}
void	search_smallest_small_list(t_stack **stack, t_data *data)
{
	t_stack	*temp;
	int		len;

	temp = *stack;
	data->min = temp->content;
	len = 0;
	while (1)
	{
		if (temp->content < data->min)
		{
			data->min = temp->content;
			data->min_pos = len;
		}
		len++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}

void	search_best_instruct(t_stack **stack, t_data *data)
{
	int	len;

	len = size_of_list(stack);
	if (data->min_pos > len / 2)
		rotate_prev(stack, 'a');
	else
		rotate_next(stack, 'a');
}

// 5 possibilite
void	sort_three(t_stack **stack_a)
{
	int	head;
	int	middle;
	int	last;

	while (1)
	{
		head = (*stack_a)->content;
		middle = (*stack_a)->next->content;
		last = (*stack_a)->prev->content;
		if (head < middle && middle < last && last > head)
			break ;
		else if (head < middle && middle > last && last > head)
			rotate_prev(stack_a, 'a');
		else if (head < middle && middle > last && last < head)
			rotate_prev(stack_a, 'a');
		else if (head > middle && middle < last && last > head)
			ft_swap(stack_a, 'a');
		else if (head > middle && middle > last && last < head)
			ft_swap(stack_a, 'a');
		else if (head > middle && middle < last && last < head)
			rotate_next(stack_a, 'a');
	}
}
