/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_transformers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:17:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_int(t_format *format, int n);
t_status	transform_di(t_format *format, int nbr);

/* =============== Definition =============== */

t_status	transform_int(t_format *format, int n) {
  if (format->type == 'c')
    return (transform_c(format, n));
  else if (format->type == 'd' || format->type == 'i')
    return (transform_di(format, n));
  return (P_ERROR);
}

t_status	transform_di(t_format *format, int nbr) {
  bool is_positive;

  is_positive = nbr >= 0;
  format->text = ft_uitoa(ft_abs(nbr));
  if (!format->text)
    return (P_ERROR);
  format->text_len = ft_strlen(format->text);
  if (apply_precision(format) == P_ERROR)
    return (P_ERROR);
  if (apply_sign(format, is_positive) == P_ERROR)
    return (P_ERROR);
  if (apply_width(format) == P_ERROR)
    return (P_ERROR);
  return (P_SUCCESS);
}
