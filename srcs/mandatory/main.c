/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:11:29 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/07 16:49:04 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_mark	ls_mark;

	initiate_linked_list(&ls_mark);
	parse_arguments(argc, argv, &ls_mark);
	print_list(ls_mark);
	check_duplicates(ls_mark);
	printf("\n");
	swap_stack_a(&ls_mark);
	// ls_mark.cursor = ls_mark.cursor->prev->prev->prev;
	// print_list(ls_mark);
	// swap_stack_b(&ls_mark);
	print_list(ls_mark);
	return (0);
}
