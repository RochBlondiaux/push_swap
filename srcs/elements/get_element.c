/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:37:10 by rblondia          #+#    #+#             */
/*   Updated: 2021/11/29 13:43:10 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_element	*get_element(t_element *lst, int index)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		if (i == index)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
}
