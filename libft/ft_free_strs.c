/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:53:58 by qrolland          #+#    #+#             */
/*   Updated: 2022/11/28 16:41:27 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strs(char **strs)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (strs[size])
		size++;
	while (i < size)
		free(strs[i++]);
	free(strs);
}
