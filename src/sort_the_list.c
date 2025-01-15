/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/15 18:04:19 by vicperri         ###   ########lyon.fr   */
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

void	sort_the_list(t_stack **stack_a)
{
	int	min;

	if (!*stack_a)
		return ;
	while (*stack_a)
	{
		min = search_smallest(stack_a);
		while (min != (*stack_a)->content)
			rotate_next(stack_a, 'a');
		push_into_stack(stack_a, 'b');
	}
	*stack_a = (*stack_a)->next;
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

void	push_into_stack(t_stack **stack, char c)
{
	t_stack	*second_stack;
	t_stack	*swap_value;

	second_stack = NULL;
	swap_value = *stack;
	rm_node(stack);
	if (!second_stack)
	{
		swap_value->next = NULL;
		swap_value->prev = NULL;
	}
	rot_lstadd_back(second_stack, swap_value); // fill stack_b
	ft_printf("p%c\n", c);
}
