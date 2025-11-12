/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:37:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 15:00:28 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "list.h"
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include "output/ft_printf/parsers.h"
# include "output/ft_printf/transformers.h"
# include "output/ft_printf/types.h"

# define P_FORMAT_START '%'
# define P_FORMATS ""
# define P_FLAGS "# +-0"
# define P_TYPES "cspdiuxX%"

# define P_INT_TYPES "cdi"
# define P_UNSIGNED_INT_TYPES "uxX"

# define P_ERROR -1
# define P_NOOP 0
# define P_SUCCESS 1

int			ft_printf(const char *str, ...) __attribute__((format(printf, 1,
						2)));

void		free_list_el(t_list *head);
void		free_el(t_element *el);

/* Text Raw */

t_element	*create_text_raw(char *p_start, size_t len);

/* Format */

t_element	*create_format(void);

/* Printers */

int			print_contents(t_list *head);
int			print_n(char *text, size_t n);

#endif
