/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:25:43 by sehhong           #+#    #+#             */
/*   Updated: 2021/11/05 15:48:29 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	split_arg_and_add_node_front(char **array_of_str, t_list_mark *ls_mark)
{
	int	idx;

	idx = 0;
	while (array_of_str[idx] != NULL)
	{
		add_node_front(ft_str_to_int(array_of_str[idx]), ls_mark);
		free(array_of_str[idx]);
		idx++;
	}
}

void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark)
{
	int		idx;
	char	**array_of_str;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	idx = 1;
	while (idx < argc)
	{
		array_of_str = ft_split_argument(argv[idx]);
		split_arg_and_add_node_front(array_of_str, ls_mark);
		free(array_of_str);
		idx++;
	}
}

void	check_if_duplicated(t_list_mark ls_mark)
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

void	check_if_already_sorted(t_list_mark ls_mark)
{
	t_node	*tmp_ptr;

	tmp_ptr = ls_mark.head;
	while (tmp_ptr != ls_mark.tail)
	{
		if (tmp_ptr->data < tmp_ptr->next->data)
			return ;
		tmp_ptr = tmp_ptr->next;
	}
	ft_putstr_fd("OK\n", STDOUT_FD);
	exit(EXIT_SUCCESS);
}
