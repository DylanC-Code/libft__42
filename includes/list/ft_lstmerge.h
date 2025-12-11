/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:12:51 by dylan             #+#    #+#             */
/*   Updated: 2025/12/11 17:15:37 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTMERGE_H
# define FT_LSTMERGE_H

# include "list.h"

void	*ft_lstmerge_sorted_lls(void *restrict list_a, void *restrict list_b,
			const struct s_list_ops *restrict ops);
void	*ft_lstmerge(void *a, void *b, const struct s_list_ops *ops);

#endif
