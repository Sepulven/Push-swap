/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:52:51 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/24 16:58:02 by asepulve         ###   ########.fr       */
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

void sort_three_des(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		sa(list);
	tmp = (*list)->next;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		rra(list);
}

void sort_three_asc(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (*(int *)tmp->content > *(int *)tmp->next->content)
		sa(list);
	tmp = (*list)->next;
	if (*(int *)tmp->content > *(int *)tmp->next->content)
		rra(list);
}

void	merge_tips(t_list **a, t_list **b)
{
	t_list	*node;
	int		i;

	i =  ft_lstsize(*a);
	while(i > 0)
	{
		node = ft_lstlast(*a);
		if (i == 1)
		{
			pb(a, b);
			print_list(*a);
			print_list(*b);
			return ;
		}
		if (*(int *)(*a)->content < *(int *)node->content)
		{
			rra(a);
			pb(a, b);
		}
		else
		{
			pb(a, b);
		}
		i--;
	}
}