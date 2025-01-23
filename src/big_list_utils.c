/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:37 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/23 19:21:15 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Goal : giving each node its right index, for exemple,
	for a list of 10 numbers,
the smallest number will have an index 0 and the biggest will have an index of 9.
To do so : I make sure each index are set to -1.
Then I go into a loop where I search for the smallest number inside my list.
Then I go inside another loop to search for this min number and I make sure it was not already sorted (temp->index still to
	-1)
If it was not : then I set my index to data->index | If it was : I coninue to traverse my temp until I reach the top.
I then increment data->index and I check if my stack still possess index = to -1
If it is : I go for antoher round | If not : I stop. Every nodes have their index set !*/
void	search_sort_index(t_stack **stack, t_data *data)
{
	t_stack	*temp;
	int		all_processed;

	all_processed = check_if_node_processed(stack);
	while (!all_processed)
	{
		search_smallest_big_list(stack, data);
		temp = *stack;
		while (1)
		{
			if (temp->content == data->min && temp->index == -1)
			{
				temp->index = data->index;
				break ;
			}
			temp = temp->next;
			if (temp == *stack)
				break ;
		}
		data->index++;
		all_processed = check_if_node_processed(stack);
	}
}
/* Goal : check if there is still nodes that have indexes set to -1
To do so : a boolean set to 1 go through a loop to traverse my stack.
If it finds an index = to
	-1 : my boolean changes to 0. | If not : it continues until it reaches the head.
I then return my boolean. */
int	check_if_node_processed(t_stack **stack)
{
	int		all_processed;
	t_stack	*temp;

	all_processed = 1;
	temp = *stack;
	while (1)
	{
		if (temp->index == -1)
		{
			all_processed = 0;
			break ;
		}
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (all_processed);
}

/* Goal : setting every nodes in my stack to an index of -1
To do so : I do a simple loop with a temp list equal to my stack,
and set each index to -1. */
void	set_index(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (1)
	{
		temp->index = -1;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}
/* Goal : search in my stack the smallest node that is still not indexed.
To do so : I set my variable (data->min) to the head of my stack.
I then traverse my stack.
If my node is smaller than my variable and its index is still equal to -1 :
my variable is	now = to this node | If not : I continue */
void	search_smallest_big_list(t_stack **stack, t_data *data)
{
	t_stack	*temp;

	temp = *stack;
	data->min = INT_MAX; // so that it compares first to the highest num possible
	while (1)
	{
		if (temp->index == -1 && temp->content < data->min)
			data->min = temp->content;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}
/* Goal : compute a size of chunk that is going to grow exponentionaly with the size of the list
To do so :
Quadratic formula : ax² + bx + c = 0
With a, b and c being constants, and x being an unknown variable.
The first part helps with bigger lists :
The size of the chunk won't double between a list of 500 and a list of 1000 but will be much bigger.
The second part will help with smaller lists in a more linear way,
and the last will be the smallest chunk you can have */
void	compute_chunks(t_stack **stack, t_data *data)
{
	int	size;

	size = size_of_list(stack);
	data->chunk_size = ((QUAD * (size * size)) + (0.03 * size) + MIN_CHUNK);
}
