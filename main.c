/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:34:49 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 19:23:34 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_all(t_stack *stack)
{
	t_node	*temp;

	temp = stack->bottom;
	while (temp)
	{
		ft_printf("%d\n", temp->n);
		temp = temp->next;
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
	if (stack_a.count <= 5)
	{
		sort_element_small(&stack_a, &stack_b);
		return (0);
	}
	find_and_move_ordered(&stack_a, &stack_b);
	if (stack_b.count != 0)
		sort_element(&stack_a, &stack_b);
	clear_stack(&stack_a);
	return (0);
}
