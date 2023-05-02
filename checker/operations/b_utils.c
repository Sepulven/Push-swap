/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:03:36 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 01:48:33 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./operations.h"

void	sb(t_list **list)
{
	t_list	*node1;
	t_list	*node2;

	if (!(*list)->next)
		return ;
	node1 = pop_head(list);
	if (!node1)
		return ;
	node2 = pop_head(list);
	if (!node2)
		return ;
	ft_lstadd_front(list, node1);
	ft_lstadd_front(list, node2);
	ft_printf("sb\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*a)
		return ;
	node = pop_head(a);
	ft_lstadd_front(b, node);
	ft_printf("pb\n");
}

void	rb(t_list **list)
{
	t_list	*node;

	if (ft_lstsize(*list) < 2)
		return ;
	node = pop_head(list);
	if (!node)
		return ;
	ft_lstadd_back(list, node);
	ft_printf("rb\n");
}

void	rrb(t_list **list)
{
	t_list	*node;

	if (ft_lstsize(*list) < 2)
		return ;
	node = pop_tail(list);
	if (!node)
		return ;
	ft_lstadd_front(list, node);
	ft_printf("rrb\n");
}
