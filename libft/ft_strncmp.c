/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:38:49 by qrolland          #+#    #+#             */
/*   Updated: 2022/05/16 17:24:25 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (const unsigned char)s1[i] == (const unsigned char)s2[i]
		&& (const unsigned char)s1[i] && (const unsigned char)s2[i])
		i++;
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}
