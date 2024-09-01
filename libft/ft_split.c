/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:51:56 by qrolland          #+#    #+#             */
/*   Updated: 2022/06/23 17:28:57 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_charset(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

static int	get_nbr_word(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (char_is_in_charset(str[i], c))
			i++;
		if (str[i])
		{
			count++;
			while (!char_is_in_charset(str[i], c) && str[i])
				i++;
		}
	}
	return (count);
}

static char	*get_str_word(int *index, char const *str, char c)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	while (char_is_in_charset(str[*index], c))
		(*index)++;
	while (!char_is_in_charset(str[*index + len], c) && str[*index + len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = str[*index];
		i++;
		(*index)++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		nbr_word;
	int		i;
	int		j;
	char	**dest;

	if (!s)
		return (NULL);
	nbr_word = get_nbr_word(s, c);
	dest = malloc((nbr_word + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nbr_word)
	{
		dest[i] = get_str_word(&j, s, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
