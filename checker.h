/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:43:58 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/30 16:52:17 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void		sort_int_tab(int *tab, unsigned int size);
char		**join_args(char **av);
char		**arr_join(char **arr1, char **arr2);
int			is_onlydigit(char *s);
int			chk_dbl(char **av, int n, int i);
void		check_cmd(t_list **stack_a, t_list **stack_b, char *s);
t_list		*make_stack_a(t_list *e, char **av);
int 		is_sorted(t_list *list, char **av);

#endif
