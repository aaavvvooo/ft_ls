#ifndef FT_LS
# define FT_LS

#include <sys/types.h>
#include <stdlib.h>
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

typedef struct s_file{
    char            *filename;
    struct stat     status;
    struct s_file   *next;

}               t_file;

typedef struct s_ls
{
    t_ls_flags flags;
    char **paths;
    int pathCount;
    int pathIndex;
} t_ls;

/*Init and parse*/
t_file  **init_files(t_ls *);
void    ft_init(t_ls *);
void    parse_flags(t_ls *, char *);
void    get_files(t_ls , t_file **);
void    init_and_parse(int , char **, t_ls *);

/*Sort lists*/
void list_sort(t_file **, int (*compare)(t_file *, t_file *));

/*Utils*/
int ft_error(char *);
void ft_free(t_file **, t_ls *);
void print_list(t_file *);

void execute_ls(t_ls, t_file **);
#endif