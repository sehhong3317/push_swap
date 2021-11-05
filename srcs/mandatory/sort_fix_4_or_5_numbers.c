/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fix_4_or_5_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 03:49:00 by sehee             #+#    #+#             */
/*   Updated: 2021/11/04 14:40:17 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fix_4_numbers(int max, t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = ls_mark->head->data;
	num2 = ls_mark->head->next->data;
	num3 = ls_mark->cursor->prev->data;
	if (max == num3)
		ra(ls_mark);
	else if (max == num1 || max == num2)
	{
		rra(ls_mark);
		if (max == num2)
			rra(ls_mark);
	}
	pb(ls_mark);
	sort_fix_3_numbers(ls_mark);
	pa(ls_mark);
	ra(ls_mark);
}

void	sort_fix_5_numbers(int max, t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;
	int	num4;

	num1 = ls_mark->head->data;
	num2 = ls_mark->head->next->data;
	num3 = ls_mark->head->next->next->data;
	num4 = ls_mark->cursor->prev->data;
	if (max == num1 || max == num2)
	{
		rra(ls_mark);
		if (max == num2)
			rra(ls_mark);
	}
	else if (max == num3 || max == num4)
	{
		ra(ls_mark);
		if (max == num3)
			ra(ls_mark);
	}
	pb(ls_mark);
	sort_fix_4_numbers(find_max_in_list(*ls_mark), ls_mark);
	pa(ls_mark);
	ra(ls_mark);
}

void	sort_fix_4_or_5_numbers(t_list_mark *ls_mark, int num_of_nums)
{
	int	max;

	max = find_max_in_list(*ls_mark);
	if (num_of_nums == 4)
		sort_fix_4_numbers(max, ls_mark);
	else if (num_of_nums == 5)
		sort_fix_5_numbers(max, ls_mark);
}

int	find_max_in_list(t_list_mark ls_mark)
{
	t_node	*tmp_ptr;
	int		max;

	max = ls_mark.head->data;
	tmp_ptr = ls_mark.head->next;
	while (tmp_ptr != ls_mark.cursor->next)
	{
		if (tmp_ptr->data > max)
			max = tmp_ptr->data;
		tmp_ptr = tmp_ptr->next;
	}
	return (max);
}
