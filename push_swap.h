/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:13:59 by asepulve          #+#    #+#             */
/*   Updated: 2023/02/22 04:31:48 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H 1

# include "libft/libft.h"
# include <time.h> //delete it

int		ft_isnum(char *num);
t_list	*converter(int argc, char *argv[]);
int		check_limit(char *num);
int		validator(int argc, char *argv[]);

void	sort_three_des(t_list **list);
void	sort_three_asc(t_list **list);
void	print_list(t_list *head);

void	sa(t_list **list);
void	pa(t_list **a, t_list **b);
void	ra(t_list **list);
void	rra(t_list **list);

void	sb(t_list **list);
void	pb(t_list **a, t_list **b);
void	rb(t_list **list);
void	rrb(t_list **list);

t_list	*pop_head(t_list **list);
t_list  *pop_tail(t_list **list);
void	rrr(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
#endif
