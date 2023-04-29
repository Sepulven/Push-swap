/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:48:06 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 16:23:39 by asepulve         ###   ########.fr       */
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
void	sort_with_diviser(t_list **a, t_list **b, \
		int range, char order, char stack);

#endif
