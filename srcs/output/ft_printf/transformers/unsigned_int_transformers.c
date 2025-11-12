/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_transformers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:08:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_unsigned_int(t_format *format, unsigned int nbr);
t_status	transform_u(t_format *format, unsigned int nbr);
t_status	transform_x(t_format *format, unsigned int nbr);
t_status	transform_upper_x(t_format *format, unsigned int nbr);

/* =============== Definition =============== */

t_status	transform_unsigned_int(t_format *format, unsigned int nbr)
{
	if (format->type == 'u')
		return (transform_u(format, nbr));
	else if (format->type == 'x')
		return (transform_x(format, nbr));
	else if (format->type == 'X')
		return (transform_upper_x(format, nbr));
	return (P_ERROR);
}

t_status	transform_u(t_format *format, unsigned int nbr)
{
	format->text = ft_uitoa(nbr);
	if (!format->text)
		return (P_ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == P_ERROR)
		return (P_ERROR);
	if (apply_width(format) == P_ERROR)
		return (P_ERROR);
	return (P_SUCCESS);
}

t_status	transform_x(t_format *format, unsigned int nbr)
{
	format->text = ft_uitoa_base(nbr, "0123456789abcdef");
	if (!format->text)
		return (P_ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == P_ERROR)
		return (P_ERROR);
	if (apply_sharp(format, false) == P_ERROR)
		return (P_ERROR);
	if (apply_width(format) == P_ERROR)
		return (P_ERROR);
	return (P_SUCCESS);
}

t_status	transform_upper_x(t_format *format, unsigned int nbr)
{
	format->text = ft_uitoa_base(nbr, "0123456789ABCDEF");
	if (!format->text)
		return (P_ERROR);
	format->text_len = ft_strlen(format->text);
	if (apply_precision(format) == P_ERROR)
		return (P_ERROR);
	if (apply_sharp(format, true) == P_ERROR)
		return (P_ERROR);
	if (apply_width(format) == P_ERROR)
		return (P_ERROR);
	return (P_SUCCESS);
}
