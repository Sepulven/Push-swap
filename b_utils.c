/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:03:36 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/17 11:18:02 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **list)
{
	sa(list);
	ft_printf("sa\n");
}

void	pb(t_list **a, t_list **b)
{
	pa(b, a);
	ft_printf("pb\n");
}

void	rb(t_list **list)
{
	ra(list);
	ft_printf("rb\n");
}

void	rrb(t_list **list)
{
	rra(list);
	ft_printf("rrb\n");
}
