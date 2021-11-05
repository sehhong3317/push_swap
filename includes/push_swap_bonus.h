/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:52:28 by sehee             #+#    #+#             */
/*   Updated: 2021/11/05 15:46:56 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	100
# endif

# define STDIN_FD	0
# define STDOUT_FD	1
# define STDERR_FD	2

# include "libft.h"
# include <unistd.h>
# include <limits.h>

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

/*get_next_line_bonus*/
int		get_next_line(int fd, char **line);

/*parse_arguments_bonus*/
void	split_arg_and_add_node_front(char **array_of_str, t_list_mark *ls_mark);
void	parse_arguments(int argc, char **argv, t_list_mark *ls_mark);
void	check_if_duplicated(t_list_mark ls_mark);
void	check_if_already_sorted(t_list_mark ls_mark);

/*linked_list_functioins*/
int		count_elements_in_stack_a(t_list_mark *ls_mark);
int		count_elements_in_stack_b(t_list_mark *ls_mark);
void	add_node_front(int data, t_list_mark *ls_mark);

/*push_bonus*/
void	pa(t_list_mark *ls_mark);
void	pb(t_list_mark *ls_mark);

/*reverse_rotate_bonus*/
void	rra(t_list_mark *ls_mark);
void	rrb(t_list_mark *ls_mark);
void	rrr(t_list_mark *ls_mark);

/*rotate_bonus*/
void	ra(t_list_mark *ls_mark);
void	rb(t_list_mark *ls_mark);
void	rr(t_list_mark *ls_mark);

/*swap_bonus*/
void	sa(t_list_mark *ls_mark);
void	sb(t_list_mark *ls_mark);
void	ss(t_list_mark *ls_mark);

#endif