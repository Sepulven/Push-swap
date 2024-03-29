/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatness.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:36:21 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/03 19:36:10 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

static void	populate_sub_stack(t_list *lst, int *stack, int l_side, int r_side)
{
	int	i;
	int	index_holder;
	int	lst_size;

	lst_size = ft_lstsize(lst);
	i = 0;
	while (i < l_side && lst)
	{
		stack[i++] = *(int *)lst->content;
		lst = lst->next;
	}
	index_holder = i;
	while (i < lst_size - r_side && lst)
	{
		lst = lst->next;
		i++;
	}
	while (i < lst_size && lst)
	{
		stack[index_holder++] = *(int *)lst->content;
		i++;
		lst = lst->next;
	}
}

int	*create_sub_stack(t_list *lst, int l_side, int r_side)
{
	int	*stack;

	if (l_side + r_side < 1)
		return (NULL);
	stack = malloc((l_side + r_side) * sizeof (int));
	if (!stack)
		return (NULL);
	populate_sub_stack(lst, stack, l_side, r_side);
	return (stack);
}

static	void	err(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

static void	init_val(int *i, int *j, int **sub_stack)
{
	*sub_stack = NULL;
	*i = 0;
	*j = 0;
}

int	get_nth_greatness_value(t_list *lst, int l_side, \
	int r_side, int greatness)
{
	int	i;
	int	j;
	int	*sub_stack;

	init_val(&i, &j, &sub_stack);
	if (greatness > l_side + r_side || greatness < 0)
		err("Greatness out of range.\n");
	sub_stack = create_sub_stack(lst, l_side, r_side);
	if (!sub_stack)
		err("We couldn't create the sub_stack");
	while (i < l_side + r_side)
	{
		j = 0;
		while (j < l_side + r_side - 1)
		{
			if (sub_stack[j] > sub_stack[j + 1])
				ft_swap(&sub_stack[j], &sub_stack[j + 1]);
			j++;
		}
		i++;
	}
	j = sub_stack[greatness - 1];
	free(sub_stack);
	return (j);
}
