/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:11:29 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/09 17:54:07 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_mark	ls_mark;
	//t_node		*tmp_ptr;

	ft_memset(&ls_mark, 0, sizeof((ls_mark)));
	parse_arguments(argc, argv, &ls_mark);
	check_duplicates(ls_mark);
	printf("\n");
	ls_mark.cursor = ls_mark.head->next->next;
	print_list(ls_mark);
	merge_to_stack_b(&ls_mark, 3, 3, 4);
	print_list(ls_mark);
	return (0);
}
