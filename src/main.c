#include "../ft_ls.h"

int main(int argc, char **argv)
{
    t_ls ls;

    if (argc > 3)
        return (ft_error("Too many arguments.\nUsage ./ft_ls [-alrtufdRgG] [PATH]\n"));
    init_and_parse(argc, argv, &ls);
    return (0);
}