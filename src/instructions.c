/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:24 by vicperri          #+#    #+#             */
/*   Updated: 2025/02/04 13:47:51 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Goal : move my head at the end of the list.
To do so, I check if my head is not equal to
the next node (for the case of a list of 1 elements).
If not, I move my the next value to be my head*/
void	rotate_next(t_stack **stack, char c)
{
	if ((*stack)->next == *stack)
		return ;
	if (*stack && *stack != (*stack)->next)
		*stack = (*stack)->next;
	if (c != 'c')
		ft_printf("r%c\n", c);
}

/*Goal : move the last node at the head of the list.
same as rotate next but this time to the last node
will be my head. */
void	rotate_prev(t_stack **stack, char c)
{
	if ((*stack)->prev == *stack)
		return ;
	if (*stack && *stack != (*stack)->prev)
		*stack = (*stack)->prev;
	if (c != 'c')
		ft_printf("rr%c\n", c);
}

/* Goal : Swap the first two elements
To do so, I swap the values between the two nodes,
as well as the index. */
void	ft_swap(t_stack **stack, char c)
{
	int	head_content;
	int	head_index;

	head_content = (*stack)->content;
	head_index = (*stack)->index;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = head_content;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = head_index;
	if (c != 'c')
		ft_printf("s%c\n", c);
}

/* Goal : Push a node from a stack to another one.
To do so, I save my node in a swap_value variable.
I rm the node in the src stack.
I push the node into the dst stack */
void	push_into_stack(t_stack **src, t_stack **dst, char c)
{
	t_stack	*swap_value;

	swap_value = *src;
	rm_node(src);
	if (!swap_value)
		return ;
	rot_lstadd_front(dst, swap_value);
	ft_printf("p%c\n", c);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != *stack)
	{
		if (temp->content > temp->next->content)
			return (ERROR);
		temp = temp->next;
	}
	return (SUCCESS);
}
