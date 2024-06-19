#ifndef FT_LS
# define FT_LS

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include "libs/libft/libft.h"
#include "libs/ft_printf/ft_printf.h"

typedef struct s_ls_flags
{
    int l;
    int a;
    int r;
    int t;
    int R;
    int u;
    int f;
    int g;
    int d;
    int G;
} t_ls_flags;

typedef struct s_ls
{
    t_ls_flags flags;
    char *path;
} t_ls;

/*Init and parse*/
void ft_init(t_ls *ls);
void init_and_parse(int argc, char **argv, t_ls *ls);
void parse_flags(t_ls *ls, char *str);

/*Utils*/
int ft_error(char *msg);

#endif