/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements_in_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:06:42 by sehee             #+#    #+#             */
/*   Updated: 2021/10/08 09:23:16 by sehee            ###   ########seoul.kr  */
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

	if (!ls_mark->cursor)
		node_ptr = ls_mark->head;	
	else
		node_ptr = ls_mark->cursor;
	num_of_elements = 0;
	while(node_ptr != ls_mark->tail)
	{
		num_of_elements++;
		node_ptr = node_ptr->next;
	}
	if (!ls_mark->cursor)
		return (num_of_elements + 1);
	return (num_of_elements);
}
