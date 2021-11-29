/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:24:43 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 18:03:38 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_silently(t_element **head)
{
	t_element	*tmp_last;
	t_element	*previous;
	t_element	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return ;
	tmp_last = stack;
	while (tmp_last->next)
	{
		previous = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = stack;
	previous->next = NULL;
	*head = tmp_last;
}

void	reverse_rotate(t_element **stack, char stack_name)
{
	reverse_rotate_silently(stack);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putchar_fd('\n', 1);
}

void	reverse_rotate_both(t_element **stack_a, t_element **stack_b)
{
	reverse_rotate_silently(stack_a);
	reverse_rotate_silently(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
