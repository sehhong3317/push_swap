/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:47:11 by sehhong           #+#    #+#             */
/*   Updated: 2021/11/03 12:15:27 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements_in_stack_a(t_list_mark *ls_mark)
{
	int		num_of_elements;
	t_node	*node_ptr;

	node_ptr = ls_mark->cursor;
	num_of_elements = 0;
	while (node_ptr != NULL)
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
	while (node_ptr != ls_mark->tail)
	{
		num_of_elements++;
		node_ptr = node_ptr->next;
	}
	if (!ls_mark->cursor)
		return (num_of_elements + 1);
	return (num_of_elements);
}

void	add_node_back(int data, t_list_mark *ls_mark)
{
	t_node	*tmp_node;

	tmp_node = (t_node *)malloc(sizeof(t_node));
	if (!tmp_node)
		return ;
	tmp_node->data = data;
	if (ls_mark->head == NULL)
	{
		ls_mark->head = tmp_node;
		ls_mark->tail = tmp_node;
		ls_mark->cursor = tmp_node;
		tmp_node->prev = NULL;
		tmp_node->next = NULL;
	}
	else
	{
		tmp_node->next = ls_mark->head;
		tmp_node->prev = NULL;
		ls_mark->head->prev = tmp_node;
		ls_mark->head = tmp_node;
	}
}

void	print_list(t_list_mark ls_mark)
{
	t_node	*curr_node;

	curr_node = ls_mark.head;
	while (curr_node != NULL)
	{
		ft_putnbr_fd(curr_node->data, 1);
		ft_putstr_fd(" ", 1);
		if (curr_node == ls_mark.cursor)
			ft_putstr_fd("<cursor> ", 1);
		curr_node = curr_node->next;
	}
	printf("\n");
}

void	check_flag_and_print(int flag, char *str, t_list_mark *ls_mark)
{
	if (ls_mark->op_flag == flag)
	{
		ft_putstr_fd(str, 1);
		ls_mark->op_flag = 0;
		//print_list(*ls_mark);
	}
}
