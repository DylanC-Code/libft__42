/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_raw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:48:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 15:05:11 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/ft_printf/ft_printf.h"

t_element	*create_text_raw(char *text, size_t len)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (!node)
		return (NULL);
	node->type = T_TEXT;
	node->data.text_raw.text = text;
	node->data.text_raw.len = len;
	return (node);
}
