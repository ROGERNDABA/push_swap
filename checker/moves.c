/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:40:00 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/29 17:14:09 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_list *head)
{
	if (head != NULL && head->next != NULL)
		ft_swap(&head->data, &head->next->data);
}

void	ft_pop(t_list **head)
{
	t_list *temp;

	if (head && *head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

void	rotate_nodes(t_list **head)
{
	if (*head != NULL)
	{
		ft_lstpushback(head, (*head)->data);
		ft_pop(head);
	}
}

void	rrotate_nodes(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	if (*head != NULL && tmp->next != NULL)
	{
		ft_lstpushfront(head, tmp->next->data);
		free(tmp->next);
		tmp->next = NULL;
	}
}

void	push_nodes(t_list **stack1, t_list **stack2)
{
	ft_lstpushfront(stack1, (*stack2)->data);
	ft_pop(stack2);
}
