/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:13:05 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 21:05:59 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_rr(t_stack *stk_a, t_stack *stk_b, t_info *save)
{
	while (stk_a->top->n != save->a_save->n && \
				stk_b->top->n != save->b_save->n)
	{
		rr(stk_a, stk_b);
		save->order_count--;
	}
	while (stk_a->top->n != save->a_save->n)
		ra(stk_a);
	while (stk_b->top->n != save->b_save->n)
		rb(stk_b);
}

void	case_rrr(t_stack *stk_a, t_stack *stk_b, t_info *save)
{
	while (stk_a->top->n != save->a_save->n && \
				stk_b->top->n != save->b_save->n)
	{
		rrr(stk_a, stk_b);
		save->order_count--;
	}
	while (stk_a->top->n != save->a_save->n)
		rra(stk_a);
	while (stk_b->top->n != save->b_save->n)
		rrb(stk_b);
}

void	case_common(t_stack *stk_a, t_stack *stk_b, t_info *save)
{
	int	count;

	count = count_index(stk_a, save->a_save);
	if (count + 1 < (stk_a->count - count - 1))
		while (stk_a->top->n != save->a_save->n)
			rra(stk_a);
	else
		while (stk_a->top->n != save->a_save->n)
			ra(stk_a);
	count = count_index(stk_b, save->b_save);
	if (count + 1 < (stk_b->count - count - 1))
		while (stk_b->top->n != save->b_save->n)
			rrb(stk_b);
	else
		while (stk_b->top->n != save->b_save->n)
			rb(stk_b);
}
