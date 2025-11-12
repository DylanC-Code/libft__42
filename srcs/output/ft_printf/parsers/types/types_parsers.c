/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:57:15 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_type(t_format *format, char c);

/* =============== Definition =============== */

t_status	parse_type(t_format *format, char c)
{
	format->type = c;
	if (format->type == '%')
		return (P_SUCCESS);
	else if (ft_strchr(P_INT_TYPES, format->type))
		return (parse_int_type(format));
	else if (format->type == 's')
		return (parse_pchar_type(format));
	else if (format->type == 'p')
		return (parse_pvoid_type(format));
	else if (ft_strchr(P_UNSIGNED_INT_TYPES, format->type))
		return (parse_unsigned_int_type(format));
	return (P_ERROR);
}
