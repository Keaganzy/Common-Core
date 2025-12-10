#include "gnl.h"

char *get_next_line(int fd)
{
    static char buf[999999] = {'\0'};
    static int i = 0;
    int j;
    int k;
    char *ret;

    j = 1;
    k = 0;

    while (j > 0)
    {
        j = read(fd, buf + k, BUFFERSIZE);
        if (j == -1 || !*(buf + i))
            return NULL;
        k += j;
    }
    j = 0;
    while (buf[i + j] && buf[i + j] != '\n')
        j++;
    ret = malloc(j + 1 + (buf[i+j] == '\n'));
    ret[j + (buf[i+j] == '\n')] = '\0';
    k = 0;

    while (k <= j)
    {
        ret[k++] = buf[i++];
    }
    return ret;
}