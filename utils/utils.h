/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:53:10 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 02:09:07 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H 1

# include "../operations/operations.h"
# include "../libft/libft.h"

typedef struct s_sort_n
{
	int		l_side;
	int		r_side;
	char	stack;
	char	greatness;
	int		size;
}	t_sort_n;

/*utils.c*/
void	ft_swap(int *x, int *y);
void	print_list(t_list *head);
int		issorted(t_list **list);

/*greatness.c*/
int		get_nth_greatness_pos(t_list *lst, int l_side, \
		int r_side, int greatness);
int		get_nth_greatness_value(t_list *lst, int l_side, int r_side, \
		int greatness);
int		*create_sub_stack(t_list *lst, int l_side, int r_side);

/*costs.c*/
int		cost_send(int lst_size, int pos);
int		best_el(t_list *lst, int l_pos, int r_pos, t_sort_n *stat);
void	calc_tips_size(t_sort_n *stat, int pos);

/*checker.c*/
void	checker(t_list **a, t_list **b, t_sort_n *stat, int *size);

/*validator.c*/
int		ft_isnum(char *num);
t_list	*converter(int argc, char *argv[]);
int		check_limit(char *num);
int		validator(int argc, char *argv[]);

/*send.c*/
void	send_el_to(t_list **a, t_list **b, int pos, char stack);
void	send_el_to_top(t_list **a, t_list **b, int pos, char stack);
#endif