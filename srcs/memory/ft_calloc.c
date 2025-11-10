/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:23:37 by dcastor           #+#    #+#             */
/*   Updated: 2025/11/10 13:54:55 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mptr;
	size_t			i;

	if (nmemb * size > INT_MAX)
		return (0);
	if (!nmemb || !size)
		return (NULL);
	i = 0;
	mptr = malloc(size * nmemb);
	if (!mptr)
		return (NULL);
	while (i < size * nmemb)
	{
		mptr[i] = '\0';
		i++;
	}
	return (mptr);
}
