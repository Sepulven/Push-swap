/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_own_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:50:11 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 00:29:28 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sort.h"

static void	sort_three_a(t_list **a, t_list **b)
{
	(void)b;
	if (!issorted(a) && *(int *)(*a)->content > *(int *)(*a)->next->content
	&& !(*(int*)(*a)->next->content > *(int*)(*a)->next->next->content))
		sa(a);
	else if (!issorted(a) && (*(int *)(*a)->content > \
	*(int *)(*a)->next->next->content))
		rra(a);
	if (!issorted(a) && (*(int *)(*a)->next->content > \
	*(int *)(*a)->next->next->content))
	{
		rra(a);
		sa(a);
	}
}

void	sort_n_own_stack(t_list **a, t_list **b)
{
	int	stack_size;
	int	tmp;
	int	pos_smallest;

	tmp = 0;
	stack_size = ft_lstsize(*a);
	while (stack_size - 3)
	{
		pos_smallest = get_nth_greatness_pos(*a, stack_size, 0, 1);
		send_el_to(a, b, pos_smallest, 'b');
		stack_size--;
		tmp++;
	}
	sort_three_a(a, b);
	while (tmp)
	{
		pa(a, b);
		tmp--;
	}
}
