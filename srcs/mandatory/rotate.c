/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:23:28 by sehee             #+#    #+#             */
/*   Updated: 2021/10/12 15:51:51 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*tmp_ptr;

	if (ls_mark->op_flag < 3)
		ls_mark->op_flag = 3;
	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (num_of_elements < 2)
	{	
		ls_mark->op_flag = 0;
		return ;
	}
	else if (num_of_elements == 2)
		sa(ls_mark);
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
		if (ls_mark->cursor == ls_mark->head)
			ls_mark->tail = ls_mark->cursor;
	}
	check_flag_and_print(3, "ra\n", ls_mark);
}

void	rb(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*tmp_ptr;

	if (ls_mark->op_flag < 4)
	ls_mark->op_flag = 4;
	num_of_elements = count_elements_in_stack_b(ls_mark);
	if (num_of_elements < 2)
	{
		ls_mark->op_flag = 0;
		return ;
	}
	else if (num_of_elements == 2)
		sb(ls_mark);
	else
	{
		if (ls_mark->cursor == NULL)
		{	
			tmp_ptr = ls_mark->head;
			ls_mark->head = ls_mark->head->next;
		}
		else
		{	
			tmp_ptr = ls_mark->cursor->next;
			ls_mark->cursor->next = tmp_ptr->next;
		}
		tmp_ptr->next->prev = ls_mark->cursor;
		tmp_ptr->prev = ls_mark->tail;
		ls_mark->tail->next = tmp_ptr;
		tmp_ptr->next = NULL;
		ls_mark->tail = tmp_ptr;
	}
	check_flag_and_print(4, "rb\n", ls_mark);
}

void	rr(t_list_mark *ls_mark)
{
	if (count_elements_in_stack_a(ls_mark) >= 2 \
		&& count_elements_in_stack_b(ls_mark) >= 2)
	{
		ls_mark->op_flag = 5;
		rotate_stack_a(ls_mark);
		rotate_stack_b(ls_mark);
		check_flag_and_print(5, "rr\n", ls_mark);
	}
}