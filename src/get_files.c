#include "../ft_ls.h"

void append_to_files(t_ls *ls, t_file **files, char *filename, int index)
{   
    int i = 0;
    t_file *temp = files[ls->pathIndex];

    if (index == 0)
    {
        t_file *new = malloc(sizeof(t_file));
        new->filename = ft_strdup(filename);
        new->next = NULL;
        stat(filename, &new->status);
        files[ls->pathIndex] = new;
    }
    else
    {
        temp = files[ls->pathIndex];
        while (++i < index)
            temp = temp->next;
        temp->next = malloc(sizeof(t_file));
        temp->next->filename = ft_strdup(filename);
        temp->next->next = NULL;
        stat(filename, &temp->next->status);
    }
}

void get_files(t_ls ls, t_file **files){
    DIR             *dir;
    struct dirent   *data;
    int             index = 0;

    for (int i = 0; i < ls.pathCount; ++i)
    {
        dir = opendir(ls.paths[i]);
        if (dir == NULL)
        {
            printf("ft_ls: cannot access '%s': No such file or directory\n", ls.paths[i]);
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
                append_to_files(&ls, files, data->d_name, index);
                ++index;
                data = readdir(dir);
            }
        }
        if (!data)
            closedir(dir);
    }
}