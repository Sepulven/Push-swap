/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:35 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 16:59:39 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

/*
	* g = greatest; 2 = second-greatest; s = smallest;
*/
void	checker(t_list **a, t_list **b, t_sort_n *stat, int *size)
{
	int			posx[2];
	int			cost[2];
	int			lst_size;
	int			sec_tip;
	int			buff_tip;

	if (stat->greatness != '2')
		return ;
	posx[1] = best_el(*b, stat->l_side, stat->r_side, stat);
	sec_tip = 0;
	while (stat->greatness == '2')
	{
		lst_size = ft_lstsize(*b);
		posx[0] = get_nth_greatness_pos(*b, stat->l_side, stat->r_side, \
		stat->l_side + stat->r_side - 1);
		posx[1] = get_nth_greatness_pos(*b, stat->l_side, stat->r_side, \
		stat->l_side + stat->r_side);
		cost[0] = cost_send(lst_size, posx[0]) + 2;
		cost[1] = cost_send(lst_size, posx[1]);
		if (cost[0] >= cost[1])
			stat->greatness = 'g';
		else
		{
			send_el_to(a, b, posx[0], 'a');
			calc_tips_size(stat, posx[0], size);
			sec_tip++;
		}
	}
	lst_size = ft_lstsize(*b);
	buff_tip = sec_tip;
	while (buff_tip-- > 0)
		ra(a);
	if (stat->greatness == 'g')
	{
		send_el_to(a, b, posx[1], 'a');
		calc_tips_size(stat, posx[1], size);
		sa(a);
	}
	lst_size = ft_lstsize(*b);
	while (sec_tip-- > 0)
		rra(a);
}
