/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:02:04 by dylan             #+#    #+#             */
/*   Updated: 2025/12/11 17:16:21 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTSORT_H
# define FT_LSTSORT_H

# include "list.h"

struct		s_info
{
	void	*head;
	void	*mid;
	void	*tail;
	size_t	len;
};

void		*ft_lstsort(void *restrict head,
				const struct s_list_ops *restrict ops);

#endif
