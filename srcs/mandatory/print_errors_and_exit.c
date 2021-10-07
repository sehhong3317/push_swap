/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors_and_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:31:04 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/07 08:01:10 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
