/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:53:10 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 17:11:47 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H 1

# include "../operations/operations.h"
# include "../libft/libft.h"

# define PING write(1, "PING\n", 6);

typedef struct s_sort_n
{
	int		l_side;
	int		r_side;
	char	stack;
	char	greatness;
}	t_sort_n;

/*utils.c*/
void	ft_swap(int *x, int *y);
char	*ft_insert_substring(char *main, const char *sub, size_t index);
void	print_list(t_list *head);
int		issorted(t_list **list);
int		right_tip_size(t_list **list);
int		left_tip_size(t_list **list);
void	send_a_to_b(t_list **a, t_list **b);
void	send_b_to_a(t_list **a, t_list **b);
void	send_n_a_to_b(t_list **a, t_list **b, int i);
void	send_n_b_to_a(t_list **a, t_list **b, int i);
char	*invert_map(char *map);

/*greatness.c*/
int		get_nth_greatness_pos(t_list *lst, int l_side, \
		int r_side, int greatness);
int		get_nth_greatness_value(t_list *lst, int l_side, int r_side, \
		int greatness);
int		*create_sub_stack(t_list *lst, int l_side, int r_side);

/*costs.c*/
int		cost_send(int lst_size, int pos);
int		best_el(t_list *lst, int l_pos, int r_pos, t_sort_n *stat);
void	calc_tips_size(t_sort_n *stat, int pos, int *size);

/*checker.c*/
void	checker(t_list **a, t_list **b, t_sort_n *stat, int *size);

/*validator.c*/
int		ft_isnum(char *num);
t_list	*converter(int argc, char *argv[]);
int		check_limit(char *num);
int		validator(int argc, char *argv[]);

/*map.c*/
char	*create_map(int num);

/*send.c*/
void	send_el_to(t_list **a, t_list **b, int pos, char stack);
void	send_el_to_top(t_list **a, t_list **b, int pos, char stack);

/*find.c*/
int		find_smallest(t_list **list);
int		find_greatest(t_list **list);
int		find_greatest_on_tips(t_list *head, int l_tip, int r_tip);
int		find_smallest_on_tips(t_list *head, int l_tip, int r_tip);
t_list	*find_node(t_list *head, int pos);

/*tips_map.c*/
char	**create_tips_map(int el);
char	**tips_map(char **map);
#endif