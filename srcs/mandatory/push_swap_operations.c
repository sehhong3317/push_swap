/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:37:44 by sehee             #+#    #+#             */
/*   Updated: 2021/10/07 12:47:58 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack_a(t_list_mark *ls_mark)
{
	t_node	*tmp_ptr;

	ls_mark->cursor = ls_mark->cursor->prev;
	tmp_ptr = ls_mark->cursor;
	
}