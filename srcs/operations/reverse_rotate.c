/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 17:08:53 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_silently(t_element **nums)
{
	t_element	*front;
	t_element	*back;
	t_element	*head;

	head = *nums;
	back = *nums;
	front = *nums;
	if (*nums == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*nums = front;
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
