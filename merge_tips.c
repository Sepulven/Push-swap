/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tips.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:16:19 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/06 14:58:13 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Merge tips regardless of the tips size; done 
// Merge tips regardless of the middle of the list; done
// TODO: To optimaze the code I need to pass a struct with the tips size and supposed functions;
// So I can make it asc or des
//TODO: I need to refactor all of it;
//		I can make the usage of pointer function, struct to pass the list
//		I could compare the nodes instead of passing the list to it
//		Basically create a new function

// There is a problem with the merge in the 15 el. case;

static	void	asc(t_manager manager)
{
	if ((*manager.r_tip > 0 && *(int *)(*manager.a)->content < *(int *)(manager.last)->content) || *manager.l_tip == 0)
	{
		manager.rrx(manager.a);
		*manager.r_tip -= 1;
	}
	else if (*manager.r_tip == 0 || *manager.l_tip > 0)
		*manager.l_tip -= 1;
	if (manager.to == 'a')
		manager.px(manager.b, manager.a);
	else if (manager.to == 'b')
		manager.px(manager.a, manager.b);
}

static	void	des(t_manager manager)
{
	if ((*manager.r_tip > 0 && *(int *)(*manager.a)->content > *(int *)(manager.last)->content) 
	|| *manager.l_tip == 0)
	{
		manager.rrx(manager.a);
		*manager.r_tip -= 1;
	}
	else if (*manager.r_tip == 0 || *manager.l_tip > 0)
		*manager.l_tip -= 1;
	if (manager.to == 'a')
		manager.px(manager.b, manager.a);
	else if (manager.to == 'b')
		manager.px(manager.a, manager.b);
}

void	merge_a_to_b_asc(t_list **a, t_list **b, int l_tip, int r_tip)
{
	while(l_tip > 0 || r_tip > 0)
		asc((t_manager){a, b, ft_lstlast(*a), &l_tip, &r_tip, &rra, &pb, 'b'});
}

void	merge_a_to_b_des(t_list **a, t_list **b, int l_tip, int r_tip)
{
	while(l_tip > 0 || r_tip > 0)
		des((t_manager){a, b, ft_lstlast(*a), &l_tip, &r_tip, &rra, &pb, 'b'});
}

void	merge_b_to_a_asc(t_list **a, t_list **b, int l_tip, int r_tip)
{
	while(l_tip > 0 || r_tip > 0)
		asc((t_manager){b, a, ft_lstlast(*b), &l_tip, &r_tip, &rrb, &pa, 'a'});
}

void	merge_b_to_a_des(t_list **a, t_list **b, int l_tip, int r_tip)
{
	while(l_tip > 0 || r_tip > 0)
		des((t_manager){b, a, ft_lstlast(*b), &l_tip, &r_tip, &rrb, &pa, 'a'});
}
