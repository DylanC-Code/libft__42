/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:38:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_zero(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_zero(t_format *format, char **p_str)
{
	if (!p_str || !*p_str)
		return (P_ERROR);
	if (**p_str != '0')
		return (P_NOOP);
	if (format->zero == true)
		return (P_ERROR);
	format->zero = true;
	format->len++;
	*p_str = *p_str + 1;
	return (P_SUCCESS);
}
