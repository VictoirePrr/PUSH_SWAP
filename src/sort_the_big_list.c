/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_big_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:59:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/22 11:07:54 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_the_big_list(t_stack **stack_a, t_stack **stack_b)
{
	t_data	data;

	data.min = 0;
	data.index = 0;
	data.min_pos = 0;
	if (!*stack_a)
		return ;
	// while (size_of_list(stack_a) != 3)
	// {
	set_index(stack_a);
	search_sort_index(stack_a, &data);
	// while ((*stack_a)->content != data.min)
	// 	search_best_instruct(stack_a, &data);
	// push_into_stack(stack_a, stack_b, 'b');
	// }
	// if (size_of_list(stack_a) == 3)
	// 	sort_three(stack_a);
	// while (*stack_b)
	// 	push_into_stack(stack_b, stack_a, 'a');
}
