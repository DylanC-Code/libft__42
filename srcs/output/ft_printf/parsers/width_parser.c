/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:48:23 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_width(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_width(t_format *format, char **p_str)
{
	int	padding;

	padding = 0;
	if (!*p_str)
		return (P_ERROR);
	while (**p_str && ft_isdigit(**p_str))
	{
		padding = padding * 10 + **p_str - '0';
		*p_str = *p_str + 1;
		format->len++;
	}
	if (!padding)
		return (P_NOOP);
	format->width = padding;
	return (P_SUCCESS);
}
