


#include "gnl.h"

void	*join_free(char **s1, char *s2, int len2)
{
	if (!*s1)
	{
		*s1 = malloc(1);
		*s1[0] = 0;
	}
	int len1 =strlen(*s1);
	char *tmp = malloc(len1 + len2 + 1);
	memcpy(tmp, *s1, len1);
	memcpy(tmp + len1, s2, len2);
	tmp[len1 + len2] = 0;
	free (*s1);
	*s1 = tmp;
	return (tmp);
}

char *get_next_line(int fd)
{
    static char buf[BUFFERSIZE + 1];
    char *ret;
    char *temp;
    int bytes;

    ret = NULL;

    while(1)
    {
        temp = strchr(buf, '\n');
        if (temp)
        {
            join_free(&ret, buf, temp - buf + 1);
            memmove(buf, temp + 1, strlen(temp + 1) + 1);
            return (ret);
        }
        else
        {
            join_free(&ret, buf, strlen(buf));
            bytes = read(fd, buf, BUFFERSIZE);
            if (bytes <=0)
            {
                buf[0] = 0;
                if (bytes < 0 || ret[0] == 0)
                {
                    free(ret);
                    return NULL;
                }
                return (ret);
            }
            buf[bytes] = 0;
        }
    }
}