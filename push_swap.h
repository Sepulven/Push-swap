/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:13:59 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 16:20:31 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 1

# include "libft/libft.h"
# include "operations/operations.h"
# include "utils/utils.h"
# include "sort/sort.h"

typedef struct s_manager
{
	t_list	**a;
	t_list	**b;
	t_list	*last;
	int		*l_tip;
	int		*r_tip;
	void	(*rrx)(t_list **);
	void	(*px)(t_list **, t_list **);
	char	to;
}	t_manager;

#endif
