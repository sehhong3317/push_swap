/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:09:39 by sehhong           #+#    #+#             */
/*   Updated: 2021/10/12 16:08:19 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0
# define ASCEND 		0
# define DESCEND		1

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
	t_node	*middle_chunk;
	int		op_flag;
}				t_list_mark;

/*linked_list_functions*/
void	add_node_back(int data, t_list_mark *ls_mark);
void	print_list(t_list_mark ls_mark);

/*parse_arguments*/
int		convert_str_to_int(char *str);
void	split_arg_and_add_node_back(char **array_of_str, t_list_mark *ls_mark);
void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark);
void	check_duplicates(t_list_mark ls_mark);

/*count_elements_in_stack*/
int		count_elements_in_stack_a(t_list_mark *ls_mark);
int		count_elements_in_stack_b(t_list_mark *ls_mark);

/*swap*/
void	sa(t_list_mark *ls_mark);
void	sb(t_list_mark *ls_mark);
//void	swap_stack_a_and_b(t_list_mark *ls_mark);

/*push*/
void	pa(t_list_mark *ls_mark);
void	pb(t_list_mark *ls_mark);

/*rotate*/
void	ra(t_list_mark *ls_mark);
void	rb(t_list_mark *ls_mark);
void	rr(t_list_mark *ls_mark);

/*reverse_rotate*/
void	rra(t_list_mark *ls_mark);
void	rrb(t_list_mark *ls_mark);
void	rrr(t_list_mark *ls_mark);

/*merge_to_stack_b*/
// int		find_max(int num1, int num2, int num3);
// t_node	*choose_which_chunk(int num1, int num2, int num3, t_list_mark *ls_mark);
// void	merge_to_stack_b(t_list_mark *ls_mark, int chunk1, int chunk2, \
// 	int chunk3);

/*print_errors_and_exit*/
void	print_error_and_exit(void);
void	check_flag_and_print(int flag, char *str, t_list_mark *ls_mark);

#endif
