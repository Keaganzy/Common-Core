/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:35:41 by ksng              #+#    #+#             */
/*   Updated: 2025/05/24 21:08:58 by ksng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*readbuff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readsize = -1;
	line = 0;
	readsize = ft_getbuff(&readbuff[fd], readsize, fd);
	while (1)
	{
		if (readbuff[fd] && ft_strchr(readbuff[fd], '\n'))
			return (ft_getline(&readbuff[fd]));
		if (readsize == 0)
		{
			return (ft_readzero(&readbuff[fd], line));
		}
		else
			return (get_next_line(fd));
	}
}

/* #include <fcntl.h>
#include <sys/stat.h>
# include <stdio.h>

int main()
{
    // Disable stdout buffering for immediate output, useful for debugging
    setbuf(stdout, NULL);

    // Open file descriptors
    int fd1 = open("filename.txt", O_RDONLY);
    int fd2 = open("filename2.txt", O_RDONLY);
    int fd3 = open("filename3.txt", O_RDONLY);
    int fd4 = open("filename4.txt", O_RDONLY);

    // Basic error checking for file opening
    if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0) {
        perror("Error opening one or more files");
        return 1; // Indicate an error
    }

    char *line1 = "initial"; // Initialize to non-NULL to enter loop
    char *line2 = "initial";
    char *line3 = "initial";
    char *line4 = "initial";

    int active_files = 4; // Keep track of how many files still have lines

    printf("--- Interleaved Reading ---\n");

    // Loop as long as at least one file is still returning lines
    while (active_files > 0)
    {
        active_files = 0; // Reset count for this iteration

        // Try to read from fd1
        if (line1 != NULL) { // Only try if previous read wasn't EOF
            line1 = get_next_line(fd1);
            if (line1 != NULL) {
                printf("FD1: %s", line1);
                free(line1);
                active_files++;
            }
        }

        // Try to read from fd2
        if (line2 != NULL) {
            line2 = get_next_line(fd2);
            if (line2 != NULL) {
                printf("FD2: %s", line2);
                free(line2);
                active_files++;
            }
        }

        // Try to read from fd3
        if (line3 != NULL) {
            line3 = get_next_line(fd3);
            if (line3 != NULL) {
                printf("FD3: %s", line3);
                free(line3);
                active_files++;
            }
        }

        // Try to read from fd4
        if (line4 != NULL) {
            line4 = get_next_line(fd4);
            if (line4 != NULL) {
                printf("FD4: %s", line4);
                free(line4);
                active_files++;
            }
        }
    }
    printf("--- All files finished ---\n");

    // Close all opened file descriptors
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0; // Indicate successful execution
} */