/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 07:08:18 by sehee             #+#    #+#             */
/*   Updated: 2021/11/02 16:51:47 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_to_stack_a(int num_of_nums, t_list_mark *ls_mark, int order)
{
	int		chunk1;
	int		chunk2;
	int		chunk3;
	t_node	*node_to_move;

	chunk1 = num_of_nums / 3;
	chunk2 = chunk1;
	chunk3 = chunk1 + num_of_nums % 3;
	ls_mark->middle_chunk = ls_mark->cursor->next;
	while (chunk1 > 0 || chunk2 > 0 || chunk3 > 0)
	{
		if (!order)
			node_to_move = choose_min_chunk(chunk1, chunk2, chunk3, ls_mark);
		else
			node_to_move = choose_max_chunk(chunk1, chunk2, chunk3, ls_mark);
		if (node_to_move == ls_mark->head)
			chunk1 = move_element1(chunk1, node_to_move->next, ls_mark, 1);
		else if (node_to_move == ls_mark->middle_chunk)
			chunk2 = move_element1(chunk2, node_to_move->next, ls_mark, 2);
		else
			chunk3 = move_element1(chunk3, node_to_move->prev, ls_mark, 3);
	}
}

void	merge_to_stack_b(int num_of_nums, t_list_mark *ls_mark, int order)
{
	int		chunk1;
	int		chunk2;
	int		chunk3;
	t_node	*node_to_move;

	chunk1 = num_of_nums / 3;
	chunk2 = chunk1;
	chunk3 = chunk1 + num_of_nums % 3;
	ls_mark->middle_chunk = ls_mark->cursor;
	while (chunk1 > 0 || chunk2 > 0 || chunk3 > 0)
	{
		if (!order)
			node_to_move = choose_max_chunk(chunk1, chunk2, chunk3, ls_mark);
		else
			node_to_move = choose_min_chunk(chunk1, chunk2, chunk3, ls_mark);
		if (node_to_move == ls_mark->head)
			chunk1 = move_element2(chunk1, node_to_move->next, ls_mark, 1);
		else if (node_to_move == ls_mark->middle_chunk)
			chunk2 = move_element2(chunk2, node_to_move->prev, ls_mark, 2);
		else
			chunk3 = move_element2(chunk3, node_to_move->prev, ls_mark, 3);
	}
}
