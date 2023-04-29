/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:40:25 by asepulve          #+#    #+#             */
/*   Updated: 2023/04/29 15:51:53 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	find_smallest(t_list **list)
{
	t_list	*current;
	t_list	*smallest;
	int		smallest_pos;
	int		i;

	i = 0;
	current = *list;
	smallest = current;
	smallest_pos = 0;
	while (current)
	{
		if (*(int *)current->content < *(int *)smallest->content)
		{
			smallest = current;
			smallest_pos = i;
		}
		current = current->next;
		i++;
	}
	return (smallest_pos);
}

int	find_greatest(t_list **list)
{
	t_list	*current;
	t_list	*greatest;
	int		greatest_pos;
	int		i;

	i = 0;
	current = *list;
	greatest = current;
	greatest_pos = 0;
	while (current)
	{
		if (*(int *)current->content > *(int *)greatest->content)
		{
			greatest = current;
			greatest_pos = i;
		}
		current = current->next;
		i++;
	}
	return (greatest_pos);
}

t_list	*find_node(t_list *head, int pos)
{
	int	i;

	i = 0;
	while (head)
	{
		if (i == pos)
			return (head);
		i++;
		head = head->next;
	}
	return (NULL);
}

//Nesta situação trabalharemos sempre com as pos.
int	find_greatest_on_tips(t_list *head, int l_pos, int r_pos)
{
	int		greatest;
	int		greatest_pos;
	int		last_pos;
	int		i;
	t_list	*tmp;

	last_pos = ft_lstsize(head) - 1;
	tmp = head;
	greatest = *(int *)head->content;
	greatest_pos = 0;
	i = 0;
	//Atenção
	if (l_pos < 0 || r_pos < 0)
		return (-1);
	while (i <= l_pos && head)
	{
		if (greatest < *(int *)head->content)
		{
			greatest = *(int *)head->content;
			greatest_pos = i;
		}
		i++;
		head = head->next;
	}
	if (r_pos < 0)
		return (greatest_pos);
	head = find_node(tmp, last_pos - r_pos);
	if (!head)
	{
		ft_printf("greatest nao encontramos a node %d %d\n", l_pos, r_pos);
		exit(EXIT_FAILURE);
	}
	if (l_pos < 0)
	{
		greatest = *(int *)head->content;
		greatest_pos = last_pos - r_pos;
	}
	while (r_pos >= 0 && head)
	{
		if (greatest < *(int *)head->content)
		{
			greatest = *(int *)head->content;
			greatest_pos = last_pos - r_pos;
		}
		r_pos--;
		head = head->next;
	}
	return (greatest_pos);
}

int	find_smallest_on_tips(t_list *head, int l_pos, int r_pos)
{
	int		smallest;
	int		smallest_pos;
	int		last_pos;
	int		i;
	t_list	*tmp;

	last_pos = ft_lstsize(head) - 1;
	tmp = head;
	smallest = *(int *)head->content;
	smallest_pos = 0;
	i = 0;
	while (i <= l_pos && head)
	{
		if (smallest > *(int *)head->content)
		{
			smallest = *(int *)head->content;
			smallest_pos = i;
		}
		i++;
		head = head->next;
	}
	if (r_pos < 0)
		return (smallest_pos);
	head = find_node(tmp, last_pos - r_pos);
	if (!head)
	{
		ft_printf("smallest nao encontramos a node %d %d\n", l_pos, r_pos);
		exit(EXIT_FAILURE);
	}
	if (l_pos < 0)
	{
		smallest = *(int *)head->content;
		smallest_pos = last_pos - r_pos;
	}
	while (r_pos >= 0 && head)
	{
		if (smallest > *(int *)head->content)
		{
			smallest = *(int *)head->content;
			smallest_pos = last_pos - r_pos;
		}
		r_pos--;
		head = head->next;
	}
	return (smallest_pos);
}


