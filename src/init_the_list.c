/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:49 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/21 11:42:56 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = (*stack)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}

t_stack	*stack_init(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!(new_node))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	fill_the_list(int argv, t_stack **stack)
{
	t_stack	*new_node;

	new_node = stack_init(argv);
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
		rot_lstadd_back(stack, new_node);
}