/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:03:40 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/17 11:13:34 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*pop_head(t_list **list)
{
	t_list	*node;
	
	node = *list;
	*list = (*list)->next; 
	node->next = NULL;
	return (node);
}

t_list *pop_tail(t_list **list)
{
	t_list	*node;
	t_list	*tmp;

	tmp = (*list)->next;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	return (node);
}

void	ss(t_list **a, t_list **b)
{
	t_list *node1;
	t_list *node2;

	node1 = pop_head(a);
	node2 = pop_head(a);
	if (!node2)
		return ;
	ft_lstadd_front(a, node1);
	ft_lstadd_front(a, node2);
	node1 = pop_head(b);
	node2 = pop_head(b);
	if (!node2)
		return ;
	ft_lstadd_front(b, node1);
	ft_lstadd_front(b, node2);
	ft_printf("ss\n");
}
void	rr(t_list **a, t_list **b)
{
	if (*a)
		ft_lstadd_back(a, pop_head(a));
	if (*b)
		ft_lstadd_back(b, pop_head(b));
	ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	if (*a)
		ft_lstadd_front(a, pop_tail(a));
	if (*b)
		ft_lstadd_front(b, pop_tail(b));
	ft_printf("rrr\n");
}
