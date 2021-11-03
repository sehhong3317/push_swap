/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_skip_lt_4_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:43:22 by sehee             #+#    #+#             */
/*   Updated: 2021/11/01 05:04:33 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_skip_3_numbers_ascend(t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	num1 = ls_mark->cursor->prev->prev->data;
	num2 = ls_mark->cursor->prev->data;
	num3 = ls_mark->cursor->data;
	max = ft_find_max(num1, num2, num3);
	if (max == num2 || (max == num1 && num2 > num3))
		sa(ls_mark);
	else
	{
		pb(ls_mark);
		if ((max == num3 && num1 > num2) || max == num1)
			sa(ls_mark);
		pb(ls_mark);
		if (max == num1)
			sb(ls_mark);
		return ;
	}
	sort_skip_3_numbers_ascend(ls_mark);
}

void	sort_skip_3_numbers_descend(t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	num1 = ls_mark->cursor->prev->prev->data;
	num2 = ls_mark->cursor->prev->data;
	num3 = ls_mark->cursor->data;
	max = ft_find_max(num1, num2, num3);
	if (max == num3 || (max == num1 && num2 < num3))
		sa(ls_mark);
	else
	{
		pb(ls_mark);
		if (max == num2)
			sa(ls_mark);
		pb(ls_mark);
		if (max == num2 && num1 < num3)
			sb(ls_mark);
		return ;
	}
	sort_skip_3_numbers_descend(ls_mark);
}

void	sort_skip_lt_4_numbers(int num_of_nums, t_list_mark *ls_mark, int order)
{
	if (num_of_nums == 2)
	{
		sort_fix_2_numbers(ls_mark, order);
		pb(ls_mark);
	}
	else if (num_of_nums == 3)
	{
		if (!order)
			sort_skip_3_numbers_ascend(ls_mark);
		else
			sort_skip_3_numbers_descend(ls_mark);
	}
	pb(ls_mark);
}
