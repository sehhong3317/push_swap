/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:25:43 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/06 16:35:19 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_str_to_ull(char *str)
{
	int					sign;
	unsigned long long	ret;
	int					digit_count;

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
	// if (*str || digit_count > 10 || sign * ret < -2147483648 \
	// 	|| sign * ret > 2147483647)
	// 	print_error_and_exit();
}

void	split_argument_and_parse_into_node(char **array_of_str, t_list_mark *ls_mark)
{
	int					idx;

	idx = 0;
	while (array_of_str[idx] != NULL)
	{
		convert_str_to_ull(array_of_str[idx]);
		add_node_back(ft_atoi(array_of_str[idx]), ls_mark);
		idx++;
	}
}

void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark)
{
	int	idx;

	if (argc == 1)
		print_error_and_exit();
	idx = 1;
	while (idx < argc)
	{
		split_argument_and_parse_into_node(ft_split_argument(argv[idx]), ls_mark);
		idx++;
	}
	print_list(*ls_mark);
}
