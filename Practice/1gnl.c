#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#ifndef BUFFERSIZE
#define BUFFERSIZE 10
#endif

char *buf = NULL;

char *get_next_line(int fd)
{
    //static char buf[999999] = {'\0'};
    if (buf == NULL)
        buf = malloc(1000000000);
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
    while (buf[i+j])
        j++;
    ret = malloc (j + 1);
    ret[j] = 0;
    k = 0;

    while (k <= j)
    {
        ret[k++] = buf[i++];
    }
    return ret;
}

// int filter()
// {
//     free(buf);
// }