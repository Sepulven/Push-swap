/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:45:31 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 16:01:00 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H 1

# include "../libft/libft.h"

/*a_utils.c*/
void	sa(t_list **list);
void	pa(t_list **a, t_list **b);
void	ra(t_list **list);
void	rra(t_list **list);

/*b_utils.c*/
void	sb(t_list **list);
void	pb(t_list **a, t_list **b);
void	rb(t_list **list);
void	rrb(t_list **list);

/*ab_utils.c*/
void	rrr(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
t_list	*pop_head(t_list **list);
t_list	*pop_tail(t_list **list);
#endif