#ifndef GNL_H
# define GNL_H

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


#ifndef BUFFERSIZE
# define BUFFERSIZE 10
#endif

char *get_next_line(int fd);

#endif