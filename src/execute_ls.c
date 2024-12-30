#include "../ft_ls.h"

int compare_time_modified(t_file *a, t_file *b)
{
    if (a->status.st_mtime > b->status.st_mtime)
        return 1;
    return 0;

}

int compare_access_time(t_file *a, t_file *b)
{
    if (a->status.st_atime > b->status.st_atime)
        return 1;
    return 0;

}

t_file *files_order_and_appearance(t_file *files, t_ls ls)
{
    t_file *res = files;

    printf("======Before=======\n");
    print_list(res);
    if (ls.flags.t == 1)
    {
        list_sort(&res, compare_time_modified);
    }
    printf("=========After======\n");
    print_list(res);
    return res;
}

void execute_ls(t_ls ls, t_file **files)
{

    for (int i = 0; i < ls.pathCount; ++i)
    {
        files[i] = files_order_and_appearance(files[i], ls);
        // print_files();
        if (ls.flags.R)
            continue;
                // recursion()
    }
}