/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:50:27 by qrolland          #+#    #+#             */
/*   Updated: 2022/05/12 12:55:15 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((const unsigned char *)s1)[i]
				== ((const unsigned char *)s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i]);
}
