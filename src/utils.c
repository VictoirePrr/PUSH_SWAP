/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:16 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/14 16:58:50 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

void	rot_lstadd_back(t_stack *stack, t_stack *new)
{
	t_stack	*head;
	t_stack	*last;

	head = stack;
	last = stack;
	if (!(new))
		return ;
	if (!(stack))
	{
		head = stack;
		head->next = stack;
		head->prev = stack;
	}
	head = stack;
	last = head->prev;
	new->prev = last;
	new->next = stack;
	last->next = new;
	head->prev = new; // Start at the head of the list
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
nnnn arrive dans la troupe.last = head->prev;
nnnn->prev = last;
nnnn->next = head;
last->next = nnnn;
head->prev = nnnn;