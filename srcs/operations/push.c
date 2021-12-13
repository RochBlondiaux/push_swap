/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 12:42:55 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_silently(t_element **source, t_element **target)
{
	t_element	*tmp;
	t_element	*element;

	if (!*source)
		return ;
	element = (*source)->next;
	tmp = *source;
	tmp->next = *target;
	*target = tmp;
	*source = element;
}

void	push(t_element **source, t_element **target, char name)
{
	push_silently(source, target);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	if (name == 'a')
		print_stacks(*target, *source);
	else
		print_stacks(*source, *target);
}
