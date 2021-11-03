/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_max_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:39:14 by sehee             #+#    #+#             */
/*   Updated: 2021/11/02 22:15:43 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*compare_3_chunks_max(t_list_mark *ls_mark)
{
	int	data1;
	int	data2;
	int	data3;
	int	max;

	data1 = ls_mark->head->data;
	data2 = ls_mark->middle_chunk->data;
	data3 = ls_mark->tail->data;
	max = ft_find_max(data1, data2, data3);
	if (max == data1)
		return (ls_mark->head);
	else if (max == data2)
		return (ls_mark->middle_chunk);
	else
		return (ls_mark->tail);
}

static t_node	*compare_2_chunks_max(int num1, int num2, int num3, \
	t_list_mark *ls_mark)
{
	if (!num1 && num2 > 0 && num3 > 0)
	{
		if (ls_mark->middle_chunk->data > ls_mark->tail->data)
			return (ls_mark->middle_chunk);
		return (ls_mark->tail);
	}
	else if (!num2 && num1 > 0 && num3 > 0)
	{
		if (ls_mark->head->data > ls_mark->tail->data)
			return (ls_mark->head);
		return (ls_mark->tail);
	}
	else
	{
		if (ls_mark->head->data > ls_mark->middle_chunk->data)
			return (ls_mark->head);
		return (ls_mark->middle_chunk);
	}
}

t_node	*choose_max_chunk(int num1, int num2, int num3, t_list_mark *ls_mark)
{
	if (num1 > 0 && num2 > 0 && num3 > 0)
		return (compare_3_chunks_max(ls_mark));
	else if (num1 > 0 && !num2 && !num3)
		return (ls_mark->head);
	else if (num2 > 0 && !num1 && !num3)
		return (ls_mark->middle_chunk);
	else if (num3 > 0 && !num1 && !num2)
		return (ls_mark->tail);
	else
		return (compare_2_chunks_max(num1, num2, num3, ls_mark));
}

int	move_element2(int chunk, t_node *next_node, t_list_mark *ls_mark, \
	int chunk_case)
{
	chunk--;
	if (chunk_case == 1)
	{
		rra(ls_mark);
		pb(ls_mark);
	}
	else if (chunk_case == 2)
	{
		pb(ls_mark);
		if (chunk)
			ls_mark->middle_chunk = next_node;
	}
	else if (chunk_case == 3)
		rrb(ls_mark);
	return (chunk);
}
