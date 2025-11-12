/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:56:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_precision(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_precision(t_format *format, char **p_str)
{
	unsigned int	precision;

	precision = 0;
	if (**p_str != '.')
		return (P_NOOP);
	*p_str = *p_str + 1;
	format->len++;
	while (**p_str && ft_isdigit(**p_str))
	{
		precision = precision * 10 + **p_str - '0';
		*p_str = *p_str + 1;
		format->len++;
	}
	if (precision > INT_MAX)
		return (P_ERROR);
	format->precision = precision;
	return (P_SUCCESS);
}
