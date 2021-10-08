/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:11:29 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/09 00:43:51 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_mark	ls_mark;
	//t_node		*tmp_ptr;

	ft_memset(&ls_mark, 0, sizeof((ls_mark)));
	parse_arguments(argc, argv, &ls_mark);
	print_list(ls_mark);
	check_duplicates(ls_mark);
	printf("\n");
	ls_mark.cursor = ls_mark.cursor->prev->prev;
	print_list(ls_mark);
	// swap_stack_a(&ls_mark);
	// print_list(ls_mark);
	// swap_stack_b(&ls_mark);
	// print_list(ls_mark);
	// swap_stack_a_and_b(&ls_mark);
	// print_list(ls_mark);
	// rotate_stack_a(&ls_mark);
	// print_list(ls_mark);
	// rotate_stack_b(&ls_mark);
	// print_list(ls_mark);
	rotate_stack_a_and_b(&ls_mark);
	print_list(ls_mark);
	reverse_rotate_stack_a(&ls_mark);
	print_list(ls_mark);
	reverse_rotate_stack_b(&ls_mark);
	print_list(ls_mark);
	reverse_rotate_stack_a_and_b(&ls_mark);
	print_list(ls_mark);
	return (0);
}
