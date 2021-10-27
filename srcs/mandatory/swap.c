/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:37:44 by sehee             #+#    #+#             */
/*   Updated: 2021/10/12 15:43:47 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list_mark *ls_mark)
{
	int	num_of_elements;
	int	tmp_data;

	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (num_of_elements < 2)
		return ;
	else
	{
		tmp_data = ls_mark->cursor->data;
		ls_mark->cursor->data = ls_mark->cursor->prev->data;
		ls_mark->cursor->prev->data = tmp_data;
	}
	check_flag_and_print(0, "sa\n", ls_mark);
}

void	sb(t_list_mark *ls_mark)
{
	int	num_of_elements;
	int	tmp_data;

	if (!ls_mark->op_flag)
		ls_mark->op_flag = 1;
	num_of_elements = count_elements_in_stack_b(ls_mark);
	if (num_of_elements < 2)
	{
		ls_mark->op_flag = 0;
		return ;
	}
	else
	{
		tmp_data = ls_mark->cursor->next->next->data;
		ls_mark->cursor->next->next->data = ls_mark->cursor->next->data;
		ls_mark->cursor->next->data = tmp_data;
	}
	check_flag_and_print(1, "sb\n", ls_mark);
}

// void	swap_stack_a(t_list_mark *ls_mark)
// {
// 	t_node	*tmp_ptr;
// 	int		num_of_elements;

// 	num_of_elements = count_elements_in_stack_a(ls_mark);
// 	if (num_of_elements < 2)
// 		return ;
// 	else if (num_of_elements == 2)
// 	{
// 		if (ls_mark->cursor == ls_mark->tail)
// 		{
// 			ls_mark->tail->next = ls_mark->head;
// 			ls_mark->head->prev = ls_mark->tail;
// 			ls_mark->head->next = NULL;
// 			ls_mark->tail->prev = NULL;
// 			ls_mark->tail = ls_mark->head;
// 			ls_mark->head = ls_mark->cursor;
// 			ls_mark->cursor = ls_mark->tail;
// 		}
// 		else
// 		{
// 			tmp_ptr = ls_mark->cursor->prev;
// 			tmp_ptr->next = ls_mark->cursor->next;
// 			ls_mark->cursor->next->prev = tmp_ptr;
// 			ls_mark->cursor->next = tmp_ptr;
// 			tmp_ptr->prev = ls_mark->cursor;
// 			ls_mark->cursor->prev = NULL;
// 			ls_mark->head = ls_mark->cursor;
// 			ls_mark->cursor = tmp_ptr;
// 		}
// 	}
// 	else
// 	{
// 		if (ls_mark->cursor != ls_mark->tail)
// 		{
// 			tmp_ptr = ls_mark->cursor->prev;
// 			tmp_ptr->next = ls_mark->cursor->next;
// 			ls_mark->cursor->prev = tmp_ptr->prev;
// 			tmp_ptr->prev->next = ls_mark->cursor;
// 			ls_mark->cursor->next->prev = tmp_ptr;
// 			ls_mark->cursor->next = tmp_ptr;
// 			tmp_ptr->prev = ls_mark->cursor;
// 			ls_mark->cursor = tmp_ptr;
// 		}
// 		else
// 		{
// 			tmp_ptr = ls_mark->cursor->prev;
// 			ls_mark->cursor->prev = tmp_ptr->prev;
// 			tmp_ptr->prev->next = ls_mark->cursor;
// 			tmp_ptr->prev = ls_mark->cursor;
// 			ls_mark->cursor->next = tmp_ptr;
// 			tmp_ptr->next = NULL;
// 			ls_mark->tail = tmp_ptr;
// 			ls_mark->cursor = tmp_ptr;
// 		}
// 	}
// 	check_flag_and_print(0, "sa\n", ls_mark);
// }

// void	swap_stack_b(t_list_mark *ls_mark)
// {
// 	int		num_of_elements;

// 	if (!ls_mark->swap_flag)
// 		ls_mark->swap_flag = 1;
// 	num_of_elements = count_elements_in_stack_b(ls_mark);
// 	if (num_of_elements < 2)
// 	{	
// 		ls_mark->swap_flag = 0;
// 		return ;
// 	}
// 	if (ls_mark->cursor != NULL)
// 		ls_mark->cursor = ls_mark->cursor->next->next;
// 	else
// 		ls_mark->cursor = ls_mark->head->next;
// 	swap_stack_a(ls_mark);
// 	ls_mark->cursor = ls_mark->cursor->prev->prev;
// 	check_flag_and_print(1, "sb\n", ls_mark);
// }

// void	swap_stack_a_and_b(t_list_mark *ls_mark)
// {
// 	if (count_elements_in_stack_a(ls_mark) >= 2 \
// 		&& count_elements_in_stack_b(ls_mark) >= 2)
// 	{
// 		ls_mark->op_flag = 2;
// 		swap_stack_a(ls_mark);
// 		swap_stack_b(ls_mark);
// 		check_flag_and_print(2, "ss\n", ls_mark);
// 	}
// }
