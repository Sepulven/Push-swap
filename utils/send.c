/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:38:04 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:55 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	send_el_to(t_list **a, t_list **b, int pos, char stack)
{
	if (stack == 'a')
	{
		send_el_to_top(a, b, pos, 'b');
		pa(a, b);
	}
	else if (stack == 'b')
	{
		send_el_to_top(a, b, pos, 'a');
		pb(a, b);
	}
}

void	send_el_to_top(t_list **a, t_list **b, int pos, char stack)
{
	int	list_size;

	if (stack == 'a')
		list_size = ft_lstsize(*a);
	else if (stack == 'b')
		list_size = ft_lstsize(*b);
	while (pos > (list_size - 1) / 2 && pos < list_size)
	{
		if (stack == 'a')
			rra(a);
		else if (stack == 'b')
			rrb(b);
		pos++;
	}
	while (pos <= (list_size - 1) / 2 && pos > 0)
	{
		if (stack == 'a')
			ra(a);
		else if (stack == 'b')
			rb(b);
		pos--;
	}
}

