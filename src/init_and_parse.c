#include "../ft_ls.h"

void ft_init(t_ls *ls)
{
    ls->flags.a = 0;
    ls->flags.l = 0;
    ls->flags.r = 0;
    ls->flags.t = 0;
    ls->flags.u = 0;
    ls->flags.f = 0;
    ls->flags.d = 0;
    ls->flags.R = 0;
    ls->flags.G = 0;
    ls->flags.g = 0;
    ls->paths = NULL;
}

int get_path_count(char **str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[++i])
    {
        if (str[i][0] != '-')
            ++count;
    }
    return (count);
}

void init_and_parse(int argc, char **argv, t_ls *ls)
{
    int argvIndex = 0;
    int pathIndex = 0;
    ls->pathIndex = 0;
    int pathCount = get_path_count(argv);

    ft_init(ls);
    if (argc == 1)
    {
        ls->paths = malloc(sizeof(char *) * 2);
        ls->paths[0] = malloc(2);
        ls->paths[0][0] = '.';
        ls->paths[0][1] = '\0';
        ls->pathCount = 1;
    }
    else
    {
        if (pathCount == 0)
            ls->pathCount = 1;
        else
            ls->pathCount = pathCount;
        ls->paths = malloc(sizeof(char *) * (ls->pathCount + 1));
        if (pathCount == 0)
        {
            ls->paths[0] = malloc(2);
            ls->paths[0][0] = '.';
            ls->paths[0][1] = '\0';
        }
        ls->paths[ls->pathCount] = NULL;
        while (++argvIndex < argc)
        {
            if (argv[argvIndex][0] == '-')
                parse_flags(ls, argv[argvIndex]);
            else 
            {
                ls->paths[pathIndex] = malloc((sizeof(char) * ft_strlen(argv[argvIndex]) + 1));
                ft_strlcpy(ls->paths[pathIndex], argv[argvIndex], ft_strlen(argv[argvIndex]) + 1);
                ++pathIndex;
            }
        }
    }
}

void parse_flags(t_ls *ls, char *str)
{
    int i;

    i = 0;

    while (str[++i])
    {
        switch (str[i])
        {
            case 'a':
                ls->flags.a = 1;
                break;
            case 'l':
                ls->flags.l = 1;
                break;
            case 'r':
                ls->flags.r = 1;
                break;
            case 't':
                ls->flags.t = 1;
                break;
            case 'u':
                ls->flags.u = 1;
                break;
            case 'R':
                ls->flags.R = 1;
                break;
            default:
                ft_error("Wrong Option\nUsage ./ft_ls [-alrtufdRgG] [PATH]\n");
        }
    }
}