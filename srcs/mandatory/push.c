/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:05:36 by sehee             #+#    #+#             */
/*   Updated: 2021/11/04 05:13:24 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list_mark *ls_mark)
{
	int	num_of_elements;

	num_of_elements = count_elements_in_stack_b(ls_mark);
	if (!num_of_elements)
		return ;
	if (ls_mark->cursor == NULL)
		ls_mark->cursor = ls_mark->head;
	else
		ls_mark->cursor = ls_mark->cursor->next;
	ft_putstr_fd("pa\n", 1);
	print_list(*ls_mark);
}

void	pb(t_list_mark *ls_mark)
{
	int	num_of_elements;

	num_of_elements = count_elements_in_stack_a(ls_mark);
	if (!num_of_elements)
		return ;
	ls_mark->cursor = ls_mark->cursor->prev;
	ft_putstr_fd("pb\n", 1);
	print_list(*ls_mark);
}
