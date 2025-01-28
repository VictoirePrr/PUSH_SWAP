/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:24 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/28 16:27:05 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_next(t_stack **stack, char c)
{
	if ((*stack)->next == *stack)
		return ;
	if (*stack && *stack != (*stack)->next)
		*stack = (*stack)->next;
	if (c != 'c')
		ft_printf("r%c\n", c);
	else
		ft_printf("rr\n");
}

void	rotate_prev(t_stack **stack, char c)
{
	if ((*stack)->prev == *stack)
		return ;
	if (*stack && *stack != (*stack)->prev)
		*stack = (*stack)->prev;
	if (c != 'c')
		ft_printf("rr%c\n", c);
	else
		ft_printf("rrr\n");
}
/* Goal : Swap the first two elements 
*/
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
	else
		ft_printf("ss\n");
}
/* Goal : Push a node from a stack to another one.
To do so, I save my node in a swap_value variable.
I rm the node in the src stack.
I push the node into the dst stack */
void	push_into_stack(t_stack **src, t_stack **dst, char c)
{
	t_stack *swap_value;

	swap_value = *src;
	rm_node(src);
	if (!swap_value)
		return ;
	rot_lstadd_front(dst, swap_value);
	ft_printf("p%c\n", c);
}