/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:41:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/12 15:02:13 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsome(t_list *head, int (*f)(t_list *))
{
	while (head)
	{
		if (f(head))
			return (true);
		head = head->next;
	}
	return (false);
}
