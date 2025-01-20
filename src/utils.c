/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:16 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/17 16:08:15 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

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

t_stack	*stack_init(int content, int argc)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!(new_node))
		return (NULL);
	new_node->content = content;
	new_node->size = argc - 1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	fill_the_list(int argv, int argc, t_stack **stack)
{
	t_stack	*new_node;

	new_node = stack_init(argv, argc);
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

// Removes the current node from a circular doubly linked list.
// If the list becomes empty, sets the stack to NULL.
void	rm_node(t_stack **stack)
{
	t_stack	*node_to_remove;

	if (!*stack)
		return ;
	node_to_remove = *stack;
	// If removing the only element in the stack
	if (node_to_remove->next == node_to_remove)
		*stack = NULL;
	else
	{
		node_to_remove->prev->next = node_to_remove->next;
		node_to_remove->next->prev = node_to_remove->prev;
		*stack = node_to_remove->next;
	}
}
