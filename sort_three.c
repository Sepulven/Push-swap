/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:14:49 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/27 00:17:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_des(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		sa(a);
	tmp = (*a)->next;
	pb(a, b);
	if (*(int *)(*a)->content < *(int *)(*a)->next->content)
		sa(a);
	pb(a, b);
	if (*(int *)(*b)->content > *(int *)(*b)->next->content)
		sb(b);
	pb(a, b);
}

void sort_three_asc(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	if (*(int *)tmp->content > *(int *)tmp->next->content)
		sa(a);
	tmp = (*a)->next;
	pb(a, b);
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a);
	pb(a, b);
	if (*(int *)(*b)->content < *(int *)(*b)->next->content)
		sb(b);
	pb(a, b);
}