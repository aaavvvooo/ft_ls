#include "../ft_ls.h"

void append_to_files(t_file **files, char *filename)
{
    (void) files;
    ft_printf("%s\n", filename);
}

void get_files(t_ls ls, t_file **files){
    DIR             *dir;
    struct dirent   *data;

    for (int i = 0; i < ls.pathCount; ++i)
    {
        dir = opendir(ls.paths[i]);
        if (dir == NULL)
        {
            ft_printf("ft_ls: cannot access '%s': No such file or directory\n", ls.paths[i]);
            continue;
        }
        else
        {
            data = readdir(dir);
            while (data)
            {
                if (!ls.flags.a)
                {
                    if (data->d_name[0] == '.')
                    {
                        data = readdir(dir);
                        continue;
                    }
                }
                append_to_files(files, data->d_name);
                data = readdir(dir);
            }
        }
        if (!data)
            closedir(dir);
    }
}