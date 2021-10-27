/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:45:39 by sehee             #+#    #+#             */
/*   Updated: 2021/10/27 16:07:43 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_skip_3_numbers(int num_of_nums, t_list_mark *ls_mark, int order)
{
	if (num_of_nums == 2)
	{
		if (!order)
		else
	}
	else if (num_of_nums == 3)
	{
		if (!order)
		else
	}

}

void	sort_fix_3_numbers(int num_of_nums, t_list_mark *ls_mark, int order)
{
	
}

void	rr_and_rb(int num_of_nums, t_list_mark *ls_mark)
{
	int	i;

	i = 0;
	while (i++ < num_of_nums / 3)
		rr(ls_mark);
	i = 0;
	while (i++ < num_of_nums % 3)
		rb(ls_mark);
}

void	sort_skip(int num_of_nums, t_list_mark *ls_mark, int order)
{
	int	chunk1;
	int	chunk2;
	
	chunk1 = num_of_nums / 3;
	chunk2 = chunk1 + num_of_nums % 3;
	if (num_of_nums <= 3)
		sort_skip_3_numbers(num_of_nums, ls_mark, order);
	else
	{
		sort_skip(chunk2, ls_mark, order);
		sort_fix(chunk1, ls_mark, !order);
		rr_and_rb(num_of_nums, ls_mark);
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
		sort_fix_3_numbers(num_of_nums, ls_mark, order);
	else
	{
		sort_skip(chunk2, ls_mark, !order);
		sort_fix(chunk1, ls_mark, order);
		rr_and_rb(num_of_nums, ls_mark);	//
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
		sort_fix_3_numbers(num_of_nums, ls_mark, DESCEND);
	else
	{	
		sort_skip(chunk2, ls_mark, ASCEND);
		sort_skip(chunk1, ls_mark, DESCEND);
		sort_fix(chunk1, ls_mark, DESCEND);
		merge_to_stack_a(num_of_nums, ls_mark, DESCEND);
	}
}