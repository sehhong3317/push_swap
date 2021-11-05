/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:11:29 by sehhong           #+#    #+#             */
/*   Updated: 2021/11/05 15:08:44 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_mark	ls_mark;

	ft_memset(&ls_mark, 0, sizeof((ls_mark)));
	parse_arguments(argc, argv, &ls_mark);
	check_if_duplicated(ls_mark);
	check_if_already_sorted(ls_mark);
	final_sort(count_elements_in_stack_a(&ls_mark), &ls_mark);
	return (0);
}
