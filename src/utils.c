/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:16 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/29 18:20:48 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

/* Goal : Removes the current node from a circular doubly linked list.
To do so I save my node into a variable node_to_remove.
If there is only one node in the stack, I set it to NULL.
Otherwise, I move the head of my stack to the second node,
I set the next of the last node to point to the second node,
and I set the prev of the second node to point to the last node.
*/
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
/* Pretty self explanatory */
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

int	check_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*check;

	temp = *stack;
	check = (*stack)->next;
	printf("check : %d\n", check->content);
	printf("temp : %d\n", temp->content);
	if (size_of_list(stack) == 2)
		return (SUCCESS);
	while (1)
	{
		printf("check : %d\n", check->content);
		printf("temp : %d\n", temp->content);
		if (temp->content == check->content)
			return (print_error(), ERROR);
		temp = temp->next;
		check = check->next;
		if (temp == *stack || check == (*stack)->next)
			break ;
	}
	return (SUCCESS);
}

// a supprimer avant de push
void	ft_print_list(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (1)
	{
		printf("c : %d || i : %d\n", temp->content, temp->index);
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}