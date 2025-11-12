/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_parsers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:05:12 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_unsigned_int_type(t_format *format);
t_status	parse_type_u(t_format *format);
t_status	parse_type_xx(t_format *format);

/* =============== Definition =============== */

t_status	parse_unsigned_int_type(t_format *format)
{
	if (format->type == 'u')
		return (parse_type_u(format));
	if (format->type == 'x' || format->type == 'X')
		return (parse_type_xx(format));
	return (P_ERROR);
}

t_status	parse_type_u(t_format *format)
{
	if (format->plus || format->space || format->sharp)
		return (P_ERROR);
	return (P_SUCCESS);
}

t_status	parse_type_xx(t_format *format)
{
	if (format->plus || format->space)
		return (P_ERROR);
	return (P_SUCCESS);
}
