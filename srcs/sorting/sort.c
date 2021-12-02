/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:52:31 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/02 14:33:17 by                  ###   ########.fr       */
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

void	sort_5(t_element **stack_a, t_element **stack_b)
{
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	if (get_top(*stack_b) > get_bottom(*stack_b))
		swap(stack_b, 'b');
	while (get_top(*stack_a) < get_top(*stack_b) && get_bottom(*stack_a) > get_top(*stack_b))
		rotate(stack_a, 'a');
	rotate(stack_a, 'a');
	push(stack_b, stack_a, 'a');
	while (get_top(*stack_a) < get_top(*stack_b) && get_bottom(*stack_a) > get_top(*stack_b))
		rotate(stack_a, 'a');
	rotate(stack_a, 'a');
	push(stack_b, stack_a, 'a');
	//while(!is_sorted(*stack_a))
	//	rotate(stack_a, 'a');
	/*
	while (get_top(*stack_a) < get_top(*stack_b))
		reverse_rotate(stack_a, 'a');
	push(stack_b, stack_a, 'a');
	*/
}

int    nb_of_rotates(t_element *a, int i)
{
	int moves;

	moves = 0;
	if (i <= (int) element_size(a) / 2)
		return (i);
	if (i > (int) element_size(a) / 2)
		moves = element_size(a) - i;
	return (moves);
}

void    get_closest_to_top(t_element *a, t_element *b, t_hold hold)
{
	int    nb_first_moves;
	int    nb_scd_moves;

	(void) b;
	nb_first_moves = nb_of_rotates(a, hold.first_hold);
	nb_scd_moves = nb_of_rotates(a, hold.second_hold);
	if (hold.first_hold == -1 && hold.second_hold == -1)
		return ;
	if (nb_first_moves < nb_scd_moves || hold.second_hold == -1)
	{
		while (nb_first_moves > 0)
		{
			rotate(&a, 'a');
			nb_first_moves --;
		}
	}
	else
	{
		while (nb_scd_moves > 0)
		{
			reverse_rotate(&a, 'a');
			nb_scd_moves --;
		}
	}
}

int        is_in_chunk(int a, t_chunk chunk)
{
	if (a >= chunk.min && a <= chunk.max)
		return (1);
	return (0);
}

int    get_hold_element(t_element *a, int hold)
{
	int    i;

	i = 0;
	while (a)
	{
		if (a->value == hold)
			return (i);
		i ++;
		a = a->next;
	}
	return (-1);
}

t_hold    get_hold(t_element *a, t_chunk chunk)
{
	t_hold    hold;
	t_element    *temp;
	int        check;

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

void    sort_100(t_element **stack_a, t_element **stack_b)
{
	t_chunk    chunk;
	t_hold    hold;

	chunk.min = 0;
	chunk.max = 19;
	hold = get_hold(*stack_a, chunk);
	get_closest_to_top(*stack_a, *stack_b, hold);
}

void	sort_500(t_element **stack_a, t_element **stack_b)
{
	(void) stack_a;
	(void) stack_b;
}

void	sort(t_element **stack_a, t_element **stack_b)
{
	size_t	length;

	length = element_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (length <= 3)
		sort_3(stack_a);
	else if (length <= 5)
		sort_5(stack_a, stack_b);
	else if (length <= 100)
		sort_100(stack_a, stack_b);
	else if (length <= 500)
		sort_500(stack_a, stack_b);
}
