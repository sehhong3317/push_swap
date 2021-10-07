/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:25:43 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/07 10:55:34 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	convert_str_to_int(char *str)
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
	if (*str || digit_count > 10 || final_int < -2147483648 \
		|| final_int > 2147483647)
		print_error_and_exit();
	return ((int)final_int);
}

void	split_arg_and_add_node_back(char **array_of_str, t_list_mark *ls_mark)
{
	int	idx;

	idx = 0;
	while (array_of_str[idx] != NULL)
	{
		add_node_back(convert_str_to_int(array_of_str[idx]), ls_mark);
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
		split_arg_and_add_node_back(ft_split_argument(argv[idx]), ls_mark);
		idx++;
	}
}

void	check_duplicates(t_list_mark ls_mark)
{
	int		data;
	int		data_to_cmp;
	t_node	*curr_node;
	t_node	*cmp_node;

	curr_node = ls_mark.head;
	while(curr_node != NULL)
	{
		data = curr_node->data;
		cmp_node = curr_node->next;
		while(cmp_node != NULL)
		{
			data_to_cmp = cmp_node->data;
			if (data == data_to_cmp)
				print_error_and_exit();
			cmp_node = cmp_node->next;
		}
		curr_node = curr_node->next;
	}
}