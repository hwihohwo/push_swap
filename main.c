/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:34:49 by marvin            #+#    #+#             */
/*   Updated: 2023/01/27 18:50:20 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_tmp;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_stack(&stack_tmp);
	push_input(&stack_tmp, argc, argv);
	while (stack_tmp.count > 0)
		push(&stack_a, pop(&stack_tmp));
	if (check_ordered(&stack_a))
		return (0);
	if (stack_a.count <= 5)
	{
		sort_element_small(&stack_a, &stack_b);
		return (0);
	}
	push_to_b_and_sort3(&stack_a, &stack_b);
	if (stack_b.count != 0)
		sort_element(&stack_a, &stack_b);
	clear_stack(&stack_a);
	return (0);
}
