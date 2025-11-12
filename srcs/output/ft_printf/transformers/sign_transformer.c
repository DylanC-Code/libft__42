/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_transformer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:11:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_sign(t_format *format, bool is_positive);

/* =============== Definition =============== */

t_status	apply_sign(t_format *format, bool is_positive)
{
	char	*result;

	if (!is_positive && *format->text != '-')
		result = ft_strjoin("-", format->text);
	else if (format->plus)
		result = ft_strjoin("+", format->text);
	else if (format->space)
		result = ft_strjoin(" ", format->text);
	else
		return (P_NOOP);
	if (!result)
		return (P_ERROR);
	free(format->text);
	format->text = result;
	format->text_len = ft_strlen(format->text);
	return (P_SUCCESS);
}
