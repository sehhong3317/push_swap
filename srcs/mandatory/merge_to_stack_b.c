/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:39:14 by sehee             #+#    #+#             */
/*   Updated: 2021/10/09 20:57:59 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int num1, int num2, int num3)
{
	int	max;

	max = num1;
	if (num2 > max)
		max = num2;
	if (num3 > max)
		max = num3;
	return (max);
}

t_node	*choose_which_chunk(int num1, int num2, int num3, t_list_mark *ls_mark)
{
	int	data1;
	int	data2;
	int	data3;
	int	max;

	data1 = ls_mark->head->data;
	data2 = ls_mark->middle_chunk->data;
	data3 = ls_mark->tail->data;

	if (num1 > 0 && num2 > 0 && num3 > 0)
	{
		max = find_max(data1, data2, data3);
		if (max == data1)
			return (ls_mark->head);
		else if (max == data2)
			return (ls_mark->middle_chunk);
		else
			return (ls_mark->tail);
	}
	if (!num1 && num2 > 0 && num3 > 0)
	{
		if (data2 > data3)
			return (ls_mark->middle_chunk);
		return (ls_mark->tail);
	}
	else if (!num2 && num1 > 0 && num3 > 0)
	{
		if (data1 > data3)
			return(ls_mark->head);
		return (ls_mark->tail);
	}
	else if (!num3 && num1 > 0 && num2 > 0)
	{
		if (data1 > data2)
			return (ls_mark->head);
		return (ls_mark->middle_chunk);
	}
	else
	{
		if (num1)
			return (ls_mark->head);
		else if (num2)
			return (ls_mark->middle_chunk);
		else if (num3)
			return(ls_mark->tail);
		return (NULL);
	}
}

int	count_rb(t_list_mark ls_mark, t_node *base_node)
{
	int		num_of_rb;
	t_node	*curr_node;
	t_node	*destinated_node;

	num_of_rb = 0;
	curr_node = base_node;
	if (ls_mark.cursor != NULL)
		destinated_node = ls_mark.cursor->next;
	else
		destinated_node = ls_mark.head;
	while (curr_node != destinated_node)
	{
		num_of_rb++;
		curr_node = curr_node->prev;
	}
	return (num_of_rb);
}

int	count_rrb(t_list_mark ls_mark, t_node *base_node)
{
	int		num_of_rrb;
	t_node	*curr_node;
	
	num_of_rrb = 0;
	curr_node = base_node;
	while (curr_node != ls_mark.tail)
	{
		num_of_rrb++;
		curr_node = curr_node->next;
	}
	num_of_rrb++;
	return (num_of_rrb);
}

//merge_to_stack_b의 조건: 감소 - C - 감소 - 증가
void	merge_to_stack_b(t_list_mark *ls_mark, int chunk1, int chunk2, \
	int chunk3)
{
	t_node	*node_to_move;
	int		num_to_rb;
	int		num_to_rrb;
	int		i;

	ls_mark->middle_chunk = ls_mark->cursor->next;
	while (chunk1 > 0 || chunk2 > 0 || chunk3 > 0)
	{
		node_to_move = choose_which_chunk(chunk1, chunk2, chunk3, ls_mark);
		if (node_to_move == NULL)
			return ;
		if (node_to_move == ls_mark->head)
		{
			chunk1--;
			node_to_move = node_to_move->next;
			reverse_rotate_stack_a(ls_mark);
			push_to_stack_b(ls_mark);
			if (ls_mark->cursor != NULL)
				ls_mark->head= node_to_move;
		}
		else if (node_to_move == ls_mark->middle_chunk \
			&& node_to_move != ls_mark->tail)
		{
			num_to_rb = count_rb(*ls_mark, node_to_move);
			num_to_rrb = count_rrb(*ls_mark, node_to_move);
			node_to_move = node_to_move->next;
			chunk2--;
			if (num_to_rb < num_to_rrb)
			{
				i = 0;
				while (i++ < num_to_rb)
					rotate_stack_b(ls_mark);
				push_to_stack_a(ls_mark);
				i = 0;
				while (i++ < num_to_rb)
					reverse_rotate_stack_b(ls_mark);
			}
			else
			{
				i = 0;
				while (i++ < num_to_rrb)
					reverse_rotate_stack_b(ls_mark);
				push_to_stack_a(ls_mark);
				i = 0;
				while (i++ < num_to_rrb - 1)
					rotate_stack_b(ls_mark);
			}
			push_to_stack_b(ls_mark);
			ls_mark->middle_chunk = node_to_move;
		}
		else if (node_to_move == ls_mark->tail)
		{
			chunk3--;
			node_to_move = node_to_move->prev;
			reverse_rotate_stack_b(ls_mark);
			ls_mark->tail = node_to_move;
		}
		print_list(*ls_mark);
	}
}