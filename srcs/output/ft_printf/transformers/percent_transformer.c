/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_transformer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:46:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "output/ft_printf/ft_printf.h"

/* =============== Declaration =============== */

t_status	transform_percent(t_format *format);

/* =============== Definition =============== */
t_status	transform_percent(t_format *format) {
  format->text = ft_strdup("%");
  if (!format->text)
    return (P_ERROR);
  format->text_len = ft_strlen(format->text);
  return (P_SUCCESS);
}
