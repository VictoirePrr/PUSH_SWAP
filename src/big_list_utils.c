/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:58:37 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/22 12:04:32 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_sort_index(t_stack **stack, t_data *data)
{
	t_stack	*temp;
	int		all_processed;

	// Check if any nodes are unindexed
	all_processed = check_if_node_processed(stack);
	// Loop until all nodes are indexed
	while (!all_processed)
	{
		// Find the smallest unindexed node
		search_smallest_big_list(stack, data);
		// Traverse the list to find and assign index to the smallest unindexed node
		temp = *stack;
		while (temp)
		{
			if (temp->content == data->min && temp->index == -1)
			{
				temp->index = data->index; // Assign index to the smallest node
				break ;
				// Exit loop once the index is assigned
			}
			temp = temp->next;
			if (temp == *stack) // Avoid infinite loop in a circular list
				break ;
		}
		// Increment the index for the next smallest node
		data->index++;
		// Recheck if all nodes are indexed
		all_processed = check_if_node_processed(stack);
	}
}

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

void	search_smallest_big_list(t_stack **stack, t_data *data)
{
	t_stack *temp;
	int len;

	temp = *stack;
	data->min = temp->content;
	len = 0;
	while (temp)
	{
		if (temp->index == -1 && temp->content < data->min)
		// Only check unprocessed nodes
		{
			data->min = temp->content;
			data->min_pos = len;
		}
		temp = temp->next;
		len++;
		if (temp == *stack)
			break ;
	}
}