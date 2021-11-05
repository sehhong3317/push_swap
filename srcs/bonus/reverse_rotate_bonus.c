/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:44:27 by sehee             #+#    #+#             */
/*   Updated: 2021/11/05 00:26:48 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate_lt_3(int num_of_elements, int a_or_b, \
	t_list_mark *ls_mark)
{
	if (num_of_elements < 2)
	{
		ls_mark->op_flag = 0;
		return ;
	}
	if (a_or_b == 1)
		sa(ls_mark);
	else
		sb(ls_mark);
}

void	rra(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*tmp_ptr;

	if (ls_mark->op_flag < 6)
		ls_mark->op_flag = 6;
	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (num_of_elements <= 2)
		reverse_rotate_lt_3(num_of_elements, 1, ls_mark);
	else
	{
		tmp_ptr = ls_mark->head->next;
		tmp_ptr->prev = NULL;
		ls_mark->head->next = ls_mark->cursor->next;
		ls_mark->head->prev = ls_mark->cursor;
		if (ls_mark->cursor != ls_mark->tail)
			ls_mark->cursor->next->prev = ls_mark->head;
		ls_mark->cursor->next = ls_mark->head;
		ls_mark->head = tmp_ptr;
		ls_mark->cursor = ls_mark->cursor->next;
		if (ls_mark->cursor->next == NULL)
			ls_mark->tail = ls_mark->cursor;
	}
	if (ls_mark->op_flag == 6)
		ls_mark->op_flag = 0;
}

static void	move_in_rrb(t_list_mark *ls_mark)
{
	if (!ls_mark->cursor)
	{
		ls_mark->tail->next = ls_mark->head;
		ls_mark->head->prev = ls_mark->tail;
		ls_mark->head = ls_mark->tail;
	}
	else
	{
		ls_mark->tail->next = ls_mark->cursor->next;
		ls_mark->cursor->next->prev = ls_mark->tail;
		ls_mark->cursor->next = ls_mark->tail;
	}	
}

void	rrb(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*tmp_ptr;

	if (ls_mark->op_flag < 7)
		ls_mark->op_flag = 7;
	num_of_elements = count_elements_in_stack_b(ls_mark);
	if (num_of_elements <= 2)
		reverse_rotate_lt_3(num_of_elements, 2, ls_mark);
	else
	{
		tmp_ptr = ls_mark->tail->prev;
		tmp_ptr->next = ls_mark->tail->next;
		move_in_rrb(ls_mark);
		ls_mark->tail->prev = ls_mark->cursor;
		ls_mark->tail = tmp_ptr;
	}
	if (ls_mark->op_flag == 7)
		ls_mark->op_flag = 0;
}

void	rrr(t_list_mark *ls_mark)
{
	if (count_elements_in_stack_a(ls_mark) >= 2 \
		&& count_elements_in_stack_b(ls_mark) >= 2)
	{
		ls_mark->op_flag = 8;
		rra(ls_mark);
		rrb(ls_mark);
		if (ls_mark->op_flag == 8)
			ls_mark->op_flag = 0;
	}	
}
