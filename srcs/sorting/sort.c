/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/13 12:44:03 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_element **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = get_top(*stack_a);
	middle = get_element(*stack_a, 1)->value;
	bottom = get_bottom(*stack_a);
	if (top > middle && bottom > middle && top < bottom)
		swap(stack_a, 'a');
	else if (top > middle && middle > bottom && top > bottom)
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (top > middle && bottom > middle && top > bottom)
		rotate(stack_a, 'a');
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (top < middle && middle > bottom && top > bottom)
		reverse_rotate(stack_a, 'a');
}

static void	move_opti(t_element **a, int i)
{
	int			lowest;
	t_element	*tmp;
	int			index;

	tmp = (*a);
	index = 0;
	lowest = get_lowest(*a)->value;
	while (tmp)
	{
		if (tmp->value == lowest)
			break ;
		index ++;
		tmp = tmp->next;
	}
	get_lowest_top(a, index, i);
}

void	sort_5(t_element **a, t_element **b)
{
	pre_sort(a);
	if (element_size(*a) == 5)
	{
		move_opti(a, 0);
		push(a, b, 'b');
		move_opti(a, 1);
		push(a, b, 'b');
		sort_3(a);
		push(b, a, 'a');
		push(b, a, 'a');
		if (!is_sorted(*a))
			rotate(a, 'a');
	}
	else
	{
		move_opti(a, 0);
		push(a, b, 'b');
		sort_3(a);
		push(b, a, 'a');
	}
}

void	sort_bigger(t_element **stack_a, t_element **stack_b)
{
	size_t		length;
	size_t		i;
	size_t		j;
	int			k;

	length = element_size(*stack_a);
	i = 0;
	pre_sort(stack_a);
	while (!is_sorted(*stack_a))
	{
		j = 0;
		while (j < length)
		{
			k = (*stack_a)->value >> i;
			if ((k & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		while ((*stack_b))
			push(stack_b, stack_a, 'a');
		i++;
	}
}

void	sort(t_element **stack_a, t_element **stack_b)
{
	size_t	length;

	length = element_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (length == 2)
		swap(stack_a, 'a');
	else if (length == 3)
		sort_3(stack_a);
	else if (length <= 5)
		sort_5(stack_a, stack_b);
	else
		sort_bigger(stack_a, stack_b);
}
