/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:30:07 by marvin            #+#    #+#             */
/*   Updated: 2023/01/27 15:58:03 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra_sub(stack_a);
	rrb_sub(stack_b);
	ft_printf("rrr\n");
}

void	sa_sub(t_stack *stack_a)
{
	int	temp;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->top->n;
	stack_a->top->n = stack_a->top->prev->n;
	stack_a->top->prev->n = temp;
}

void	sb_sub(t_stack *stack_b)
{
	int	temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->top->n;
	stack_b->top->n = stack_b->top->prev->n;
	stack_b->top->prev->n = temp;
	ft_printf("sb\n");
}

void	ra_sub(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->prev;
	stack_a->top->next = 0;
	temp->next = stack_a->bottom;
	temp->next->prev = temp;
	temp->prev = 0;
	stack_a->bottom = temp;
}

void	rb_sub(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->prev;
	stack_b->top->next = 0;
	temp->next = stack_b->bottom;
	temp->next->prev = temp;
	temp->prev = 0;
	stack_b->bottom = temp;
}
