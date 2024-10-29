/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:26:24 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/04 15:13:18 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_wordcount(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] == sep)
		count = 0;
	else
		count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i + 1] != '\0' && str[i + 1] != sep)
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

int	ft_wordlen(char *substr, char sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (substr[i] != '\0' && substr[i] != sep)
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_issep(char *s, char c)
{
	if (*s == c)
		return (1);
	else
		return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		w;
	char	*s2;

	w = 0;
	s2 = (char *)s;
	if (s2 == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_wordcount(s2, c) + 1));
	if (res == NULL)
		return (NULL);
	while (*s2)
	{
		if (*s2 && ft_issep (s2, c) == 0)
		{
			res[w++] = ft_substr(s2, 0, ft_wordlen(s2, c));
			s2 += ft_wordlen(s2, c);
		}
		while (*s2 && ft_issep (s2, c) == 1)
		{
			s2++;
		}
	}
	res[w] = NULL;
	return (res);
}

// #include <stdio.h>
// int main(int ac, char **av, char **envp)
// {
// 	char	**paths;
// 	char	**cmds;
// 	char	*path;
// 	char	*cmd;
// 	cmd = "nothing";
// 	paths = path_finder(envp);
// 	cmds = ft_split(cmd, ' ');
// 	path = path_maker(paths, cmds[0]);
// 	int i = 0;
// 	while (paths[i])
// 	{
// 		printf("no %d paths = %s\n",i, paths[i]);
// 		i++;
// 	}
// 	int k = 0;
// 	while (cmds[k])
// 	{
// 		printf("no %d cmds = %s\n",k, cmds[k]);
// 		k++;
// 	}
// 	printf("the final path = %s", path);
// 	return 0;
//}
// #include <stdio.h>
// int main(int ac, char **av, char **envp)
// {
// 	char *path;
// 	char **paths;
// 	char *final;
// 	char **cmds;
// 	char *cmd;
// 	cmd = "nothing";
// 	paths = path_finder(envp);	
// 	cmds = ft_split(cmd, ' ');
// 	int i = 0;
// 	while (paths[i])
// 	{
// 		printf("no %d paths = %s\n",i, paths[i]);
// 		i++;
// 	}
// 	int c = 0;
// 	c = ft_wordcount(cmd, ' ');
// 	printf("word = %d\n",c);
// 	int k = 0;
// 	while (cmds[k])
// 	{
// 		printf("no %d cmds = %s\n",k, cmds[k]);
// 		k++;
// 	}
// 	printf("%s\n",cmds[k]);
// 	return 0;
// }