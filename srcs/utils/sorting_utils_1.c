/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:19:19 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/30 11:19:20 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	good_sort(t_element **stack_a, t_element **stack_b)
{
	if ((get_top(*stack_b) > get_top(*stack_a))
		&& get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (get_top(*stack_b) > get_top(*stack_a))
			rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
	}
	if ((get_top(*stack_b) < get_top(*stack_a))
		&& get_top(*stack_b) > get_bottom(*stack_a))
	{
		push(stack_b, stack_a, 'b');
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
	}
	if (get_top(*stack_a) > get_element(*stack_a, 1)->value)
		swap(stack_a, 'a');
}

t_hold	get_hold(t_element *a, t_chunk chunk)
{
	t_hold		hold;
	t_element	*temp;
	int			check;

	check = 0;
	hold.first_hold = -1;
	hold.second_hold = -1;
	temp = (a);
	while (temp && check != 2)
	{
		if (is_in_chunk(temp->value, chunk) && check == 0)
		{
			hold.first_hold = get_hold_element((a), temp->value);
			check = 1;
			temp = temp->next;
		}
		if (is_in_chunk(temp->value, chunk) && check == 1)
		{
			hold.second_hold = get_hold_element(a, temp->value);
			check = 2;
		}
		temp = temp->next;
	}
	return (hold);
}
