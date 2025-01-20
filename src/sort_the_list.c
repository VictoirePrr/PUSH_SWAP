/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/17 16:11:54 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_next(t_stack **stack, char c)
{
	if (*stack && *stack != (*stack)->next)
		*stack = (*stack)->next;
	if (c != 'c')
		ft_printf("r%c\n", c);
	else
		ft_printf("rr\n");
}

void	rotate_prev(t_stack **stack, char c)
{
	if (*stack && *stack != (*stack)->prev)
		*stack = (*stack)->prev;
	if (c != 'c')
		ft_printf("rr%c\n", c);
	else
		ft_printf("rrr\n");
}

void	sort_the_list(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (!*stack_a)
		return ;
	if ((*stack_a)->size == 3)
		sort_three(stack_a);
	else
	{
		while (*stack_a)
		{
			min = search_smallest(stack_a);
			while (min != (*stack_a)->content)
				rotate_next(stack_a, 'a');
			push_into_stack(stack_a, stack_b, 'b');
		}
		while (*stack_b)
			push_into_stack(stack_b, stack_a, 'a');
	}
}

int	search_smallest(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = temp->content;
	while (1)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (min);
}

void	push_into_stack(t_stack **src, t_stack **dst, char c)
{
	t_stack	*swap_value;

	swap_value = *src;
	rm_node(src);
	if (!*dst)
	{
		swap_value->next = swap_value;
		swap_value->prev = swap_value;
	}
	rot_lstadd_back(dst, swap_value);
	ft_printf("p%c\n", c);
}

// 5 possibilite
void	sort_three(t_stack **stack_a)
{
	int	head;
	int	middle;
	int	last;

	head = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	last = (*stack_a)->prev->content;
	while (1)
	{
		// 1 2 3
		if (head < middle && middle < last && last > head)
			break ;
		//  1 3 2
		if (head < middle && middle > last && last > head)
			rotate_prev(stack_a, 'a');
		// 2 3 1
		if (head < middle && middle > last && last < head)
			rotate_prev(stack_a, 'a');
		// 2 1 3
		if (head > middle && middle > last && last > head)
			rotate_next(stack_a, 'a');
		// 3 2 1
		if (head > middle && middle > last && last < head)
			rotate_next(stack_a, 'a');
		// 3 1 2
		if (head > middle && middle < last && last < head)
			rotate_next(stack_a, 'a');
	}
}
