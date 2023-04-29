/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:39:01 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/11 13:50:46 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECKER_H 
#  define CHECKER_H 1

# include "stdlib.h"
# include "unistd.h"
# include "libft/libft.h"
# include "operations/operations.h"

/*checker_utils.c*/
int	issorted(t_list **list);
int	validator(int argc, char *argv[]);
t_list *converter(int argc, char *argv[]);


# endif