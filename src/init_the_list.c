/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:49 by vicperri          #+#    #+#             */
/*   Updated: 2025/02/04 13:49:17 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Same as rot_lstadd_front but the other way around.
My node will be added at the end of the list */
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
I check if the stack is empty;
I point the next and prev of the neuw node to itself.
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
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev->next = new_node;
		head->prev = new_node;
		*stack = new_node;
	}
}

/*Goal : init my node.
To do so, I malloc a stack and init the variables.
Next and prev will be equal to NULL for now.*/
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

/*Goal : Add a new node to my stack.
To do so, I first check the content of my node forlimits of int
Then I initialize my node and check if stack exists.
If so, I call a function that will add the node at the end of the list.
If not, I create my stack, which head will be my node. */
int	fill_and_check_the_list(long content, t_stack **stack)
{
	t_stack	*new_node;

	if (content > INT_MAX || content < INT_MIN)
		return (ERROR);
	new_node = stack_init((int)content);
	if (!new_node)
		return (ERROR);
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		rot_lstadd_back(stack, new_node);
		if (check_stack(stack) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
