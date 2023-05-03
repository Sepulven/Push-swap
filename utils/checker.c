/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:35 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 13:13:00 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

static void	second_greatest_util_2(t_list **a, t_list **b, \
		int *sec_tip, t_sort_n *stat)
{
	int			posx[2];
	int			cost[2];
	int			lst_size;

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
			calc_tips_size(stat, posx[0]);
			(*sec_tip)++;
		}
	}
	posx[0] = (*sec_tip);
	while (posx[0]-- > 0)
		ra(a);
}

void	second_greatest_util_1(t_list **a, t_list **b, \
		int *r_a_tip, t_sort_n *stat)
{
	int	pos;

	pos = best_el(*b, stat->l_side, stat->r_side, stat);
	while (stat->greatness == 's')
	{
		send_el_to(a, b, pos, 'b');
		calc_tips_size(stat, pos);
		ra(a);
		(*r_a_tip)++;
		pos = best_el(*a, stat->l_side, stat->r_side, stat);
	}
}

void	second_greatest_case(t_list **a, t_list **b, \
		t_sort_n *stat, int *r_a_tip)
{
	int			sec_tip;
	int			pos;

	(void)r_a_tip;
	pos = best_el(*b, stat->l_side, stat->r_side, stat);
	sec_tip = 0;
	if (stat->greatness == 's')
		second_greatest_util_1(a, b, r_a_tip, stat);
	pos = best_el(*b, stat->l_side, stat->r_side, stat);
	if (stat->greatness == '2')
		second_greatest_util_2(a, b, &sec_tip, stat);
	pos = get_nth_greatness_pos(*b, stat->l_side, stat->r_side, \
		stat->l_side + stat->r_side);
	if (stat->greatness == 'g')
	{
		send_el_to(a, b, pos, 'a');
		calc_tips_size(stat, pos);
		sa(a);
	}
	while (sec_tip-- > 0)
		rra(a);
}

void	smallest_case(t_list **a, t_list **b, t_sort_n *stat, int *r_a_tip)
{
	(void)b;
	(void)stat;
	ra(a);
	(*r_a_tip)++;
}

/*
	* g = greatest; 2 = second-greatest; s = smallest;
*/
void	checker(t_list **a, t_list **b, t_sort_n *stat, int *r_a_tip)
{
	if (stat->greatness == '2')
		second_greatest_case(a, b, stat, r_a_tip);
	if (stat->greatness == 's')
		smallest_case(a, b, stat, r_a_tip);
}
