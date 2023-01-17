/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:21:43 by marvin            #+#    #+#             */
/*   Updated: 2023/01/17 20:32:08 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
	node->n = content;
	node->next = NULL;
	if (stack->bottom == NULL && stack->top == NULL)
	{
		stack->bottom = node;
		stack->top = node;
		node->prev = NULL;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->count++;
}

int	pop(t_stack *stack)
{
	int		ret;
	t_node	*temp;

	temp = stack->top;
	ret = stack->top->n;
	if (stack->top->prev != 0)
	{
		stack->top = stack->top->prev;
		stack->top->next = 0;
	}
	else
	{
		stack->top = 0;
		stack->bottom = 0;
	}
	free(temp);
	stack->count--;
	return (ret);
}

int	is_empty(t_stack *stack)
{
	if (stack->count == 0)
		return (0);
	else
		return (1);
}

void	init_stack(t_stack *stack)
{
	stack->bottom = NULL;
	stack->top = NULL;
	stack->count = 0;
}

void	clear_stack(t_stack *stack)
{
	while (stack->count > 0)
		pop(stack);
}
