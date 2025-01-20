/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/20 17:00:35 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_the_list(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (!*stack_a)
		return ;
	if (size_of_list(stack_a) == 3)
		sort_three(stack_a);
	else
	{
		while (size_of_list(stack_a) != 3)
		{
			search_smallest(stack_a);
			search_best_instruct(stack_a);
			push_into_stack(stack_a, stack_b, 'b');
		}
		if (size_of_list(stack_a) == 3)
			sort_three(stack_a);
		while (*stack_b)
			push_into_stack(stack_b, stack_a, 'a');
	}
}
void	search_smallest(t_stack **stack)
{
	t_node	*node;
	t_stack	*temp;

	temp = *stack;
	(*stack)->node.min = temp->content;
	(*stack)->node.pos = 0;
	while (1)
	{
		if (temp->content < (*stack)->node.min)
			(*stack)->node.min = temp->content;
		temp = temp->next;
		(*stack)->node.pos++;
		if (temp == *stack)
			break ;
	}
}

void	search_best_instruct(t_stack **stack)
{
	int	len;

	len = size_of_list(stack);
	while ((*stack)->content != (*stack)->node.min)
	{
		ft_print_list(stack);
		printf("min : %d\n", (*stack)->node.min);
		// if ((*stack)->node.pos > len / 2)
		// 	rotate_prev(stack, 'a');
		// else
		rotate_next(stack, 'a');
	}
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
