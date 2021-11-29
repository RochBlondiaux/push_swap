/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:22:43 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 17:36:56 by rblondia         ###   ########.fr       */
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
# include "../libft/libft.h"

/**
 * Structures
 */
typedef struct s_element {
	int					value;
	struct s_element	*next;
}						t_element;

/**
 * Elements operations
 */
void		swap(t_element **stack, char stack_name);
void		swap_both(t_element **stack_a, t_element **stack_b);
void		push(t_element **source, t_element **target, char name);
void		rotate(t_element **stack, char stack_name);
void		rotate_both(t_element **stack_a, t_element **stack_b);
void		reverse_rotate(t_element **stack, char stack_name);
void		reverse_rotate(t_element **stack, char stack_name);
void		reverse_rotate_both(t_element **stack_a, t_element **stack_b);

/**
 * Elements
 */
size_t		element_size(t_element *lst);
t_element	*get_element(t_element *lst, int index);
t_element	*new_element(int value, t_element *next);
void		clear_elements(t_element **stack_a, t_element **stack_b);
void		element_iter(t_list *lst, void (*f)(int));

/**
 * Parsing
 */
void		parse(t_element **lst, char **args, int argc);

/**
 * Utils
 */
void		create_empty(t_element **lst, int size);
void		exit_error(void);

#endif
