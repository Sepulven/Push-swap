/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:52:51 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/26 05:11:55 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *head)
{
	while (head)
	{
		ft_printf("->%d ", *(int *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}

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

// Merge tips regardless of the tips size; done 
// Merge tips regardless of the middle of the list; done
// TODO: To optimaze the code I need to pass a struct with the tips size and supposed functions;
// So I can make it asc or des
void	merge_tips(t_list **a, t_list **b, int l_tip, int r_tip)
{
	t_list	*node;

	while(l_tip > 0 || r_tip > 0)
	{
		node = ft_lstlast(*a);
		if (l_tip == 0)
		{
			rra(a);
			pb(a, b);
			r_tip--;
		}
		else if (r_tip == 0)
		{
			pb(a, b);
			l_tip--;
		}
		else if (l_tip > 0 && *(int *)(*a)->content > *(int *)node->content)
		{
			pb(a, b);
			l_tip--;
		}
		else if (r_tip > 0)
		{
			rra(a);
			pb(a, b);
			r_tip--;
		}
	}
}