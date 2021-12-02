#include "../../includes/push_swap.h"

void	good_sort(t_element **stack_a, t_element **stack_b)
{
	if ((get_top(*stack_b) > get_top(*stack_a)) && get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (get_top(*stack_b) > get_top(*stack_a))
			rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
	}
	if ((get_top(*stack_b) < get_top(*stack_a)) && get_top(*stack_b) < get_bottom(*stack_a))
	{
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
		push(stack_b, stack_a, 'b');
	}
	if ((get_top(*stack_b) < get_top(*stack_a)) && get_top(*stack_b) > get_bottom(*stack_a))
	{
		push(stack_b, stack_a, 'b');
		while (!is_sorted(*stack_a))
			reverse_rotate(stack_a, 'a');
	}
}