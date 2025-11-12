/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:21 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

int	ft_printf(const char *str, ...);

/* =============== Definition =============== */

int	ft_printf(const char *str, ...)
{
	t_list	*list;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (P_ERROR);
	list = NULL;
	if (parse_str((char *)str, &list) == P_ERROR)
		return (free_list_el(list), P_ERROR);
	if (!list)
		return (0);
	if (apply_formats(list, args) == P_ERROR)
		return (free_list_el(list), P_ERROR);
	return (print_contents(list));
}
