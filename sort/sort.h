/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:48:06 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 12:52:17 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H 1

# include "../libft/libft.h"
# include "../operations/operations.h"
# include "../utils/utils.h"

/*
typedef struct s_stat
{
	char	stack;
	char	order;
	int		range;
}	t_stat;
*/
typedef struct s_stat
{
	char	stack;
	char	order;
	int		range;
}	t_stat;

/*utils.c*/
int		diviser_value(t_list *lst, int range);
int		sub_diviser_value(t_list *lst, int range);

/*split_stack.c*/
void	split_stack(t_list **a, t_list **b, t_stat s);

/*split_stack_sorted.c*/
void	split_stack_diviser(t_list **a, t_list **b, int range, char stack);

/*tips.c*/
void	diviser_to_tips(t_list **a, t_list **b, int range, char stack);

/*tips_sorted.c*/
void	diviser_tips_sorted(t_list **a, t_list **b, int range, char stack);

#endif
