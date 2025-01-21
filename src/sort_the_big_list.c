/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_big_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:59:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/21 15:41:33 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_the_big_list(t_stack **stack_a, t_stack **stack_b)
{
	t_data data;
    t_stack *temp;

	data.min = 0;
	data.min_pos = 0;
    temp = stack_a;
	if (!*stack_a)
		return ;
	while (size_of_list(stack_a) != 3)
	{
        search_sort_index(stack_a, temp, &data);
		// search_smallest(stack_a, &data);
		// while ((*stack_a)->content != data.min)
		// 	search_best_instruct(stack_a, &data);
		// push_into_stack(stack_a, stack_b, 'b');
	}
	if (size_of_list(stack_a) == 3)
		sort_three(stack_a);
	while (*stack_b)
		push_into_stack(stack_b, stack_a, 'a');
}

