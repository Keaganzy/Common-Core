/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:23:03 by ksng              #+#    #+#             */
/*   Updated: 2025/05/24 21:13:15 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

static char	*ft_readzero(char **buff, char *rt)
{
	if (*buff)
	{
		rt = *buff;
		*buff = 0;
		return (rt);
	}
	else
	{
		free(*buff);
		return (NULL);
	}
}

static char	*ft_getline(char **buff)
{
	char	*rt;
	char	*findnew;
	char	*strtemp;

	findnew = ft_strchr(*buff, '\n');
	if (*buff && findnew)
	{
		rt = ft_en_strdup(*buff, 0, findnew - *buff + 1);
		strtemp = ft_en_strdup(*buff, findnew - *buff + 1, ft_strlen(*buff));
		free(*buff);
		if (*strtemp == '\0')
		{
			free(strtemp);
			*buff = 0;
		}
		else
			*buff = strtemp;
		return (rt);
	}
	return (NULL);
}

static ssize_t	ft_getbuff(char **buff, ssize_t readsize, int fd)
{
	char	*strtemp;
	char	*rt;

	rt = 0;
	if (!*buff || !ft_strchr(*buff, '\n'))
	{
		strtemp = malloc(BUFFER_SIZE + 1);
		if (!strtemp)
			return (readsize);
		readsize = read(fd, strtemp, BUFFER_SIZE);
		if (readsize < 0)
		{
			free(strtemp);
			return (0);
		}
		strtemp[readsize] = '\0';
		if (readsize != 0)
		{
			rt = ft_strjoin(*buff, strtemp);
			free(*buff);
			*buff = rt;
		}
		free(strtemp);
	}
	return (readsize);
}

char	*get_next_line(int fd)
{
	ssize_t		readsize;
	static char	*readbuff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readsize = 0;
	line = 0;
	readsize = ft_getbuff(&readbuff, readsize, fd);
	while (1)
	{
		if (readbuff && ft_strchr(readbuff, '\n'))
			return (ft_getline(&readbuff));
		if (readsize == 0)
		{
			return (ft_readzero(&readbuff, line));
		}
		else
			return (get_next_line(fd));
	}
}

/* #include <fcntl.h>
#include <sys/stat.h>
int main()
{
	setbuf(stdout, 0);
	char *line;
	int	fd = open("filename.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("line: %s", line);
		free(line);
	}
	return (0);
} */