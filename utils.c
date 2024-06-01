#include "ft_ls.h"

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        ++i;
    return i;
}


int ft_error(char *msg)
{
    write(2, msg, ft_strlen(msg));
    _exit(1);
}