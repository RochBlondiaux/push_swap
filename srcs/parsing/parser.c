/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:08:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 22:21:54 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_data(t_element *lst)
{
	t_element	*tmp;
	t_element	*tmp1;
	int			count;

	tmp = lst;
	while (tmp)
	{
		count = 0;
		tmp1 = tmp;
		while (tmp1)
		{
			if (tmp1->value == tmp->value)
			{
				count++;
				if (count >= 2)
					exit_error();
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int	strlen_(char **a)
{
	int	l;

	if (!a)
		return (0);
	l = 0;
	while (l[a])
		l++;
	return (l);
}

int	contains_space(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (a[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	create_new_element(char *a, t_element **lst)
{
	int	tmp;

	if (!a || !a[0])
		exit(-1);
	tmp = ft_atoi(a);
	if (tmp == 0 && (a[0] != '0'))
		exit_error();
	*lst = new_element(tmp, *lst);
}

void	parse(t_element **lst, char **args, int argc)
{
	int			index;
	int			i;
	char		**strs;

	index = argc - 1;
	while (index > 0)
	{
		if (contains_space(args[index]))
		{
			strs = ft_split(args[index], ' ');
			i = strlen_(strs) - 1;
			while (i >= 0)
			{
				create_new_element(strs[i], lst);
				free(strs[i]);
				i--;
			}
			free(strs);
		}
		else
			create_new_element(args[index], lst);
		index--;
	}
	check_data(*lst);
}
