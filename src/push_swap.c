/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/31 13:59:59 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*check;

	temp = *stack;
	if (size_of_list(stack) == 2)
		return (SUCCESS);
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
				return (print_error(), ERROR);
			num = ft_atoi(args[j]);
			if (fill_and_check_the_list(num, stack) == ERROR)
				return (print_error(), ERROR);
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
		return (ERROR);
	if (size_of_list(&stack_a) <= 12)
		sort_the_small_list(&stack_a, &stack_b);
	else
		sort_the_big_list(&stack_a, &stack_b);
	return (SUCCESS);
}
