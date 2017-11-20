#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <stdio.h> //DEBUG

# define BUFF_SIZE 42
# define MALLCHECK(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);

#endif