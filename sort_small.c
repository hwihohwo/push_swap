/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:01:57 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 00:01:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_element_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count == 1)
		return ;
	else if (stack_a->count == 2)
	{
		if (stack_a->bottom->content < stack_a->top->content)
			sa(stack_a);
		else
			return ;
	}
	else if (stack_a->count == 3)
		sort_element_3(stack_a);
	else if (stack_a->count == 4)

}

void	sort_element_3(t_stack *stack_a)
{
	if (stack_a->bottom->content < stack_a->bottom->next->content \
		< stack_a->top->content)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->bottom->content < stack_a->top->content \
			< stack_a->bottom->next->content)
		rra(stack_a);
	else if (stack_a->bottom->next->content < stack_a->bottom->content \
			< stack_a->top->content)
		ra(stack_a);
	else if (stack_a->top->content < stack_a->bottom->content \
			< stack_a->bottom->next->content)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->bottom->next->content < stack_a->top->content \
			< stack_a->bottom->content)
		sa(stack_a);
}

void	sort_element_4(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	sort_element_3(stack_a);
	
}