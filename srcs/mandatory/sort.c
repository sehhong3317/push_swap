/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:45:39 by sehee             #+#    #+#             */
/*   Updated: 2021/11/02 21:17:23 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_and_rb(int rr_count, int rb_count, t_list_mark *ls_mark)
{
	int	i;

	i = 0;
	if (rr_count == rb_count && count_elements_in_stack_b(ls_mark) == 2)
	{	
		ra(ls_mark);
		return ;
	}
	while (i++ < rr_count)
		rr(ls_mark);
	i = 0;
	while (i++ < rb_count)
		rb(ls_mark);
}

void	sort_skip(int num_of_nums, t_list_mark *ls_mark, int order)
{
	int	chunk1;
	int	chunk2;

	chunk1 = num_of_nums / 3;
	chunk2 = chunk1 + num_of_nums % 3;
	if (num_of_nums <= 3)
		sort_skip_lt_4_numbers(num_of_nums, ls_mark, order);
	else
	{
		sort_skip(chunk2, ls_mark, order);
		sort_fix(chunk1, ls_mark, !order);
		rr_and_rb(chunk1, chunk2 - chunk1, ls_mark);
		sort_fix(chunk1, ls_mark, order);
		merge_to_stack_b(num_of_nums, ls_mark, order);
	}
}

void	sort_fix(int num_of_nums, t_list_mark *ls_mark, int order)
{
	int	chunk1;
	int	chunk2;

	chunk1 = num_of_nums / 3;
	chunk2 = chunk1 + num_of_nums % 3;
	if (num_of_nums <= 3)
		sort_fix_lt_4_numbers(num_of_nums, ls_mark, order);
	else
	{
		sort_skip(chunk2, ls_mark, !order);
		sort_fix(chunk1, ls_mark, order);
		rr_and_rb(chunk1, chunk2 - chunk1, ls_mark);
		sort_skip(chunk1, ls_mark, order);
		merge_to_stack_a(num_of_nums, ls_mark, order);
	}
}

void	final_sort(int num_of_nums, t_list_mark *ls_mark)
{
	int	chunk1;
	int	chunk2;

	chunk1 = num_of_nums / 3;
	chunk2 = chunk1 + num_of_nums % 3;
	if (num_of_nums <= 3)
		sort_fix_lt_4_numbers(num_of_nums, ls_mark, DESCEND);
	else
	{	
		sort_skip(chunk2, ls_mark, ASCEND);
		sort_skip(chunk1, ls_mark, DESCEND);
		sort_fix(chunk1, ls_mark, DESCEND);
		merge_to_stack_a(num_of_nums, ls_mark, DESCEND);
	}
}
