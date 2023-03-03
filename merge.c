/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:17:07 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/03 03:37:28 by asepulve         ###   ########.fr       */
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

int	left_tip_size(t_list **list)
{
	t_list *tmp;
	int	size;
	char	flag;

	if (!*list)
		return (0);
	flag = 'd';
	tmp = *list;
	size = 0;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		flag = 'c';
	while (tmp->next)
	{
		if (flag == 'd' && *(int *)tmp->content < *(int *)tmp->next->content)
			break;
		if (flag == 'c' && *(int *)tmp->content > *(int *)tmp->next->content)
			break;
		size++;
		tmp = tmp->next;
	}
	return (size);
}

// We know that if one tip is decresent the other ir crescent
int right_tip_size(t_list **list)
{
	t_list	*tmp;
	int	size;
	char	flag;

	if (!*list)
		return (0);
	flag = 'c';
	tmp = *list;
	size = 0;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		flag = 'd';
	while (tmp->next)
	{
		if (flag == 'c' && *(int *)tmp->content > *(int *)tmp->next->content)
			size = 0;
		else if (flag == 'd' && *(int *)tmp->content < *(int *)tmp->next->content)
			size = 0;
		else
			size++;
		tmp = tmp->next;
	}
	return (size);
}

//TODO: I need to manage how to merge the tips;
//TODO: I need to manage in case where the number of triangles are odd;
void	merge_all(t_list **a, t_list **b)
{
	float	triangles;
	float	size;
	int		l_tip;
	int		r_tip;
	int		tips;
	int		flag;
	int		tmp;

	tips = 3;
	size = ft_lstsize(*b) / 3;
	flag = 0;
	if ((int)size % 2 != 0)
		flag = 1;
	tmp = flag;
	while (size != 1 &&!issorted(a))
	{
		triangles = size;
		flag = tmp;
		if (ft_lstsize(*b) != 0)
		{
			
			while (triangles > 1)
			{
				// manage the tips size;
				r_tip = right_tip_size(b);
				if (flag == 1 && r_tip - 3 > tips)
				{
					r_tip = tips + 3;
					flag = 0;
				} else
					r_tip = tips;
				l_tip = left_tip_size(b);
				if (flag == 1 && l_tip - 3 > tips)
				{
					l_tip = tips + 3;
					flag = 0;
				} else 
					l_tip = tips;
				if (*(int *)(*b)->content < *(int *)(*b)->next->content)
					merge_b_to_a_des(a, b, l_tip, r_tip);
				else
					merge_b_to_a_asc(a, b, l_tip, r_tip);
				triangles -= 2;
			}
			if (triangles < 2 && triangles > 0)
			{
				send_b_to_a(a, b);
				flag = 1;
			}
			tips += tips;
			size /= 2;
		}
		else 
		{
			while (triangles > 1)
			{
				// manage the tips size;
				r_tip = right_tip_size(a);
				if (flag == 1 && r_tip - 3 > tips)
				{
					r_tip = tips + 3;
					flag = 0;
				} else
					r_tip = tips;
				l_tip = left_tip_size(a);
				if (flag == 1 && l_tip - 3 > tips)
				{
					l_tip = tips + 3;
					flag = 0;
				} else 
					l_tip = tips;
				if (*(int *)(*a)->content < *(int *)(*a)->next->content)
					merge_a_to_b_des(a, b, l_tip, r_tip);
				else
					merge_a_to_b_asc(a, b, l_tip, r_tip);
				triangles -= 2;
			}
			if (triangles < 2 && triangles > 0)
			{
				send_a_to_b(a, b);
				flag = 1;
			}
			tips += tips;
			size /= 2;
		}
	}
}
