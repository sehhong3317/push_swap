/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:09:39 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/07 16:17:13 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_list_mark
{
	t_node	*head;
	t_node	*tail;
	t_node	*cursor;
}				t_list_mark;

/*linked_list_functions*/
void	initiate_linked_list(t_list_mark *ls_mark);
void	add_node_back(int data, t_list_mark *ls_mark);
void	print_list(t_list_mark ls_mark);

/*parse_arguments*/
int		convert_str_to_int(char *str);
void	split_arg_and_add_node_back(char **array_of_str, t_list_mark *ls_mark);
void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark);
void	check_duplicates(t_list_mark ls_mark);

/*push_swap_operations*/
void	swap_stack_a(t_list_mark *ls_mark);
void	swap_stack_b(t_list_mark *ls_mark);

/*print_errors_and_exit*/
void	print_error_and_exit(void);

#endif
