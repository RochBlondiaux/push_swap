#include "../../includes/push_swap.h"

void	dispatch_command(char *cmd, t_element **stack_a, t_element **stack_b)
{
	if (ft_strcmp(cmd, "sa\n"))
		swap_silently(stack_a);
	else if (ft_strcmp(cmd, "sb\n"))
		swap_silently(stack_b);
	else if (ft_strcmp(cmd, "ss\n"))
	{
		swap_silently(stack_a);
		swap_silently(stack_b);
	}
	else if (ft_strcmp(cmd, "pa\n"))
		push_silently(stack_b, stack_a);
	else if (ft_strcmp(cmd, "pb\n"))
		push_silently(stack_a, stack_b);
	else if (ft_strcmp(cmd, "ra\n"))
		rotate_silently(stack_a);
	else if (ft_strcmp(cmd, "rb\n"))
		rotate_silently(stack_b);
	else if (ft_strcmp(cmd, "rr\n"))
	{
		rotate_silently(stack_a);
		rotate_silently(stack_b);
	}
	else if (ft_strcmp(cmd, "rra\n"))
		reverse_rotate_silently(stack_a);
	else if (ft_strcmp(cmd, "rrb\n"))
		reverse_rotate_silently(stack_b);
	else if (ft_strcmp(cmd, "rrr\n"))
	{
		reverse_rotate_silently(stack_a);
		reverse_rotate_silently(stack_b);
	}
	else
		exit_error();
}

void handle_standard_input(t_element *stack_a, t_element *stack_b)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		dispatch_command(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (!stack_b && stack_a && is_sorted(stack_a))
		printf("O.K\n");
	else
		printf("K.O\n");
}

int main(int argc, char **argv)
{
	t_element	*stack_a;
	t_element	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	parse(&stack_a, argv, argc);
	print_stacks(stack_a, stack_b);
	handle_standard_input(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	clear_elements(&stack_a, &stack_b);
	return (0);
}