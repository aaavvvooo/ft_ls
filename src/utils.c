#include "../ft_ls.h"

int ft_error(char *msg)
{
    ft_printf("%s\n", msg);
    exit (1);
}

void ft_free(t_file **files, t_ls *ls)
{
    free(files);
    for (int i = 0; i < ls->pathCount; ++i)
        free(ls->paths[i]);
    free(ls->paths);
}