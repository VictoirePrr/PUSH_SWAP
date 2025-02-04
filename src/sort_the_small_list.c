/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_small_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:05:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/02/04 13:48:27 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Goal : sort lists smaller or equal to 12 numbers.
To do so, I traverse my stack until it equals to only 3 numbers :
1. I sort the lists of 3 numbers.
2. I push my smallest node to stack B until I only have 3 numbers.
3. I sort the last 3 numbers
4. I push from stack B to stack A until it is empty*/
void	sort_the_small_list(t_stack **stack_a, t_stack **stack_b)
{
	t_data	data;

	data.min = 0;
	data.min_pos = 0;
	if (!*stack_a)
		return ;
	if (size_of_list(stack_a) == 3)
		sort_three(stack_a);
	else
	{
		while (size_of_list(stack_a) != 3)
		{
			search_smallest_small_list(stack_a, &data);
			while ((*stack_a)->content != data.min)
				search_best_instruct(stack_a, &data);
			push_into_stack(stack_a, stack_b, 'b');
		}
		if (size_of_list(stack_a) == 3)
			sort_three(stack_a);
		while (*stack_b)
			push_into_stack(stack_b, stack_a, 'a');
	}
}

/*Goal : search for the smallest num in my list.
To do so, I interate through my stack with temp and compare the content of
my nodes to data->min which is first equal to the MAX INT.
If my temp is smaller than data->min, data->min will now be equal to temp.
I also take advantage of this iteration to retrive
the position of the smallest node.*/
void	search_smallest_small_list(t_stack **stack, t_data *data)
{
	t_stack	*temp;
	int		len;

	temp = *stack;
	data->min = INT_MAX;
	len = 0;
	while (1)
	{
		if (temp->content < data->min)
		{
			data->min = temp->content;
			data->min_pos = len;
		}
		len++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}

/* Goal : search for the best instruction to sort the stack.
To do so, I divide by 2 my list. If the position of the node
that I want to move is bigger than the division; it will take
less mouvements to move it down. */
void	search_best_instruct(t_stack **stack, t_data *data)
{
	int	len;

	len = size_of_list(stack);
	if (data->min_pos > len / 2)
		rotate_prev(stack, 'a');
	else
		rotate_next(stack, 'a');
}

/* Goal : sort the old fashioned way 3 numbers.
To do so, I compare them and choose the best function
to sort them with the minimum of mouvements.*/
void	sort_three(t_stack **stack_a)
{
	int	head;
	int	middle;
	int	last;

	while (1)
	{
		head = (*stack_a)->content;
		middle = (*stack_a)->next->content;
		last = (*stack_a)->prev->content;
		if (head < middle && middle < last && last > head)
			break ;
		else if (head < middle && middle > last && last > head)
			rotate_prev(stack_a, 'a');
		else if (head < middle && middle > last && last < head)
			rotate_prev(stack_a, 'a');
		else if (head > middle && middle < last && last > head)
			ft_swap(stack_a, 'a');
		else if (head > middle && middle > last && last < head)
			ft_swap(stack_a, 'a');
		else if (head > middle && middle < last && last < head)
			rotate_next(stack_a, 'a');
	}
}
