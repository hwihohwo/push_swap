/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:07:28 by marvin            #+#    #+#             */
/*   Updated: 2023/01/05 14:07:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;
	int	count;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->top->content;
	stack_a->top->content = stack_a->top->prev->content;
	stack_a->top->prev->content = temp;
}

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->top->content;
	stack_b->top->content = stack_b->top->prev->content;
	stack_b->top->prev->content = temp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	b;

	if (is_empty(stack_b) == 0)
		return ;
	b = pop(stack_b);
	push(stack_a, b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	if (is_empty(stack_a) == 0)
		return ;
	a = pop(stack_a);
	push(stack_b, a);
}
