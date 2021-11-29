/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:53:01 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 16:12:44 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_element **source, t_element **target, char name)
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
	ft_putchar_fd('p', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
}
