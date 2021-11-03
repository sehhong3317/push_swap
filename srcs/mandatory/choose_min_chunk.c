/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_min_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:57:50 by sehee             #+#    #+#             */
/*   Updated: 2021/11/02 22:15:57 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*compare_3_chunks_min(t_list_mark *ls_mark)
{
	int	data1;
	int	data2;
	int	data3;
	int	min;

	data1 = ls_mark->head->data;
	data2 = ls_mark->middle_chunk->data;
	data3 = ls_mark->tail->data;
	min = ft_find_min(data1, data2, data3);
	if (min == data1)
		return (ls_mark->head);
	else if (min == data2)
		return (ls_mark->middle_chunk);
	else
		return (ls_mark->tail);
}

static t_node	*compare_2_chunks_min(int num1, int num2, int num3, \
t_list_mark *ls_mark)
{
	if (!num1 && num2 > 0 && num3 > 0)
	{
		if (ls_mark->middle_chunk->data < ls_mark->tail->data)
			return (ls_mark->middle_chunk);
		return (ls_mark->tail);
	}
	else if (!num2 && num1 > 0 && num3 > 0)
	{
		if (ls_mark->head->data < ls_mark->tail->data)
			return (ls_mark->head);
		return (ls_mark->tail);
	}
	else
	{
		if (ls_mark->head->data < ls_mark->middle_chunk->data)
			return (ls_mark->head);
		return (ls_mark->middle_chunk);
	}
}

t_node	*choose_min_chunk(int num1, int num2, int num3, t_list_mark *ls_mark)
{
	if (num1 > 0 && num2 > 0 && num3 > 0)
		return (compare_3_chunks_min(ls_mark));
	else if (num1 > 0 && !num2 && !num3)
		return (ls_mark->head);
	else if (num2 > 0 && !num1 && !num3)
		return (ls_mark->middle_chunk);
	else if (num3 > 0 && !num1 && !num2)
		return (ls_mark->tail);
	else
		return (compare_2_chunks_min(num1, num2, num3, ls_mark));
}

int	move_element1(int chunk, t_node *next_node, t_list_mark *ls_mark, \
	int chunk_case)
{
	chunk--;
	if (chunk_case == 1)
		rra(ls_mark);
	else if (chunk_case == 2)
	{
		pa(ls_mark);
		if (chunk)
			ls_mark->middle_chunk = next_node;
	}
	else
	{
		rrb(ls_mark);
		pa(ls_mark);
	}
	return (chunk);
}
