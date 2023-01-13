/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:34:49 by marvin            #+#    #+#             */
/*   Updated: 2023/01/11 18:14:44 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (temp->content == num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_and_push_integer(t_stack *stack_a, char *argv)
{
	int		i;
	long	ret;

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
	int		i;
	int		j;
	long	num;

	i = 0;
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

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	push_input(&stack_a, argc, argv);
	find_and_move_ordered(&stack_a, &stack_b);
	find_position(&stack_a, &stack_b);
	return (0);
}
