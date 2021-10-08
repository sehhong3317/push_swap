/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors_and_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:31:04 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/08 12:38:11 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	check_flag_and_print(int flag, char *str, t_list_mark *ls_mark)
{
	if (ls_mark->swap_flag == flag)
	{
		ft_putstr_fd(str, 1);
		ls_mark->swap_flag = 0;
	}
}