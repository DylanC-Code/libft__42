/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_transformer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:23:29 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	apply_sharp(t_format *format, bool upper);

/* =============== Definition =============== */

t_status	apply_sharp(t_format *format, bool upper) {
  char *result;

  if (!format->sharp || (format->text_len == 1 && format->text[0] == '0'))
    return (P_NOOP);
  if (upper)
    result = ft_strjoin("0X", format->text);
  else
    result = ft_strjoin("0x", format->text);
  if (!result)
    return (P_ERROR);
  free(format->text);
  format->text = result;
  format->text_len = ft_strlen(result);
  return (P_SUCCESS);
}
