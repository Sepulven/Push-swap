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
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
