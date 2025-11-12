/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchar_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:08:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_pchar_type(t_format *format);

/* =============== Definition =============== */

t_status	parse_pchar_type(t_format *format)
{
	if (format->plus || format->sharp)
		return (P_ERROR);
	return (P_SUCCESS);
}
