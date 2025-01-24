/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_big_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:59:04 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/24 16:10:42 by vicperri         ###   ########lyon.fr   */
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

	data.min = 0;
	data.index = 0;
	data.chunk_size = 0;
	if (!*stack_a)
		return ;
	set_index(stack_a);
	search_sort_index(stack_a, &data);
	compute_chunks(stack_a, &data);
	korean_algo(stack_a, stack_b, &data);
	if (size_of_list(stack_a) == 3)
		sort_three(stack_a);
	// printf("a with 3 : \n");
	// ft_print_list(stack_a);
	// printf("b with others : \n");
	// ft_print_list(stack_b);
	push_b_in_a_korean_way(stack_a, stack_b);
}

/*Goal : push into stack_b my nodes depending on their index so that I can do a first sort between them.
To do so : until my stack_a is equal to three,
I will push into stack_b each node's index that corresponds to the size of the chunk
I will then, if it is the case, increase the size of my chunk.
For exemple : with a chunk of size 30 I will take the first node's index that is between 0 and 30 and push it into B,
I will then increase my chunk to 31 until the list A is a size of 3 nodes */
void	korean_algo(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	while (size_of_list(stack_a) != 3)
	{
		if ((*stack_a)->index <= data->chunk_size)
		{
			push_into_stack(stack_a, stack_b, 'b');
			data->chunk_size++;
		}
		rotate_next(stack_a, 'a');
	}
}
void	push_b_in_a_korean_way(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*temp_a;
	int		size;

	size = size_of_list(stack_a);
	temp_b = *stack_b;
	temp_a = *stack_a;
	while (1)
	{
		if (temp_b->index == temp_a->index - 1 || temp_a->prev->index == size
			|| temp_b->index > temp_a->prev->index)
		{
			push_into_stack(stack_b, stack_a, 'a');
		}
		temp_b = temp_b->next;
		if (temp_b == *stack_b)
			break ;
	}
}
void	sort_stack_a_korean_way(t_stack **stack_a)
{
	t_stack *temp_a;

	temp_a = *stack_a;
	if (temp_a->index != temp_a->next->index - 1)
	{
		rotate_next(stack_a, 'a');
		return ;
	}
	while (1)
	{
		if (temp_a->prev->index == temp_a->index - 1)
		{
			rotate_prev(stack_a, 'a');
			temp_a = temp_a->next;
		}
		else
			break ;
	}
}