/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:57:08 by seonghwc          #+#    #+#             */
/*   Updated: 2023/01/27 15:57:47 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_sub(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->bottom;
	stack_a->bottom = stack_a->bottom->next;
	stack_a->bottom->prev = 0;
	temp->prev = stack_a->top;
	stack_a->top->next = temp;
	temp->next = 0;
	stack_a->top = temp;
}

void	rrb_sub(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->bottom;
	stack_b->bottom = stack_b->bottom->next;
	stack_b->bottom->prev = 0;
	temp->prev = stack_b->top;
	stack_b->top->next = temp;
	temp->next = 0;
	stack_b->top = temp;
}
