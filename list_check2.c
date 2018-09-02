/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 12:37:59 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/02 12:59:02 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		left_right(t_list *e, int val)
{
	int		i;
	t_list	*list;
	int		size;

	i = 0;
	size = ft_list_size(e);
	list = e;
	while (list != NULL)
	{
		if (list->data == val && i < (size / 2))
			return (1);
		i++;
		list = list->next;
	}
	return (2);
}

int		scnd_last(t_list *list)
{
	t_list *e;

	e = list;
	while (e->next->next != NULL)
		e = e->next;
	return (e->data);
}

int		list_center(t_list *head)
{
	int		i;
	int		z;
	t_list	*list;

	i = -1;
	list = head;
	z = ft_list_size(list);
	if (z % 2 == 0 && list != NULL)
	{
		while (++i < (z / 2) - 1)
			list = list->next;
		return (list->data);
	}
	else
	{
		while (++i < z / 2)
			list = list->next;
		return (list->data);
	}
	return (0);
}

int		get_factor(int n)
{
	int i;

	i = n;
	if (n == 1)
		return (n);
	else if (n <= 100)
	{
		while (i > 0)
		{
			if ((n / i) > 3)
				return (i);
			i -= 1;
		}
	}
	else
	{
		while (i > 0)
		{
			if ((n / i) > 3)
				return (i);
			i -= 1;
		}
	}
	return (1);
}

void	print_list(t_list *list, char i)
{
	t_list *e;

	e = list;
	if (i == 'A')
		printf(RED"STACK A = ");
	else
		printf(GREEN"STACK B = ");
	while (e != NULL)
	{
		printf("%d ",e->data);
		e = e->next;
	}
	printf("\n"DEFAULT);
}
