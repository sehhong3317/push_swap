/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:09:39 by sehhong           #+#    #+#             */
/*   Updated: 2021/11/01 05:06:38 by sehee            ###   ########seoul.kr  */
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

/*choose_max_chunk*/
t_node	*choose_max_chunk(int num1, int num2, int num3, t_list_mark *ls_mark);
int		move_element2(int chunk, t_node *next_node, t_list_mark *ls_mark, \
	int chunk_case);

/*choose_min_chunk*/
t_node	*choose_min_chunk(int num1, int num2, int num3, t_list_mark *ls_mark);
int		move_element1(int chunk, t_node *next_node, t_list_mark *ls_mark, \
	int chunk_case);

/*linked_list_functions*/
int		count_elements_in_stack_a(t_list_mark *ls_mark);
int		count_elements_in_stack_b(t_list_mark *ls_mark);
void	add_node_back(int data, t_list_mark *ls_mark);
void	print_list(t_list_mark ls_mark);
void	check_flag_and_print(int flag, char *str, t_list_mark *ls_mark);

/*parse_arguments*/
void	split_arg_and_add_node_back(char **array_of_str, t_list_mark *ls_mark);
void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark);
void	check_duplicates(t_list_mark ls_mark);

/*swap*/
void	sa(t_list_mark *ls_mark);
void	sb(t_list_mark *ls_mark);
void	ss(t_list_mark *ls_mark);

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

/*merge*/
void	merge_to_stack_a(int num_of_nums, t_list_mark *ls_mark, int order);
void	merge_to_stack_b(int num_of_nums, t_list_mark *ls_mark, int order);

/*print_errors_and_exit*/

/*sort_fix_lt_4_numbers*/
void	sort_fix_2_numbers(t_list_mark *ls_mark, int order);
void	sort_fix_3_numbers_ascend(t_list_mark *ls_mark);
void	sort_fix_3_numbers_descend(t_list_mark *ls_mark);
void	sort_fix_lt_4_numbers(int num_of_nums, t_list_mark *ls_mark, int order);

/*sort_skip_lt_4_numbers*/
void	sort_skip_3_numbers_ascend(t_list_mark *ls_mark);
void	sort_skip_3_numbers_descend(t_list_mark *ls_mark);
void	sort_skip_lt_4_numbers(int num_of_nums, t_list_mark *ls_mark, \
	int order);

/*sort*/
void	rr_and_rb(int rr_count, int rb_count, t_list_mark *ls_mark);
void	sort_skip(int num_of_nums, t_list_mark *ls_mark, int order);
void	sort_fix(int num_of_nums, t_list_mark *ls_mark, int order);
void	final_sort(int num_of_nums, t_list_mark *ls_mark);

#endif
