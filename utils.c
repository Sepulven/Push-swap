/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:52:51 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/03 01:35:14 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *head)
{
	while (head)
	{
		ft_printf("->[%d]", *(int *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}

void send_a_to_b(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	while (i > 0)
	{
		pb(a, b);
		i--;
	}
}

void	send_b_to_a(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*b);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}
