/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_big_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:59:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/31 13:57:56 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Goal : sort lists bigger than 12 numbers.
To do so, I trvaerse my stack until it equals to only 3 numbers :
1. I set each nodes to an index of -1.
2. I set each nodes to their sorted index.
3. Compute my chunk
4. Start the korean algo to push into stack b
5. Push stack B into stack A*/
void	sort_the_big_list(t_stack **stack_a, t_stack **stack_b)
{
	t_data	data;
	int		size_a;

	data.index = 0;
	data.chunk_size = 0;
	size_a = size_of_list(stack_a);
	if (!*stack_a)
		return ;
	set_index(stack_a);
	search_sort_index(stack_a, &data);
	compute_chunks(stack_a, &data);
	korean_algo(stack_a, stack_b, &data);
	if (size_of_list(stack_a) == 3)
		sort_three(stack_a);
	push_b_in_a_korean_way(stack_a, stack_b, size_a, &data);
}

/*Goal : push into stack_b my nodes depending on
their index so that I can do a first sort between them.
To do so : until my stack_a is equal to three,
I will push into stack_b each node's index that corresponds to
the size of the chunk. I will then, if it is the case,
increase the size of my chunk.
For exemple : with a chunk of size 30 I will take the first node's index
that is between 0 and 30 and push it into B,
I will then increase my chunk to 31 until the list A is a size of 3 nodes */
void	korean_algo(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	int	index_max;
	int	count;

	index_max = size_of_list(stack_a) - 3;
	count = 0;
	while (size_of_list(stack_a) != 3)
	{
		if ((*stack_a)->index <= count && (*stack_a)->index < index_max)
		{
			push_into_stack(stack_a, stack_b, 'b');
			count++;
		}
		else if ((*stack_a)->index < (count + data->chunk_size)
			&& (*stack_a)->index < index_max)
		{
			sort_next_head(stack_a, stack_b, data, count);
			count++;
		}
		else
			rotate_next(stack_a, 'a');
	}
}

void	push_b_in_a_korean_way(t_stack **stack_a, t_stack **stack_b, int size_a,
		t_data *data)
{
	int	size_b;

	while (size_of_list(stack_a) != size_a)
	{
		if ((*stack_b)->index == (*stack_a)->index - 1
			|| (*stack_a)->prev->index == size_a - 1
			|| (*stack_b)->index > (*stack_a)->prev->index)
		{
			push_into_stack(stack_b, stack_a, 'a');
			sort_stack_a_korean_way(stack_a);
		}
		else if ((*stack_b)->index != data->max)
		{
			size_b = size_of_list(stack_b);
			max_index_in_b(stack_b, data);
			if (data->max_pos > size_b / 2)
				rotate_prev(stack_b, 'b');
			else
				rotate_next(stack_b, 'b');
		}
	}
}

void	sort_stack_a_korean_way(t_stack **stack_a)
{
	if ((*stack_a)->index != (*stack_a)->next->index - 1)
	{
		rotate_next(stack_a, 'a');
		return ;
	}
	else
	{
		while ((*stack_a)->prev->index == (*stack_a)->index - 1)
			rotate_prev(stack_a, 'a');
	}
}

void	sort_next_head(t_stack **stack_a, t_stack **stack_b, t_data *data,
		int count)
{
	push_into_stack(stack_a, stack_b, 'b');
	if ((*stack_a)->index >= count)
	{
		rotate_next(stack_a, 'c');
		rotate_next(stack_b, 'c');
		ft_printf("rr\n");
	}
	else
		rotate_next(stack_b, 'b');
}
