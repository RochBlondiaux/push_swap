/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:39 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 14:52:37 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_element	*new_element(int value, t_element *next)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->value = value;
	element->next = next;
	return (element);
}
