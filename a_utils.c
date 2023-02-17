/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:58:45 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/17 12:32:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sa(t_list **a)
{
	t_list *tmp;

	//save second node in tmp;
	//first point to the third;
	//second node point to first;
	//the address of the head is overwritten;
	tmp = *a->next;
	*a->next = *a->next->next;
	tmp->next = *a;
	a = &tmp;
	ft_printf("sa\n");
}
void	pa(t_list **a)
{
	ft_printf("\n");
}
void	ra(t_list **a)
{
	ft_printf("\n");
}
void	rra(t_list **a)
{
	ft_printf("\n");
}
