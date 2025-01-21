/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:24 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/21 11:45:11 by vicperri         ###   ########lyon.fr   */
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
void	ft_swap(t_stack **stack, char c)
{
	int	temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	if (c != 'c')
		ft_printf("s%c\n", c);
	else
		ft_printf("ss\n");
}

void	push_into_stack(t_stack **src, t_stack **dst, char c)
{
	t_stack *swap_value;

	swap_value = *src;
	rm_node(src);
	if (!swap_value) // If rm_node removed the last node, skip adding
		return ;
	if (!*dst)
	{
		swap_value->next = swap_value;
		swap_value->prev = swap_value;
	}
	rot_lstadd_back(dst, swap_value);
	ft_printf("p%c\n", c);
}