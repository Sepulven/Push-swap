/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:52:51 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 15:47:57 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	print_list(t_list *head)
{
	while (head)
	{
		ft_printf("->[%d]", *(int *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}

char	*ft_insert_substring(char *main, const char *sub, size_t index)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!sub || index > ft_strlen(main) - 1)
		return (NULL);
	str = (char *)malloc(ft_strlen(main) + ft_strlen(sub) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < index)
	{
		str[i] = main[i];
		i++;
	}
	j = 0;
	while (sub[j])
		str[i++] = sub[j++];
	while (main[index])
		str[i++] = main[index++];
	str[i] = '\0';
	free(main);
	return (str);
}

int	issorted(t_list **list)
{
	t_list	*tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// We know that if one tip is decresent the other ir crescent
int	right_tip_size(t_list **list)
{
	t_list	*tmp;
	int		size;
	char	flag;

	if (!*list)
		return (0);
	flag = 'c';
	tmp = *list;
	size = 1;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		flag = 'd';
	while (tmp->next)
	{
		if (flag == 'c' && *(int *)tmp->content > *(int *)tmp->next->content)
			size = 0;
		else if (flag == 'd' && \
		*(int *)tmp->content < *(int *)tmp->next->content)
			size = 0;
		else
			size++;
		tmp = tmp->next;
	}
	return (size);
}

int	left_tip_size(t_list **list)
{
	t_list	*tmp;
	int		size;
	char	flag;

	if (!*list)
		return (0);
	flag = 'd';
	tmp = *list;
	size = 1;
	if (*(int *)tmp->content < *(int *)tmp->next->content)
		flag = 'c';
	while (tmp->next)
	{
		if (flag == 'd' && *(int *)tmp->content < *(int *)tmp->next->content)
			break ;
		if (flag == 'c' && *(int *)tmp->content > *(int *)tmp->next->content)
			break ;
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	send_n_a_to_b(t_list **a, t_list **b, int i)
{
	while (i > 0)
	{
		pb(a, b);
		i--;
	}
}

void	send_n_b_to_a(t_list **a, t_list **b, int i)
{
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}

void	send_a_to_b(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	while (i > 0)
	{
		pb(a, b);
		i--;
	}
}

void	send_b_to_a(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*b);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}
