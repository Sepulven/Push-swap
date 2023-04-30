/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/30 18:29:33 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sub_stack(t_list **a, t_list **b, t_sort_n stat)
{
	int		pos;
	int		size;

	size = ft_lstsize(*b);
	while (stat.l_side + stat.r_side > 0 && size)
	{
		pos = best_el(*b, stat.l_side, stat.r_side, &stat);
		send_el_to(a, b, pos, 'a'); 
		calc_tips_size(&stat, pos, &size);
		checker(a, b, &stat, &size);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		lst_size;
	int		i;

	a = NULL;
	b = NULL;
	(void)lst_size;
	(void)i;
	(void)b;
	if (!validator(argc, argv))
		return (write(2, "Error1\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error2\n", 7));
	// split_stack_diviser(&a, &b, (t_stat){'a', 'c', 100});
	// diviser_tips(&a, &b, (t_stat){'a', 'c', 25});
	// diviser_tips(&a, &b, (t_stat){'a', 'c', 25});
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 12});
	// i = 0;
	// while (i++ < 13)
	// 	rra(&a);
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 13});
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 12});
	// i = 0;
	// while (i++ < 13)
	// 	rra(&a);
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 13});
	// diviser_tips_sorted(&a, &b, (t_stat){'b', 'c', 50});
	// sort_sub_stack(&a, &b, (t_sort_n){50, 50, 'b', 'g'});
	// split_stack_diviser(&a, &b, (t_stat){'a', 'c', 500});
	// diviser_tips(&a, &b, (t_stat){'a', 'c', 125});
	// diviser_tips(&a, &b, (t_stat){'a', 'c', 125});
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 62});
	// i = 0;
	// while (i++ < 63)
	// 	rra(&a);
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 63});
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 62});
	// i = 0;
	// while (i++ < 63)
	// 	rra(&a);
	// diviser_tips(&a, &b, (t_stat){'b', 'd', 63});
	// diviser_tips_sorted(&a, &b, (t_stat){'b', 'c', 250});
	// sort_sub_stack(&a, &b, (t_sort_n){250, 250, 'b', 'g'});
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (1);
}

	// diviser_to_tips(&a, &b, 13, 'b');
	// diviser_to_tips(&a, &b, 13, 'b');
	// diviser_to_tips(&a, &b, 25, 'b');
	// i = 0;
	// while (i < 25)
	// {
	// 	send_el_to_top(&a, &b, ft_lstsize(a) - 1, 'a');
	// 	i++;
	// }
	// diviser_to_tips(&a, &b, 25, 'b');
	// diviser_tips_sorted(&a, &b, 50, 'b');
	