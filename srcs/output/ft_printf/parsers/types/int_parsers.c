/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:19:27 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_int_type(t_format *format);
t_status	parse_type_di(t_format *format);
t_status	parse_type_c(t_format *format);

/* =============== Definition =============== */

t_status	parse_int_type(t_format *format)
{
	if (format->type == 'd' || format->type == 'i')
		return (parse_type_di(format));
	if (format->type == 'c')
		return (parse_type_c(format));
	return (P_ERROR);
}

t_status	parse_type_di(t_format *format)
{
	if (format->sharp)
		return (P_ERROR);
	return (P_SUCCESS);
}

t_status	parse_type_c(t_format *format)
{
	if (format->zero)
		return (P_ERROR);
	else if (format->plus)
		return (P_ERROR);
	else if (format->space)
		return (P_ERROR);
	else if (format->sharp)
		return (P_ERROR);
	else if (format->precision >= 0)
		return (P_ERROR);
	return (P_SUCCESS);
}
