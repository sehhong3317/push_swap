/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:47:11 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/06 14:41:09 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate_linked_list(t_list_mark *ls_mark)
{
	ls_mark->head = NULL;
	ls_mark->tail = NULL;
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
		tmp_node->prev = NULL;
		tmp_node->next = NULL;
	}
	else
	{
		tmp_node->prev = ls_mark->tail;
		tmp_node->next = NULL;
		ls_mark->tail->next = tmp_node;
		ls_mark->tail = tmp_node;
	}
}

void	print_list(t_list_mark ls_mark)
{
	t_node	*curr_node;

	curr_node = ls_mark.head;
	printf("start!\n");
	while (curr_node != NULL)
	{
		printf("%d\n", curr_node->data);
		curr_node = curr_node->next;
	}
	printf("end!\n");
}