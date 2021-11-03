/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:44:58 by sehee             #+#    #+#             */
/*   Updated: 2021/10/31 18:09:23 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_valid_int(char *str, int digit_count, int final_int)
{
	if (*str || digit_count > 10 || final_int < -2147483648 \
		|| final_int > 2147483647)
		ft_print_error_and_exit();
}

int	ft_str_to_int(char *str)
{
	int			sign;
	long long	ret;
	int			digit_count;
	int			final_int;

	ret = 0;
	sign = 1;
	digit_count = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digit_count++;
		ret = ret * 10 + (*str - '0');
		str++;
	}
	final_int = sign * ret;
	is_valid_int(str, digit_count, final_int);
	return ((int)final_int);
}
