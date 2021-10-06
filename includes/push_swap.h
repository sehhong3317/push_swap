/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:09:39 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/06 16:28:21 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

# include <stdio.h>
# include <stdlib.h>

typedef struct 	s_node
{
	struct s_node	*prev;
	int				data;
	struct s_node 	*next;
}				t_node;

typedef struct	s_list_mark
{
	t_node	*head;
	t_node	*tail;
}				t_list_mark;

/*linked_list_functions*/
void	initiate_linked_list(t_list_mark *ls_mark);
void	add_node_back(int data, t_list_mark *ls_mark);
void	print_list(t_list_mark ls_mark);

/*parse_arguments*/
void	convert_str_to_ull(char *str);
void	split_argument_and_parse_into_node(char **array_of_str, t_list_mark *ls_mark);
void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark);

/*print_errors_and_exit*/
void	print_error_and_exit();

#endif
