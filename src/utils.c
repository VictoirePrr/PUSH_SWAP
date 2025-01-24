/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:16 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/24 16:02:55 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
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
int	size_of_list(t_stack **stack)
{
	t_stack	*temp;
	int		size;

	temp = *stack;
	size = 0;
	while (1)
	{
		temp = temp->next;
		size++;
		if (temp == *stack)
			break ;
	}
	return (size);
}

// a supprimer avant de push
void	ft_print_list(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (1)
	{
		printf("%d\n", temp->index);
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}