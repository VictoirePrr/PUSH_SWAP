/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_big_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:59:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/02/03 17:26:51 by vicperri         ###   ########lyon.fr   */
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
In my first 'if' I will push into stack_b each node's index that are smaller than count.
In my second 'if' I will do a special sort for bigger indexes (smaller than my chunk_size
	+ count).
For exemple : with a chunk of size 30 I will take the first node's index
that is smaller than count and push into B, or the  first node's index
that is smaller than count + chunk_size and sort it in a special way.*/
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
			sort_next_head(stack_a, stack_b, count);
			count++;
		}
		else
			rotate_next(stack_a, 'a');
	}
}
/* Goal : push B into A and final sort.
To do so, I iterate in stack_a until it is equal to the initial size of A.
I then check if my index at the head of B is sorted with the head of A or
that the last index of A is sorted
or that the index of B is bigger than the last index of A.
If so, I push into stack A my node and sort stack A.
Else if my index at the head of B is not equal to the biggest index in B,
I will choose to rotate next or prev depending of its position in the list.*/
void	push_b_in_a_korean_way(t_stack **stack_a, t_stack **stack_b, int size_a,
		t_data *data)
{
	int	size_b;

	while (size_of_list(stack_a) != size_a)
	{
		max_index_in_b(stack_b, data);
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
			if (data->max_pos > size_b / 2)
				rotate_prev(stack_b, 'b');
			else
				rotate_next(stack_b, 'b');
		}
	}
}
/* Goal : sort stack A once B pushed a node.
To do so, I check if the index of the head is sorted.
If not I will ra to put the node at the end of the stack.
If it is the case then I will check if the last node of A
could be sorted if I put it at the head. If it is the case I will rra */
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
/* Goal : sort the new head after pushing the old head
(smaller than count + chunk_size) into B.
To do so, I check if the head is bigger than count.
If it is the case I 'rr' to favor smaller indexes to be pushed into B.
Else, I just rotate B to push the old head at the bottom. */
void	sort_next_head(t_stack **stack_a, t_stack **stack_b, int count)
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
