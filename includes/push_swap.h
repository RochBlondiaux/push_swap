/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:22:43 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 14:50:17 by rblondia         ###   ########.fr       */
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
 * Elements
 */
size_t		element_size(t_element *lst);
t_element	*get_element(t_element *lst, int index);
t_element	*new_element(int value, t_element *next);
void		clear_elements(t_element **lst);
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
