/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:25:43 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/31 18:08:07 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_arg_and_add_node_back(char **array_of_str, t_list_mark *ls_mark)
{
	int	idx;

	idx = 0;
	while (array_of_str[idx] != NULL)
	{
		add_node_back(ft_str_to_int(array_of_str[idx]), ls_mark);
		idx++;
	}
}

void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark)
{
	int	idx;

	if (argc == 1)
		ft_print_error_and_exit();
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
	while (curr_node != NULL)
	{
		data = curr_node->data;
		cmp_node = curr_node->next;
		while (cmp_node != NULL)
		{
			data_to_cmp = cmp_node->data;
			if (data == data_to_cmp)
				ft_print_error_and_exit();
			cmp_node = cmp_node->next;
		}
		curr_node = curr_node->next;
	}
}
