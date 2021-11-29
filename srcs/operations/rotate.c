/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:18:21 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 17:24:05 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_silently(t_element **stack)
{
	t_element	*tmp;
	int			first;

	tmp = *stack;
	first = tmp->value;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next != NULL)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->value = first;
}

void	rotate(t_element **stack, char stack_name)
{
	rotate_silently(stack);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(stack_name, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate_both(t_element **stack_a, t_element **stack_b)
{
	rotate_silently(stack_a);
	rotate_silently(stack_b);
	ft_putstr_fd("rr\n", 1);
}