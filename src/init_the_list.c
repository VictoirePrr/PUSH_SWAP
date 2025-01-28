/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:49 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/28 16:24:30 by vicperri         ###   ########lyon.fr   */
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
/* Goal : add a new node at the head of the node.
To do so,
	I check if the stack is empty; I point the next and prev of the neuw node to itself.
Otherwise, I save my first node into a head variable.
I connect the prev of the new node to the tail of the stack,
I connect the next of the new node to the first node that initially existed,
I connect the next of the tail to the new_node,
I connect the prev of first node that initially existed to the new_node,
	making it the second node,
And I finally transform my new_node into the new head of my stack.*/

void	rot_lstadd_front(t_stack **stack, t_stack *new_node)
{
	t_stack	*head;

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
		head = *stack;
		new_node->prev = head->prev; // Connect `new_node->prev` to the tail
		new_node->next = head;       // Connect `new_node->next` to the head
		head->prev->next = new_node;
			// Connect the old tail's `next` to `new_node`
		head->prev = new_node;       // Connect the head's `prev` to `new_node`
		*stack = new_node;
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
	t_stack *new_node;

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