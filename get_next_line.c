/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/11 19:57:06 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(buf), NULL);
	backup = ft_file_read(fd, backup, buf);
	free(buf);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_get_backup(backup);
	return (line);
}

char	*ft_get_backup(char *backup)
{
	int		d;
	int		i;
	int		len;
	char	*new;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
		return (free(backup), NULL);
	len = ft_strlen(backup);
	new = malloc(sizeof(char) * (len - i + 1));
	if (new == NULL)
		return (free(backup), NULL);
	d = 0;
	while (backup[++i] != '\0')
		new[d++] = backup[i];
	new[d] = '\0';
	free(backup);
	return (new);
}

char	*ft_file_read(int fd, char *backup, char *buf)
{
	char	*rest;
	int		eof_cheack;

	eof_cheack = 1;
	while (eof_cheack != 0)
	{
		eof_cheack = read(fd, buf, BUFFER_SIZE);
		if (eof_cheack == -1)
			return (free(backup), NULL);
		buf[eof_cheack] = '\0';
		rest = backup;
		if (!rest)
			rest = ft_strdup("");
		backup = ft_strjoin (rest, buf);
		if (!backup)
			return (free(rest), NULL);
		free (rest);
		if (ft_strchr(backup, '\n') != NULL)
			break ;
	}
	return (backup);
}

char	*ft_get_line(char *backup)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (!backup[i])
		return (NULL);
	len = ft_strlen(backup);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (free(backup), NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
/*
 #include <fcntl.h>
 #include <stdio.h>

 int main(void)
 {
   int fd;
   char *line;

   fd = open("./test.txt", O_RDONLY);
   if (fd == -1)
   {
     perror("Error opening file");
     return 1;
   }

   line = get_next_line(fd);
   while (line != NULL)
   {
     printf("%s", line);
     free(line); // Free the memory allocated by get_next_line
     line = get_next_line(fd);
   }

   if (line == NULL)
   {
     // Print an additional newline after the last line
     printf("\n");
   }
   free(line);
   close(fd);
   return 0;
 }
 */