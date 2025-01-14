/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/14 16:03:18 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void update_stack_a(int min, t_stack **stack_a)
{
	t_stack *temp;

	temp = *stack_a;
	if (!*stack_a)
		return ;
	while (temp->next != *stack_a)
	{
		if (temp->content == min)
		{
			printf("ra\n");
			temp->prev = temp->next;
		}
	}
}

void	sort_the_list(t_stack **stack_a)
{
	t_stack *temp;
	t_stack *stack_b;
	int min;

	temp = *stack_a;
	min = temp->content;
	stack_b = NULL;
	if (!*stack_a)
		return ;
	printf("\n");
	printf("%d", min);
	while (1)
	{
		if (min > temp->next->content)
		{
			printf("min : %d", min);
			min = temp->next->content;
			update_stack_a(min, &stack_a);
			fill_the_list(min, &stack_b);
		}
		temp = temp->next;
		if (temp == *stack_a) // Stop when we loop back to the head
			break ;
	}
}