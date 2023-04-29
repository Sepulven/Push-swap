/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:03:40 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/23 10:35:21 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_list	*pop_head(t_list **list)
{
	t_list	*node;

	if (!*list)
		return (NULL);
	node = *list;
	*list = (*list)->next;
	node->next = NULL;
	return (node);
}

t_list	*pop_tail(t_list **list)
{
	t_list	*node;
	t_list	*tmp;

	if (!*list)
		return (NULL);
	if (!(*list)->next)
	{
		node = *list;
		*list = NULL;
		return (node);
	}
	tmp = *list;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	node->next = NULL;
	return (node);
}

void	ss(t_list **a, t_list **b)
{
	t_list	*node1;
	t_list	*node2;

	if (!(*a)->next || !(*b)->next)
		return ;
	node1 = pop_head(a);
	if (!node1)
		return ;
	node2 = pop_head(a);
	if (!node2)
		return ;
	ft_lstadd_front(a, node1);
	ft_lstadd_front(a, node2);
	node1 = pop_head(b);
		if (!node1)
		return ;
	node2 = pop_head(b);
	if (!node2)
		return ;
	ft_lstadd_front(b, node1);
	ft_lstadd_front(b, node2);
	ft_printf("ss\n");
}

void	rr(t_list **a, t_list **b)
{
	t_list	*node;

	if (*a && ft_lstsize(*a) >= 2)
	{
		node = pop_head(a);
		if (node)
			ft_lstadd_back(a, node);
	}
	if (*b && ft_lstsize(*b) >= 2)
	{
		node = pop_head(b);
		if (node)
			ft_lstadd_back(b, node);
	}
	ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*node;

	if (*a && ft_lstsize(*a) >= 2)
	{
		node = pop_tail(a);
		if (node)
			ft_lstadd_front(a, node);
	}
	if (*b && ft_lstsize(*b) >= 2)
	{
		node = pop_tail(b);
		if (node)
			ft_lstadd_front(b, node);
	}
	ft_printf("rrr\n");
}
