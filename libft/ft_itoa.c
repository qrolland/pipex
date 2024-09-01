/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:52:06 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/23 17:27:46 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;
	long int	nbr;

	nbr = n;
	len = ft_itoa_len(n);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		dest[0] = '-';
	}
	while (nbr >= 10)
	{
		dest[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	dest[len--] = nbr + '0';
	return (dest);
}
