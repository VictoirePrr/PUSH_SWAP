/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/31 17:49:52 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_stack **stack)
{
	t_stack	*temp;
	int		size;

	size = size_of_list(stack);
	while (size > 0)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
		size--;
	}
	*stack = NULL;
}

int	check_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*check;

	temp = *stack;
	if (size_of_list(stack) == 2)
	{
		if (temp->content == (*stack)->next->content)
			return (ERROR);
	}
	while (1)
	{
		check = temp->next;
		while (check != temp->prev)
		{
			if (temp->content == check->content)
				return (ERROR);
			check = check->next;
		}
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	return (SUCCESS);
}

int	split_and_list_argv(int argc, char **argv, t_stack **stack)
{
	int		j;
	int		i;
	long	num;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			return (ERROR);
		j = 0;
		while (args[j])
		{
			if (ft_isdigit(args[j]) == ERROR)
				return (ERROR);
			num = ft_atoi(args[j]);
			if (fill_and_check_the_list(num, stack) == ERROR)
				return (ERROR);
			j++;
		}
		ft_free_args(args);
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (split_and_list_argv(argc, argv, &stack_a) == ERROR)
		return (print_error(), ERROR);
	// ft_free_list(&stack_a)
	if (size_of_list(&stack_a) == 1)
		return (SUCCESS);
	// ft_free_list(&stack_a),
	if (size_of_list(&stack_a) == 2)
	{
		if (stack_a->content > stack_a->next->content)
			rotate_next(&stack_a, 'a');
	}
	else if (size_of_list(&stack_a) <= 12)
		sort_the_small_list(&stack_a, &stack_b);
	else if (size_of_list(&stack_a) > 12)
		sort_the_big_list(&stack_a, &stack_b);
	// ft_free_list(&stack_a);
	// ft_free_list(&stack_b);
	//+ error quand double chaine trie au depard
	return (SUCCESS);
}
