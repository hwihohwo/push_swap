/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:21:28 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 19:52:30 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_index(t_stack *stk, t_node *node)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = stk->bottom;
	while (temp != node)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	is_integer(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') || argv[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_dup(t_stack *stack_a, int num)
{
	t_node	*temp;

	temp = stack_a->bottom;
	while (temp)
	{
		if (temp->n == num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_and_push_integer(t_stack *stack_a, char *argv)
{
	int			i;
	long long	ret;

	i = 0;
	while (argv[i])
	{
		while (argv[i] <= '0' || argv[i] >= '9')
			i++;
		if (argv[i] == '\0')
			break ;
		ret = ft_atoi(&argv[i]);
		if (ret < -2147483648 || ret > 2147483647)
			return (0);
		else if (check_dup(stack_a, (int)ret) == 0)
			return (0);
		else
			push(stack_a, (int)ret);
		while (argv[i] >= '0' && argv[i] <= '9')
			i++;
	}
	return (1);
}

void	push_input(t_stack *stack_a, int argc, char *argv[])
{
	int		j;

	j = 1;
	while (j < argc)
	{
		if (is_integer(argv[j]))
		{
			if (check_and_push_integer(stack_a, argv[j]) == 0)
			{
				clear_stack(stack_a);
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		else
		{
			clear_stack(stack_a);
			write(2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
}
