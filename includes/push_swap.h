/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:22:43 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/02 18:13:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**
 * Libraries
 */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

/**
 * Constants
 */
# define DEBUG 0

/**
 * Structures
 */
typedef struct s_element {
	int					value;
	struct s_element	*next;
}						t_element;

typedef struct s_chunk {
	int    min;
	int    max;
}        t_chunk;

typedef struct s_hold {
	int    first_hold;
	int    second_hold;
}        t_hold;

/**
 * Elements operations
 */
void		swap(t_element **stack, char stack_name);
void		swap_both(t_element **stack_a, t_element **stack_b);
void		push_silently(t_element **source, t_element **target);
void		push(t_element **source, t_element **target, char name);
void		rotate(t_element **stack, char stack_name);
void		rotate_both(t_element **stack_a, t_element **stack_b);
void		reverse_rotate(t_element **stack, char stack_name);
void		reverse_rotate(t_element **stack, char stack_name);
void		reverse_rotate_both(t_element **stack_a, t_element **stack_b);
void		swap_silently(t_element **stack);
void		rotate_silently(t_element **stack);
void		reverse_rotate_silently(t_element **nums);

/**
 * Elements
 */
size_t		element_size(t_element *lst);
t_element	*get_element(t_element *lst, int index);
t_element	*new_element(int value, t_element *next);
void		clear_elements(t_element **stack_a, t_element **stack_b);
void		element_iter(t_list *lst, void (*f)(int));
t_element	*get_last_element(t_element *lst);
int			get_top(t_element *stack);
int			get_bottom(t_element *stack);
int			get_lowest(t_element *stack);
int 		get_bigger(t_element *stack);

/**
 * Parsing
 */
void		parse(t_element **lst, char **args, int argc);

/**
 * Sorting
 */
void		good_sort(t_element **stack_a, t_element **stack_b);
void		sort(t_element **stack_a, t_element **stack_b);
/**
 * Utils
 */
void		exit_error(void);
int			is_sorted(t_element *stack);
void		print_stacks(t_element *stack_a, t_element *stack_b);
t_hold	    get_hold(t_element *a, t_chunk chunk);
int		    get_hold_element(t_element *a, int hold);
int	        is_in_chunk(int a, t_chunk chunk);
void		get_closest_to_top(t_element **a, t_element *b, t_hold hold);
int			nb_of_rotates(t_element *a, int i);
int			ft_strcmp(char *a, char *b);

#endif
