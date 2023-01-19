/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:07:28 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 20:36:30 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->top->n;
	stack_a->top->n = stack_a->top->prev->n;
	stack_a->top->prev->n = temp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->top->n;
	stack_b->top->n = stack_b->top->prev->n;
	stack_b->top->prev->n = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_b) == 0)
		return ;
	push(stack_a, pop(stack_b));
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a) == 0)
		return ;
	push(stack_b, pop(stack_a));
	ft_printf("pb\n");
}
