/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvoid_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:56:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:58:34 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	parse_pvoid_type(t_format *format);

/* =============== Definition =============== */

t_status	parse_pvoid_type(t_format *format) {
  if (format->sharp || format->zero || format->space ||
      format->precision >= 0 || format->plus)
    return (P_ERROR);
  return (P_SUCCESS);
}
