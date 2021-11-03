/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fix_lt_4_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:26:52 by sehee             #+#    #+#             */
/*   Updated: 2021/11/03 12:09:18 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fix_2_numbers(t_list_mark *ls_mark, int order)
{
	int	num1;
	int	num2;

	num1 = ls_mark->cursor->prev->data;
	num2 = ls_mark->cursor->data;
	if ((!order && num1 > num2) || (order && num1 < num2))
		sa(ls_mark);
}

void	sort_fix_3_numbers_ascend(t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	num1 = ls_mark->cursor->prev->prev->data;
	num2 = ls_mark->cursor->prev->data;
	num3 = ls_mark->cursor->data;
	max = ft_find_max(num1, num2, num3);
	if (num1 < num2 && num2 < num3)
		return ;
	else if ((max == num3 && num1 > num2) || (max == num1 && num2 < num3))
	{
		pb(ls_mark);
		sa(ls_mark);
		pa(ls_mark);
	}
	else if (max == num2 || (max == num1 && num2 > num3))
		sa(ls_mark);
	sort_fix_3_numbers_ascend(ls_mark);
}

void	sort_fix_3_numbers_descend(t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	num1 = ls_mark->cursor->prev->prev->data;
	num2 = ls_mark->cursor->prev->data;
	num3 = ls_mark->cursor->data;
	max = ft_find_max(num1, num2, num3);
	if (num1 > num2 && num2 > num3)
		return ;
	else if (max == num1 && num3 > num2)
		sa(ls_mark);
	else if (max == num2)
	{
		pb(ls_mark);
		sa(ls_mark);
		pa(ls_mark);
	}
	else if (max == num3)
		sa(ls_mark);
	sort_fix_3_numbers_descend(ls_mark);
}

void	sort_fix_lt_4_numbers(int num_of_nums, t_list_mark *ls_mark, int order)
{
	if (num_of_nums == 2)
		sort_fix_2_numbers(ls_mark, order);
	else if (num_of_nums == 3 && !order)
		sort_fix_3_numbers_ascend(ls_mark);
	else if (num_of_nums == 3 && order)
		sort_fix_3_numbers_descend(ls_mark);
}
