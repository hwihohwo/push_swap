/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:17:48 by seonghwc          #+#    #+#             */
/*   Updated: 2023/01/17 18:59:49 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_bottom(t_stack *stack, t_node *node)
{
	int	count;

	count = count_index(stack, node->n);
	if (count < (stack->count - count))
		while (stack->bottom->n != node->n)
			rra(stack);
	else
		while (stack->bottom->n != node->n)
			ra(stack);
}

void	move_to_top(t_stack *stack, t_node *node)
{
	int	count;

	count = count_index(stack, node->n);
	if (count + 1 < (stack->count - count - 1))
		while (stack->top->n != node->n)
			rra(stack);
	else
		while (stack->bottom->n != node->n)
			ra(stack);
}
