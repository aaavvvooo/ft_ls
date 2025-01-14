#include "../ft_ls.h"

int main(int argc, char **argv)
{
    t_ls    ls;
    t_file  **files;

    init_and_parse(argc, argv, &ls);
    files = malloc(sizeof(t_file *) * ls.pathCount);
    get_files(ls, files);
    ft_free(files, &ls);
    
    return (0);
}