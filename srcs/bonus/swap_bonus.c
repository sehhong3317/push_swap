/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:37:44 by sehee             #+#    #+#             */
/*   Updated: 2021/11/05 00:28:05 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	move_in_sa(t_list_mark *ls_mark, int num_of_elements, \
	t_node *tmp_ptr)
{
	tmp_ptr->next = ls_mark->cursor->next;
	if (num_of_elements > 2)
	{
		ls_mark->cursor->prev = tmp_ptr->prev;
		tmp_ptr->prev->next = ls_mark->cursor;
	}
	tmp_ptr->prev = ls_mark->cursor;
	ls_mark->cursor->next = tmp_ptr;
	tmp_ptr->next->prev = tmp_ptr;
	if (num_of_elements == 2)
	{	
		ls_mark->cursor->prev = NULL;
		ls_mark->head = ls_mark->cursor;
	}
	ls_mark->cursor = tmp_ptr;
}

void	sa(t_list_mark *ls_mark)
{
	t_node	*tmp_ptr;
	int		num_of_elements;

	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (num_of_elements < 2)
		return ;
	tmp_ptr = ls_mark->cursor->prev;
	if (ls_mark->cursor != ls_mark->tail)
		move_in_sa(ls_mark, num_of_elements, tmp_ptr);
	else
	{
		ls_mark->cursor->prev = tmp_ptr->prev;
		if (num_of_elements > 2)
			tmp_ptr->prev->next = ls_mark->cursor;
		tmp_ptr->prev = ls_mark->cursor;
		ls_mark->cursor->next = tmp_ptr;
		tmp_ptr->next = NULL;
		ls_mark->tail = tmp_ptr;
		ls_mark->cursor = tmp_ptr;
		if (num_of_elements == 2)
			ls_mark->head = tmp_ptr->prev;
	}
	if (ls_mark->op_flag == 0)
		ls_mark->op_flag = 0;
}

void	sb(t_list_mark *ls_mark)
{
	int		num_of_elements;

	if (!ls_mark->op_flag)
		ls_mark->op_flag = 1;
	num_of_elements = count_elements_in_stack_b(ls_mark);
	if (num_of_elements < 2)
	{	
		ls_mark->op_flag = 0;
		return ;
	}
	if (ls_mark->cursor != NULL)
		ls_mark->cursor = ls_mark->cursor->next->next;
	else
		ls_mark->cursor = ls_mark->head->next;
	sa(ls_mark);
	ls_mark->cursor = ls_mark->cursor->prev->prev;
	if (ls_mark->op_flag == 1)
		ls_mark->op_flag = 0;
}

void	ss(t_list_mark *ls_mark)
{
	if (count_elements_in_stack_a(ls_mark) >= 2 \
		&& count_elements_in_stack_b(ls_mark) >= 2)
	{
		ls_mark->op_flag = 2;
		sa(ls_mark);
		sb(ls_mark);
		if (ls_mark->op_flag == 2)
			ls_mark->op_flag = 0;
	}
}
