/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:23:28 by sehee             #+#    #+#             */
/*   Updated: 2021/11/05 00:27:40 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate_lt_3(int num_of_elements, int a_or_b, t_list_mark *ls_mark)
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

void	ra(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*tmp_ptr;

	if (ls_mark->op_flag < 3)
		ls_mark->op_flag = 3;
	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (num_of_elements <= 2)
		rotate_lt_3(num_of_elements, 1, ls_mark);
	else
	{
		tmp_ptr = ls_mark->cursor->prev;
		tmp_ptr->next = ls_mark->cursor->next;
		if (ls_mark->cursor != ls_mark->tail)
			ls_mark->cursor->next->prev = tmp_ptr;
		ls_mark->cursor->next = ls_mark->head;
		ls_mark->cursor->prev = ls_mark->head->prev;
		ls_mark->head->prev = ls_mark->cursor;
		ls_mark->head = ls_mark->head->prev;
		ls_mark->cursor = tmp_ptr;
		if (ls_mark->tail == ls_mark->head)
			ls_mark->tail = ls_mark->cursor;
	}
	if (ls_mark->op_flag == 3)
		ls_mark->op_flag = 0;
}

static void	move_in_rb(t_list_mark *ls_mark, t_node **tmp_ptr)
{
	if (ls_mark->cursor == NULL)
	{	
		*tmp_ptr = ls_mark->head;
		ls_mark->head = ls_mark->head->next;
	}
	else
	{	
		*tmp_ptr = ls_mark->cursor->next;
		ls_mark->cursor->next = (*tmp_ptr)->next;
	}	
}

void	rb(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*tmp_ptr;

	if (ls_mark->op_flag < 4)
		ls_mark->op_flag = 4;
	num_of_elements = count_elements_in_stack_b(ls_mark);
	if (num_of_elements <= 2)
		rotate_lt_3(num_of_elements, 2, ls_mark);
	else
	{
		move_in_rb(ls_mark, &tmp_ptr);
		tmp_ptr->next->prev = ls_mark->cursor;
		tmp_ptr->prev = ls_mark->tail;
		ls_mark->tail->next = tmp_ptr;
		tmp_ptr->next = NULL;
		ls_mark->tail = tmp_ptr;
	}
	if (ls_mark->op_flag == 4)
		ls_mark->op_flag = 0;
}

void	rr(t_list_mark *ls_mark)
{
	if (count_elements_in_stack_a(ls_mark) >= 2 \
		&& count_elements_in_stack_b(ls_mark) >= 2)
	{
		ls_mark->op_flag = 5;
		ra(ls_mark);
		rb(ls_mark);
		if (ls_mark->op_flag == 5)
			ls_mark->op_flag = 0;
	}
}
