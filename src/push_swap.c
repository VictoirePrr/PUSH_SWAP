/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:30:18 by vicperri          #+#    #+#             */
/*   Updated: 2025/02/04 13:49:37 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_stack **stack)
{
	t_stack	*temp;
	int		size;

	if (!*stack)
		return ;
	size = size_of_list(stack);
	while (size != 0)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
		size--;
	}
	*stack = NULL;
}

/*Goal : Check for doubles inside the stack.
 To do so, I check if the list is equal to a size of 2.
 Then I loop inside my stack with a temp and a check, while I am on
 the head I loop through the list, if I find a double :
 I return ERROR.*/
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

/*Goal : check arguments for mistakes and list the numbers into stack.
To do so, I do a split on my argvs and store it into a tab of tab
'args'. Then I loop in my args and check if I only have numbers,
if so; I atoi them and insert them into a stack. While being inserted into
the stack I check for doubles. I free when needed and if everything works
I return SUCCESS ! */
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
				return (ft_free_args(args), ERROR);
			num = ft_atoi(args[j]);
			if (fill_and_check_the_list(num, stack) == ERROR)
				return (ft_free_args(args), ERROR);
			j++;
		}
		ft_free_args(args);
		i++;
	}
	return (SUCCESS);
}

int	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (size_of_list(stack_a) == 1)
	{
		ft_free_list(stack_a);
		return (SUCCESS);
	}
	if (size_of_list(stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			rotate_next(stack_a, 'a');
	}
	else if (size_of_list(stack_a) <= 12)
		sort_the_small_list(stack_a, stack_b);
	else if (size_of_list(stack_a) > 12)
		sort_the_big_list(stack_a, stack_b);
	ft_free_list(stack_a);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
	{
		print_error();
		return (ERROR);
	}
	if (split_and_list_argv(argc, argv, &stack_a) == ERROR)
	{
		ft_free_list(&stack_a);
		print_error();
		return (ERROR);
	}
	if (is_sorted(&stack_a) == 1)
		ft_push_swap(&stack_a, &stack_b);
	else
		ft_free_list(&stack_a);
	return (SUCCESS);
}
