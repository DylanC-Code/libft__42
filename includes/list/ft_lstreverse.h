/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:07:11 by dylan             #+#    #+#             */
/*   Updated: 2025/12/12 11:15:59 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTREVERSE_H
# define FT_LSTREVERSE_H

# include "list.h"

void	*ft_lstreverse(void *restrict curr, void *restrict prev,
			const struct s_list_ops *restrict ops);

#endif
