/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:48:06 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 12:28:58 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H 1

# include "../libft/libft.h"
# include "../operations/operations.h"
# include "../utils/utils.h"

/*pre_sort.c*/
char	**pre_sort(t_list **a, t_list **b, int n);

/*sort_with_diviser.c*/
void	sort_n(t_list **a, t_list **b, \
		int (*f)(t_list *, int, int), t_sort_n stat);
void	split_with_diviser(t_list **a, t_list **b, int range, char stack);
int		diviser_value(t_list *list, int range);

/*split_stack.c*/
void	split_stack(t_list **a, t_list **b, char stack);

/*split_stack_sorted.c*/
void	split_stack_diviser(t_list **a, t_list **b, int range, char stack);

/*utils.c*/
int		diviser_value(t_list *lst, int range);
int		sub_diviser_value(t_list *lst, int range);

/*tips.c*/
void	diviser_to_tips(t_list **a, t_list **b, int range, char stack);

/*tips_sorted.c*/
void	diviser_tips_sorted(t_list **a, t_list **b, int range, char stack);

#endif
