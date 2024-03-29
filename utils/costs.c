/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:40:55 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 19:43:16 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

int	cost_send(int lst_size, int pos)
{
	if (lst_size < 0)
	{
		ft_printf("List size can't be negative.");
		exit(EXIT_FAILURE);
	}
	if (pos < (lst_size - 1) / 2)
		return (pos + 2);
	else
		return ((lst_size - 1) - pos + 2);
}

int	best_el(t_list *lst, int l_pos, int r_pos, t_sort_n *stat)
{
	int	pos[3];
	int	cost[3];
	int	lst_size;

	lst_size = ft_lstsize(lst);
	pos[0] = get_nth_greatness_pos(lst, l_pos, r_pos, l_pos + r_pos - 1);
	pos[1] = get_nth_greatness_pos(lst, l_pos, r_pos, l_pos + r_pos);
	pos[2] = get_nth_greatness_pos(lst, l_pos, r_pos, 1);
	cost[0] = cost_send(lst_size, pos[0]) + 1;
	cost[1] = cost_send(lst_size, pos[1]);
	cost[2] = cost_send(lst_size, pos[1]);
	stat->greatness = 'g';
	if (cost[0] < cost[1] && cost[0] <= cost[2])
	{
		stat->greatness = '2';
		return (pos[0]);
	}
	else if (cost[2] < cost[0] && cost[2] < cost[1])
	{
		stat->greatness = 's';
		return (pos[2]);
	}
	return (pos[1]);
}

void	calc_tips_size(t_sort_n *stat, int pos)
{
	if (pos < stat->l_side)
	{
		stat->r_side += pos;
		stat->l_side -= pos;
	}
	else if (pos >= stat->size - stat->r_side)
	{
		stat->l_side = stat->l_side + (stat->size - pos);
		stat->r_side = stat->r_side - (stat->size - pos);
	}
	stat->size--;
	stat->l_side--;
}
