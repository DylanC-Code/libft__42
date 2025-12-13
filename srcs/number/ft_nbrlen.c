/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:19:24 by dylan             #+#    #+#             */
/*   Updated: 2025/12/13 10:21:56 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_nbrlen(int nbr, unsigned int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		len++;
		nbr /= base;
	}
	return (len);
}
