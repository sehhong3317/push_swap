/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:45:39 by sehee             #+#    #+#             */
/*   Updated: 2021/10/10 11:39:02 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_skip_ascend_3_numbers(t_list_mark *ls_mark)
{
	int	num1;
	int	num2;
	int	num3;
	int	max;

	num1 = ls_mark->head->data;
	num2 = ls_mark->head->next->data;
	num3 = ls_mark->tail->data;
	max = find_max(num1, num2, num3);
	if (max == num1 && num2 > num3)
	{
		
	}

	else if (max == num1 && num2 < num3)
		swap_stack_a(ls_mark);
	else if (max == num2 && num1 < num3)
		reverse_rotate_stack_a(ls_mark);
	else if (max == num2 && num1 > num3)
	{	
		swap_stack_a(ls_mark);
		rotate_stack_a(ls_mark);
	}
	else if (max == num3 && num1 < num2)
	{
		rotate_stack_a(ls_mark);
		swap_stack_a(ls_mark);
	}
	else if (max == num3 && num1 > num2)
		rotate_stack_a(ls_mark);
}

void	sort_skip_ascend(int num_of_num, t_list_mark *ls_mark)
{
	int	quotient;
	int	i;
	
	quotient = num_of_num / 3;
	if (num_of_num <= 3)
		sort_skip_ascend_3_numbers(ls_mark);
	else
	{
		sort_skip_ascend(quotient + num_of_num % 3, ls_mark);
		sort_fix_descend(quotient);
		i = 0;
		while (i++ < quotient)
			rotate_stack_a_and_b(ls_mark);
		i = 0;
		while (i++ < num_of_num % 3)
			rotate_stack_b(ls_mark);
		sort_fix_ascend(quotient);
		merge_to_stack_b_ascend(ls_mark, quotient, quotient, quotient + num_of_num % 3);
	}
}

void	final_sort(int num_of_num, t_list_mark *ls_mark)
{
	int	quotient;
	
	if (num_of_num <= 3)

	quotient = num_of_num / 3;
	sort_skip_ascend(quotient + num_of_num % 3, ls_mark);
	sort_skip_descend(quotient);
	sort_fix_descend(quotient);
	merge_to_stack_a_descend(ls_mark, quotient, quotient, quotient + num_of_num % 3);
}