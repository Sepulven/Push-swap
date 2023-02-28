/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:07 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/27 22:54:43 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_list **list)
{
	t_list *tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	merge_all(t_list **a, t_list **b)
{
	float	size;
	int		tips;
	int		i;
	int		j;

	size = ft_lstsize(*b) / 3;
	tips = 3;
	j = 1;
	while (!issorted(a))
	{
		i = 0;
		if (ft_lstsize(*b) != 0)
		{
			while (i != size / 2)
			{
				if (*(int *)(*b)->content < *(int *)(*b)->next->content)
					merge_b_to_a_des(a, b, tips, tips);
				else
					merge_b_to_a_asc(a , b, tips, tips);
				i++;
			}
			size /= 2; 
			j++;
			tips += tips;
		}
		else 
		{
			while (i != size / 2)
			{
				if (*(int *)(*a)->content < *(int *)(*a)->next->content)
					merge_a_to_b_des(a, b, tips, tips);
				else
					merge_a_to_b_asc(a, b, tips, tips);
				i++;
			}
			size /= 2;
			j++;
			tips += tips;
		}
	}
}
