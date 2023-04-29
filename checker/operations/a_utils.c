/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:58:45 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/01 19:03:30 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_list **list)
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
	ft_printf("sa\n");
}

void	pa(t_list **a, t_list **b)
{
	if (!*b)
		return ;
	ft_lstadd_front(a, pop_head(b));
	ft_printf("pa\n");
}

void	ra(t_list **list)
{
	t_list	*node;

	if (ft_lstsize(*list) < 2)
		return ;
	node = pop_head(list);
	if (!node)
		return ;
	ft_lstadd_back(list, node);
	ft_printf("ra\n");
}

void	rra(t_list **list)
{
	t_list	*node;

	if (ft_lstsize(*list) < 2)
		return ;
	node = pop_tail(list);
	if (!node)
		return ;
	ft_lstadd_front(list, node);
	ft_printf("rra\n");
}
