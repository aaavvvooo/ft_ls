#include "../ft_ls.h"

int main(int argc, char **argv)
{
    t_ls    ls;
    t_file  **files; //massiv t_file* - ov

    init_and_parse(argc, argv, &ls);
    files = malloc(sizeof(t_file *) * ls.pathCount);
    get_files(ls, files);
    execute_ls(ls, files);
    // for (int i = 0; i < ls.pathCount; ++i)
    //     print_list(files[i]);
    ft_free(files, &ls);
    
    return (0);
}