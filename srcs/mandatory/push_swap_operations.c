/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:37:44 by sehee             #+#    #+#             */
/*   Updated: 2021/10/07 17:13:26 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements_in_stack_a(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*node_ptr;

	node_ptr = ls_mark->cursor;
	num_of_elements = 0;
	while(node_ptr != NULL)
	{
		num_of_elements++;
		node_ptr = node_ptr->prev;
	}
	return (num_of_elements);
}

int	count_elements_in_stack_b(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*node_ptr;

	node_ptr = ls_mark->cursor;
	num_of_elements = 0;
	while(node_ptr != ls_mark->tail)
	{
		num_of_elements++;
		node_ptr = node_ptr->next;
	}
	return (num_of_elements);
}

void	swap_stack_a(t_list_mark *ls_mark)
{
	t_node	*tmp_ptr;
	int		num_of_elements;

	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (num_of_elements < 2)
		return ;
	else if (num_of_elements == 2)
	{
		if (ls_mark->cursor == ls_mark->tail)
		{

		}
		else
		{
			
		}

	}
	else
	{
		if (ls_mark->cursor != ls_mark->tail)
		{
			tmp_ptr = ls_mark->cursor->prev;
			tmp_ptr->next = ls_mark->cursor->next;
			ls_mark->cursor->prev = tmp_ptr->prev;
			tmp_ptr->prev->next = ls_mark->cursor;
			ls_mark->cursor->next->prev = tmp_ptr;
			ls_mark->cursor->next = tmp_ptr;
			tmp_ptr->prev = ls_mark->cursor;
			ls_mark->cursor = tmp_ptr;
		}
		else
		{
			tmp_ptr = ls_mark->cursor->prev;
			ls_mark->cursor->prev = tmp_ptr->prev;
			tmp_ptr->prev->next = ls_mark->cursor;
			tmp_ptr->prev = ls_mark->cursor;
			ls_mark->cursor->next = tmp_ptr;
			tmp_ptr->next = NULL;
			ls_mark->cursor = tmp_ptr;
		}
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_stack_b(t_list_mark *ls_mark)
{
	t_node	*node_ptr;
	int		num_of_elements;

	num_of_elements = count_elements_in_stack_b(ls_mark);
	node_ptr = ls_mark->cursor;
	if (num_of_elements < 2)
		ft_putstr_fd("Unable to swap on stack b", 2);
	else if (num_of_elements == 2)
	{
		ls_mark->cursor = ls_mark->tail;
		swap_stack_a(ls_mark);
		ls_mark->cursor = ls_mark->tail->prev->prev;
	}
	else
	{
		ls_mark->cursor = ls_mark->cursor->next->next;
		swap_stack_a(ls_mark);
		ls_mark->cursor = ls_mark->cursor->prev->prev;
	}
	ft_putstr_fd("sb\n", 1);
}

void	swap_stack_a_and_b(t_list_mark *ls_mark)
{
	swap_stack_a(ls_mark);
	swap_stack_b(ls_mark);
	ft_putstr_fd("ss\n", 1);
}
