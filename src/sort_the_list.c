/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/16 16:22:42 by vicperri         ###   ########lyon.fr   */
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
		ft_printf("rrr\n");
}

void	sort_the_list(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	if (!*stack_a)
		return ;
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
