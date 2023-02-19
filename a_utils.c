/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:58:45 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/17 12:32:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list)
{
	t_list *node1;
	t_list *node2;

	node1 = pop_head(list);
	node2 = pop_head(list);
	ft_lstadd_front(list, node1);
	ft_lstadd_front(list, node2);
	ft_printf("sa\n");
}

void	pa(t_list **a, t_list **b)
{
	if (!*b || !*a)
		return ;
	ft_lstadd_front(a, pop_head(b));
	ft_printf("pa\n");
}

void	ra(t_list **list)
{
	ft_lstadd_back(list, pop_head(list));
	ft_printf("ra\n");
}

void	rra(t_list **list)
{
	ft_lstadd_front(list, pop_tail(list));
	ft_printf("rra\n");
}
