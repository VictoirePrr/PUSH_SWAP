/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:16 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/15 17:56:29 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

void	rot_lstadd_back(t_stack *stack, t_stack *new)
{
	t_stack	*last;

	if (!(new))
		return ;
	if (!(stack))
	{
		stack = new;
		new->next = stack;
		new->prev = stack;
	}
	else
	{
		last = stack->prev;
		new->prev = last;
		new->next = stack;
		last->next = new;
		stack->prev = new;
	} // Start at the head of the list
		// Link the new node back to the head
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
	printf("%d\n", new_node->content);
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
	}
	else
		rot_lstadd_back(*stack, new_node);
}

void	rm_node(t_stack **stack)
{
	t_stack *last;
	if ((*stack)->next == *stack)
		*stack = NULL; // update stack_a if only one node
	else
	{ // update stack_a if multiple node
		last = (*stack)->prev;
		*stack = (*stack)->next;
		(*stack)->prev = last;
		last->next = *stack;
	}
}