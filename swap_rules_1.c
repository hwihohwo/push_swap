/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:07:28 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 16:20:15 by seonghwc         ###   ########.fr       */
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
	int	b;

	if (is_empty(stack_b) == 0)
		return ;
	b = pop(stack_b);
	push(stack_a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	a;

	if (is_empty(stack_a) == 0)
		return ;
	a = pop(stack_a);
	push(stack_b, a);
	ft_printf("pb\n");
}
