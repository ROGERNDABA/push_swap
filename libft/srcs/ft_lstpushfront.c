/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:03:37 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/31 14:57:41 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **begin_list, int data)
{
	t_list	*list;

	if (*begin_list)
	{
		list = ft_lstnewnode(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
	{
		*begin_list = ft_lstnewnode(data);
	}
}
