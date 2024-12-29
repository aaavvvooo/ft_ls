#include "../ft_ls.h"

int main(int argc, char **argv)
{
    t_ls    ls;
    t_file  **files; //massiv t_file* - ov

    init_and_parse(argc, argv, &ls);
    files = init_files(&ls);
    get_files(ls, files);
    ft_free(files, &ls);
    
    return (0);
}