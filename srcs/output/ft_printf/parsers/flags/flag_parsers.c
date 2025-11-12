/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:54:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_flags(t_format *format, char **p_str);

/* =============== Definition =============== */

t_status	parse_flags(t_format *format, char **p_str)
{
	t_status	minus_status;
	t_status	zero_status;
	t_status	plus_status;
	t_status	space_status;
	t_status	hash_status;

	minus_status = parse_minus(format, p_str);
	if (minus_status == P_ERROR)
		return (P_ERROR);
	zero_status = parse_zero(format, p_str);
	if (zero_status == P_ERROR)
		return (P_ERROR);
	hash_status = parse_hash(format, p_str);
	if (hash_status == P_ERROR)
		return (P_ERROR);
	space_status = parse_space(format, p_str);
	if (space_status == P_ERROR)
		return (P_ERROR);
	plus_status = parse_plus(format, p_str);
	if (plus_status == P_ERROR)
		return (P_ERROR);
	if (minus_status || zero_status || hash_status || space_status
		|| plus_status)
		return (parse_flags(format, p_str), P_SUCCESS);
	return (P_NOOP);
}
