#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFERSIZE
#define BUFFERSIZE 10
#endif

char *get_entire_file(int fd)
{
    static char buf[999999];
    int j = 1;
    int k = 0;

    // Read until EOF
    while (j > 0)
    {
        j = read(fd, buf + k, BUFFERSIZE);
        if (j == -1)
            return NULL;
        k += j;
    }

    // k now holds total file size
    char *ret = malloc(k + 1);
    if (!ret)
        return NULL;

    for (int i = 0; i < k; i++)
        ret[i] = buf[i];
    ret[k] = '\0';

    return ret;
}