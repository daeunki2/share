/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:35:37 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/11 19:54:55 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (s);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*combo;
	int			len_total;
	int			i;
	int			t;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	combo = malloc(sizeof(char) * len_total);
	if (combo == NULL)
		return (NULL);
	i = 0;
	t = 0;
	while (s1[i] != '\0')
	{
		combo[i] = s1[i];
		i++;
	}
	while (s2[t] != '\0')
	{
		combo [i + t] = s2[t];
		t++;
	}
	combo[i + t] = '\0';
	return (combo);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while ((c1[i] != '\0' || c2[i] != '\0') && n > 0)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
		n--;
	}
	return (0);
}
