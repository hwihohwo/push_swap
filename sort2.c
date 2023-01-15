/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:03:54 by marvin            #+#    #+#             */
/*   Updated: 2023/01/13 18:03:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_calc(t_stack *stack_a, t_stack *stack_b, int count_a, int count_b)
{
	int	ret;

	ret = 0;
	if (count_a < (stack_a->count + 1) / 2 && \
		count_b < (stack_b->count + 1) / 2)
			ret = half_under(stack_a, stack_b, count_a, count_b);
	else if (count_a >= (stack_a->count + 1) /2  && \
		count_b >= (stack_b->count + 1) / 2)
			ret = half_upper(stack_a, stack_b, count_a, count_b);
	else
	{
		ret += common_case(stack_a, count_a);
		ret += common_case(stack_b, count_b);
	}
	return (ret);
}

int	order_count(t_stack *stack_a, t_stack *stack_b, t_node *b_temp)
{
	int		count_a;
	int		count_b;
	t_node *tmp;

	count_a = 0;
	count_b = 0;
	tmp = stack_b->bottom;
	while (tmp != b_temp)
	{
		count_b++;
		tmp = tmp->next;
	}
	tmp = stack_a->bottom;
	while (!(tmp->content > tmp->content && tmp->next->content < tmp->content))
	{
		count_a++;
		tmp = tmp->next;
	}
	return (order_calc(stack_a, stack_b, count_a, count_b));
}

void	find_best_element(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	int		max;
	t_node *temp;

	temp = stack_b->bottom;
	max = 0;
	while (temp)
	{
		count = order_count(stack_a, stack_b, temp);
		temp = temp->next;
		if (max < count)
			max = count;
	}
}

// void	find_position(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*start;
// 	t_node	*temp;
// 	int		b_top;

// 	start = stack_a->bottom;
// 	while (stack_b->count > 0)
// 	{
// 		b_top = stack_b->top->content;
// 		temp = start;
// 		if (temp->content > b_top && temp->next->content < b_top)
// 		{
// 			calc_path(stack_a, temp);
// 			pa(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			if (temp->next == 0)
// 				temp = stack_a->bottom;
// 			else
// 				temp = temp->next;
// 		}
// 	}
// }

// void	calc_path(t_stack *stack_a, t_node *pos)
// {
// 	t_node	*temp;
// 	int		count;

// 	count = 0;
// 	temp = stack_a->bottom;
// 	while (temp == pos)
// 	{
// 		count++;
// 		temp = temp->next;
// 	}
// 	if (count < (stack_a->count + 1) / 2)
// 		while (stack_a->top == pos)
// 			rra(stack_a);
// 	else
// 		while (stack_a->top == pos)
// 			ra(stack_a);
// }