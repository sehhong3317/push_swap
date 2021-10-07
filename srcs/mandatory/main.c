/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:11:29 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/07 10:45:07 by sehee            ###   ########seoul.kr  */
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
	return (0);
}
