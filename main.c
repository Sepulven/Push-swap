/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:23 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/02 02:23:01 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sub_stack(t_list **a, t_list **b, t_sort_n stat)
{
	int		pos;
	int		r_a_tip;

	r_a_tip = 0;
	while (stat.l_side + stat.r_side > 1 && stat.size)
	{
		pos = best_el(*b, stat.l_side, stat.r_side, &stat);
		send_el_to(a, b, pos, 'a');
		calc_tips_size(&stat, pos);
		checker(a, b, &stat, &r_a_tip);
	}
	pa(a, b);
	while (r_a_tip-- > 0)
		rra(a);
}

static void	init_stacks_size(int *a, int*b, int size)
{
	a[0] = size / 2;
	b[0] = size / 2 + (size % 2 != 0);
	a[1] = a[0] / 2;
	b[1] = b[0] / 2;
	a[2] = a[1] / 2;
	b[2] = b[1] / 2;
}

void	push_swap(t_list **a, t_list **b, int size)
{
	int	i;
	int	stack_a[3];
	int	stack_b[3];

	init_stacks_size(stack_a, stack_b, size);
	split_stack_diviser(a, b, (t_stat){'a', 'c', size});
	diviser_tips(a, b, (t_stat){'a', 'c', stack_b[1]});
	diviser_tips(a, b, (t_stat){'a', 'c', stack_b[1] + (stack_b[0] % 2 != 0)});
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2]});
	i = 0;
	while (i++ < stack_b[2] + (stack_b[1] % 2 != 0))
		rra(a);
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2] + (stack_b[1] % 2 != 0)});
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2]});
	i = 0;
	while (i++ < stack_b[2] + (stack_b[1] % 2 != 0))
		rra(a);
	diviser_tips(a, b, (t_stat){'b', 'd', stack_b[2] + (stack_b[1] % 2 != 0)});
	split_stack_diviser(a, b, (t_stat){'a', 'c', stack_a[0] + (size % 2 != 0)});
	diviser_tips_sorted(a, b, (t_stat){'b', 'c', \
	stack_a[1] + (stack_a[0] % 2 != 0)});
	sort_sub_stack(a, b, (t_sort_n){size, 0, \
	'b', 'g', ft_lstsize(*b)});
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
		return (write(2, "Error\n", 7));
	a = converter(argc, argv);
	if (!a)
		return (write(2, "Error\n", 7));
	if (argc - 1 == 2 && !issorted(&a))
		sa(&a);
	if (argc - 1 < 50 && argc - 1 > 2)
		sort_n_own_stack(&a, &b);
	else if (argc - 1 > 50)
		push_swap(&a, &b, argc - 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
