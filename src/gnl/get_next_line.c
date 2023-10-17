/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 16:10:09 by nmolinel      #+#    #+#                 */
/*   Updated: 2023/03/23 16:10:10 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_libc.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*add_to_buff(char **buff, int fd, char *str)
{
	char	*tmp;
	size_t	src_len;
	size_t	tot_len;

	src_len = ft_strlen(str) + 1;
	if (!buff[fd])
	{
		buff[fd] = (char *) malloc(sizeof(char) * src_len);
		if (!buff[fd])
			return (0);
		ft_strlcpy(buff[fd], str, src_len);
		return (buff[fd]);
	}
	tmp = ft_strdup(buff[fd]);
	if (!tmp)
		return (ft_free(buff, fd, tmp));
	free(buff[fd]);
	tot_len = src_len + ft_strlen(tmp);
	buff[fd] = (char *) malloc(sizeof(char) * tot_len);
	if (!buff[fd])
		return (ft_free(0, 0, tmp));
	ft_strlcpy(buff[fd], tmp, tot_len);
	ft_strlcpy(buff[fd] + ft_strlen(tmp), str, tot_len);
	free(tmp);
	return (buff[fd]);
}

int	ft_strchr_len(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (s[i] && s[i] != chr)
		i++;
	if (s[i] != chr)
		return (0);
	return (i + 1);
}

char	*search_line(char **buff, int fd, int nlc)
{
	int		i;
	char	*line;

	if (!buff[fd])
		return ("");
	i = ft_strchr_len(buff[fd], nlc);
	if (!i)
		return ("");
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (ft_free(buff, fd, 0));
	ft_strlcpy(line, buff[fd], i + 1);
	ft_strlcpy(buff[fd], buff[fd] + i, ft_strlen(buff[fd]) + 1);
	if (!nlc || !ft_strlen(buff[fd]))
	{
		free(buff[fd]);
		buff[fd] = 0;
	}
	return (line);
}

char	*read_file(int fd, char **buff, char **next_line)
{
	char	stream[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = read(fd, stream, BUFFER_SIZE);
	while (bytes_read >= 0)
	{
		if (!bytes_read)
		{
			*next_line = search_line(buff, fd, '\0');
			if (*next_line && ft_strlen(*next_line))
				return (*next_line);
			return (0);
		}
		stream[bytes_read] = 0;
		if (!add_to_buff(buff, fd, stream))
			return (0);
		*next_line = search_line(buff, fd, '\n');
		if (!*next_line)
			return (0);
		if (ft_strlen(*next_line))
			return (*next_line);
		bytes_read = read(fd, stream, BUFFER_SIZE);
	}
	return (ft_free(buff, fd, 0));
}

char	*get_next_line(int fd)
{
	static char	*buff[FOPEN_MAX];
	char		*next_line;

	if (!buff[fd])
		return (read_file(fd, buff, &next_line));
	next_line = search_line(buff, fd, '\n');
	if (!next_line)
		return (0);
	if (ft_strlen(next_line))
		return (next_line);
	return (read_file(fd, buff, &next_line));
}
