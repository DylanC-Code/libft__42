/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:06:58 by dylan             #+#    #+#             */
/*   Updated: 2025/12/12 11:18:33 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list/ft_lstreverse.h"

void	*ft_lstreverse(void *restrict curr, void *restrict prev,
		const struct s_list_ops *restrict ops)
{
	void	*next;
	void	*head;

	next = ops->get_next(curr);
	if (next)
		head = ft_lstreverse(next, curr, ops);
	else
		head = curr;
	ops->add_back(curr, prev);
	return (head);
}
