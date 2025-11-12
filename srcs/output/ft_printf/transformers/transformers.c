/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:55:32 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_formats(t_list *head, va_list args);
t_status	apply_format(t_element *element, va_list args);

/* =============== Definition =============== */

t_status	apply_formats(t_list *head, va_list args)
{
	t_list		*next;
	t_element	*element;

	if (!head)
		return (P_NOOP);
	while (head)
	{
		element = head->content;
		next = head->next;
		if (apply_format(element, args) == P_ERROR)
			return (P_ERROR);
		head = next;
	}
	return (P_SUCCESS);
}

t_status	apply_format(t_element *element, va_list args)
{
	t_format	*format;

	if (element->type == T_TEXT)
		return (P_NOOP);
	format = &element->data.format;
	if (ft_strchr(P_INT_TYPES, format->type))
		return (transform_int(format, va_arg(args, int)));
	else if (format->type == 's')
		return (transform_pchar(format, va_arg(args, char *)));
	else if (format->type == 'p')
		return (transform_pvoid(format, va_arg(args, void *)));
	else if (ft_strchr(P_UNSIGNED_INT_TYPES, format->type))
		return (transform_unsigned_int(format, va_arg(args, unsigned int)));
	else if (format->type == '%')
		return (transform_percent(format));
	return (P_ERROR);
}
