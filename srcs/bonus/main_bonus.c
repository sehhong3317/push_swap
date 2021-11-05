/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:57:09 by sehee             #+#    #+#             */
/*   Updated: 2021/11/05 15:48:16 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_instruction(char *str, t_list_mark *ls_mark)
{
	if (ft_strlen(str) == 2 && !ft_strncmp(str, "sa", 2))
		sa(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "sb", 2))
		sb(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "ss", 2))
		ss(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "pa", 2))
		pa(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "pb", 2))
		pb(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "ra", 2))
		ra(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "rb", 2))
		rb(ls_mark);
	else if (ft_strlen(str) == 2 && !ft_strncmp(str, "rr", 2))
		rr(ls_mark);
	else if (ft_strlen(str) == 3 && !ft_strncmp(str, "rra", 3))
		rra(ls_mark);
	else if (ft_strlen(str) == 3 && !ft_strncmp(str, "rrb", 3))
		rrb(ls_mark);
	else if (ft_strlen(str) == 3 && !ft_strncmp(str, "rrr", 3))
		rrr(ls_mark);
	else
		ft_print_error_and_exit();
}

int	main(int argc, char **argv)
{
	char		*line;
	int			ret;
	t_list_mark	ls_mark;

	ft_memset(&ls_mark, 0, sizeof((ls_mark)));
	parse_arguments(argc, argv, &ls_mark);
	check_if_duplicated(ls_mark);
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret > 0)
			execute_instruction(line, &ls_mark);
		else if (!ret)
			break ;
		free(line);
	}
	free(line);
	check_if_already_sorted(ls_mark);
	ft_putstr_fd("KO\n", STDOUT_FD);
	exit(EXIT_FAILURE);
	return (0);
}
