/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:22:34 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/31 11:18:54 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "checker.h"

void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);

void		del_nodes(t_list **lst);
void		swap_node(t_list *head);
void		rotate_nodes(t_list **head);
void		rrotate_nodes(t_list **head);
void		push_nodes(t_list **stack1, t_list **stack2);

typedef struct	s_push
{
	t_list		*a;
	t_list		*b;
	char		**array;
	int			*sorted;
	int			size;
	int			fctr;
}				t_push;

#endif
