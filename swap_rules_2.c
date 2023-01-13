/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:37:12 by marvin            #+#    #+#             */
/*   Updated: 2023/01/10 13:15:01 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->prev;
	stack_a->top->next = NULL;
	temp->next = stack_a->bottom;
	stack_a->bottom->prev = temp;
	temp->prev = NULL;
	stack_a->bottom = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->prev;
	stack_b->top->next = NULL;
	temp->next = stack_b->bottom;
	stack_b->bottom->prev = temp;
	temp->prev = NULL;
	stack_b->bottom = temp;
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

void	rra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a->count < 2)
		return ;
	temp = stack_a->bottom;
	stack_a->bottom = stack_a->bottom->next;
	stack_a->bottom->prev = NULL;
	temp->prev = stack_a->top;
	stack_a->top->next = temp;
	temp->next = NULL;
	stack_a->top = temp;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->count < 2)
		return ;
	temp = stack_b->bottom;
	stack_b->bottom = stack_b->bottom->next;
	stack_b->bottom->prev = NULL;
	temp->prev = stack_b->top;
	stack_b->top->next = temp;
	temp->next = NULL;
	stack_b->top = temp;
	ft_printf("rrb\n");
}
