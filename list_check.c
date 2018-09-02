/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 12:27:15 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/02 12:32:10 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		list_last(t_list *head)
{
	t_list *list;

	list = head;
	while (list->next != NULL)
		list = list->next;
	return (list->data);
}

int		val_dist(t_list *e, int a, int b)
{
	int		i;
	int		j;
	t_list	*list;

	i = -1;
	j = -1;
	list = e;
	while (list != NULL)
	{
		if (list->data == a)
			break ;
		i++;
		list = list->next;
	}
	list = e;
	while (list != NULL)
	{
		if (list->data == b)
			break ;
		j++;
		list = list->next;
	}
	return (i - j);
}

int		lowest(t_list *e, int i)
{
	int		r;
	t_list	*list;

	list = e;
	r = list->data;
	while (list != NULL)
	{
		if (i == 0)
			r = (r < list->data) ? r : list->data;
		else
			r = (r > list->data) ? r : list->data;
		list = list->next;
	}
	return (r);
}

int		position(t_list *list, int val)
{
	int		i;
	t_list	*e;

	e = list;
	i = 0;
	while (e != NULL)
	{
		if (e->data == val)
			break ;
		i++;
		e = e->next;
	}
	return (i);
}
