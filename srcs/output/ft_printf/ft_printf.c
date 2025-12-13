/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:54:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/12/13 10:39:00 by dylan            ###   ########.fr       */
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
		return (va_end(args), P_ERROR);
	list = NULL;
	if (parse_str((char *)str, &list) == P_ERROR)
		return (free_list_el(list), va_end(args), P_ERROR);
	if (!list)
		return (va_end(args), 0);
	if (apply_formats(list, args) == P_ERROR)
		return (free_list_el(list), va_end(args), P_ERROR);
	return (va_end(args), print_contents(list));
}
