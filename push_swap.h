/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:13:59 by asepulve          #+#    #+#             */
/*   Updated: 2023/03/03 19:02:44 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 1

# include "libft/libft.h"
# include <time.h> //delete it

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

/*main.c*/
char	*ft_insert_substring(char *main, const char *sub, size_t index);

/*sort.c*/
char	*map_pre_sort(int size);
void	pre_sort_a_to_b(t_list **a, t_list **b, int size);


/*sort_three.c*/
void	sort_three_des(t_list **a, t_list **b);
void	sort_three_asc(t_list **a, t_list **b);

/*merge.c*/
int		issorted(t_list **list);
void	merge_all(t_list **a, t_list **b);
int		right_tip_size(t_list **list);
int		left_tip_size(t_list **list);

/*merge_tips.c*/
void	merge_a_to_b_asc(t_list **a, t_list **b, int l_tip, int r_tip);
void	merge_a_to_b_des(t_list **a, t_list **b, int l_tip, int r_tip);
void	merge_b_to_a_asc(t_list **a, t_list **b, int l_tip, int r_tip);
void	merge_b_to_a_des(t_list **a, t_list **b, int l_tip, int r_tip);

/*validator.c*/
int		ft_isnum(char *num);
t_list	*converter(int argc, char *argv[]);
int		check_limit(char *num);
int		validator(int argc, char *argv[]);

/*utils.c*/
void	print_list(t_list *head);
void	send_a_to_b(t_list **a, t_list **b);
void	send_b_to_a(t_list **a, t_list **b);

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
