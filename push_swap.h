/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghwc <seonghwc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:22:00 by marvin            #+#    #+#             */
/*   Updated: 2023/01/11 18:12:33 by seonghwc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
};

typedef struct s_node	t_node;

typedef struct s_stack
{
	t_node	*bottom;
	t_node	*top;
	int		count;
}	t_stack;

void	push(t_stack *stack, int content);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);
void	init_stack(t_stack *stack);
void	clear_stack(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		is_integer(char *argv);
int		check_dup(t_stack *stack_a, int num);
int		check_and_push_integer(t_stack *stack_a, char *argv);
void	push_input(t_stack *stack_a, int argc, char *argv[]);
int		check_ordered_length(t_node *current);
void	mov_ordered_to_bottom(t_stack *stack_a, t_node *save);
void	mov_to_stack_b(t_stack *stack_a, t_stack *stack_b, int count);
void	find_and_move_ordered(t_stack *stack_a, t_stack *stack_b);
void	find_position(t_stack *stack_a, t_stack *stack_b);
void	calc_path(t_stack *stack_a, t_node *pos);

#endif