/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:25:18 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/31 09:58:20 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

int		chk_dbl(char **av, int n, int i)
{
	while (i > n)
	{
		if (ft_strcmp(av[i], av[n]) == 0)
			return (0);
		i--;
	}
	return (1);
}

int		is_onlydigit(char *s)
{
	s--;
	while (*++s)
		if (!(*s >= 48 && *s <= 57) && !(*s == '-' && ft_isdigit(*(s+1))))
			return (0);
	return (1);
}

void	del_nodes(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

t_list	*make_stack_a(t_list *e, char **av)
{
	int		i;

	i = ft_arrsize(av);
	while (--i >= 0)
	{
		if (is_onlydigit(av[i]) &&
			chk_dbl(av, i, ft_arrsize(av) - 1) == 1)
			ft_lstpushfront(&e, ft_atoi(av[i]));
		else if ((long)ft_atoi(av[i]) > INT_MAX &&
				(long)ft_atoi(av[i]) < INT_MIN)
			ft_lstpushfront(&e, ft_atoi(av[i]));
		else
		{
			printf("Error\n");
			del_nodes(&e);
			exit(1);
		}
	}
	return (e);
}
