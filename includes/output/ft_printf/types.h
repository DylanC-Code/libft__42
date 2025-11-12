/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:58:55 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 14:52:16 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "output/ft_printf/ft_printf.h"
#include <stdbool.h>

typedef int			t_status;

typedef enum e_element_type
{
	T_TEXT,
	T_FORMAT,
}					t_element_type;

typedef struct s_text_raw
{
	char			*text;
	size_t			len;
}					t_text_raw;

typedef struct s_format
{
	size_t			len;
	bool			minus;
	bool			zero;
	long			precision;
	bool			sharp;
	bool			space;
	bool			plus;
	unsigned int	width;
	unsigned char	type;
	char			*text;
	unsigned int	text_len;
}					t_format;

typedef union u_element_data
{
	t_text_raw		text_raw;
	t_format		format;
}					t_element_data;

typedef struct s_element
{
	t_element_type	type;
	t_element_data	data;
}					t_element;

#endif
