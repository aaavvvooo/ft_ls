#include "ft_ls.h"

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
    ls->path = NULL;
}

void	init_and_parse(int argc, char **argv, t_ls *ls)
{

    ft_init(ls);
    if (argc == 1)
        ls->path = ".";
    else if (argc == 2)
    {
        if (argv[1][0] == '-')
        {
            ls->path = ".";
            parse_flags(ls, argv[1]);
        }
        else
            ls->path = argv[1];
    }
    else
    {
        parse_flags(ls, argv[1]);
        ls->path = argv[2];
    }
}

void parse_flags(t_ls *ls, char *str)
{
    int i;

    if (str[0] == '-')
        i = 0;
    i = -1;
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
            case 'f':
                ls->flags.f = 1;
                break;
            case 'd':
                ls->flags.d = 1;
                break;
            case 'R':
                ls->flags.R = 1;
                break;
            case 'g':
                ls->flags.g = 1;
                break;
            case 'G':
                ls->flags.G = 1;
                break; 
            default:
                ft_error("Wrong Option\nUsage ./ft_ls [-alrtufdRgG] [PATH]\n");
                break;
        }
    }  
}