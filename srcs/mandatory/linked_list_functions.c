/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:47:11 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/08 07:47:54 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ls_mark->cursor = ls_mark->tail;
		tmp_node->prev = NULL;
		tmp_node->next = NULL;
	}
	else
	{
		tmp_node->prev = ls_mark->tail;
		tmp_node->next = NULL;
		ls_mark->tail->next = tmp_node;
		ls_mark->tail = tmp_node;
		ls_mark->cursor = ls_mark->tail;
	}
}

void	print_list(t_list_mark ls_mark)
{
	t_node	*curr_node;

	curr_node = ls_mark.head;
	printf("\n");
	while (curr_node != NULL)
	{
		printf("%d ", curr_node->data);
		if (curr_node == ls_mark.cursor)
			printf("cursor ");
		curr_node = curr_node->next;
	}
	printf("\n");
}
