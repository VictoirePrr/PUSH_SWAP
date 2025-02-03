/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:41:16 by vicperri          #+#    #+#             */
/*   Updated: 2025/02/03 13:50:59 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

/* Goal : Removes the current node from a circular doubly linked list.
To do so I save my node into a variable node_to_remove.
If there is only one node in the stack, I set it to NULL.
Otherwise, I move the head of my stack to the second node,
I set the next of the last node to point to the second node,
and I set the prev of the second node to point to the last node.
*/
void	rm_node(t_stack **stack)
{
	t_stack	*node_to_remove;

	if (!*stack)
		return ;
	node_to_remove = *stack;
	if (node_to_remove->next == node_to_remove)
		*stack = NULL;
	else
	{
		node_to_remove->prev->next = node_to_remove->next;
		node_to_remove->next->prev = node_to_remove->prev;
		*stack = node_to_remove->next;
	}
}

int	size_of_list(t_stack **stack)
{
	t_stack	*temp;
	int		size;

	temp = *stack;
	size = 0;
	while (1)
	{
		temp = temp->next;
		size++;
		if (temp == *stack)
			break ;
	}
	return (size);
}

void	ft_free_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
}
/*Goal : search for the biggest num in my list.
To do so, I interate through my stack with temp and compare the content of
my nodes to data->max which is first equal to the MIN INT.
If my temp is bigger than data->max, data->max will now be equal to temp.
I also take advantage of this iteration to retrive the position of the biggest node.*/
void	max_index_in_b(t_stack **stack_b, t_data *data)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = *stack_b;
	data->max = INT_MIN;
	while (1)
	{
		if (temp->index > data->max)
		{
			data->max = temp->index;
			data->max_pos = len;
		}
		len++;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
}
