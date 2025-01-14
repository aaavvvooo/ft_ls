#include "../ft_ls.h"

void append_to_files(t_ls *ls, t_file **files, char *filename, int index)
{   
    int     i = 0;
    t_file  *temp = files[ls->pathIndex];
    char    *temp_str1;
    char    *temp_str2;

    if (index == 0)
    {
        t_file *new = malloc(sizeof(t_file));
        new->filename = ft_strdup(filename);
        if (filename[0] == '.' && ft_strncmp(filename, ".", 2) && ft_strncmp(filename, "..", 3))
            new->filename_without_dot = mini_strdup(filename);
        else
            new->filename_without_dot = ft_strdup(filename);
        new->next = NULL;
        temp_str1 = ft_strjoin(ls->paths[ls->pathIndex], "/");
        temp_str2 = ft_strjoin(temp_str1, filename);
        lstat(temp_str2, &new->status);
        files[ls->pathIndex] = new;
        free(temp_str1);
        free(temp_str2);
    }
    else
    {
        temp = files[ls->pathIndex];
        while (++i < index)
            temp = temp->next;
        temp->next = malloc(sizeof(t_file));
        temp->next->filename = ft_strdup(filename);
        if (filename[0] == '.' && ft_strncmp(filename, ".", 2) && ft_strncmp(filename, "..", 3))
            temp->next->filename_without_dot = mini_strdup(filename);
        else
            temp->next->filename_without_dot = ft_strdup(filename);
        temp->next->next = NULL;
        temp_str1 = ft_strjoin(ls->paths[ls->pathIndex], "/");
        temp_str2 = ft_strjoin(temp_str1, filename);
        lstat(temp_str2, &temp->next->status);
        free(temp_str1);
        free(temp_str2);
    }
}

void get_files(t_ls ls, t_file **files){
    DIR             *dir;
    struct dirent   *data;
    int             index;

    for (int i = 0; i < ls.pathCount; ++i)
    {
        index = 0;
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
                data = readdir(dir);
                ++index;
            }
            files_order_and_appearance(&files[i], ls);
            print_files(files[i], ls);
            t_file *temp = files[i];
            for(int i = 0; i < index; ++i)
            {
                if (ls.flags.R && S_ISDIR(temp->status.st_mode) && ft_strncmp(".", temp->filename, 2) && ft_strncmp("..", temp->filename, 3))
                {
                    char *temp_join = ft_strjoin(ls.paths[ls.pathIndex], "/");
                    t_file **rec_files = malloc(sizeof(t_file *) * 1);
                    *rec_files = NULL;
                    t_ls rec_ls;
                    rec_ls.flags = ls.flags;
                    rec_ls.pathCount = 1;
                    rec_ls.pathIndex = 0;
                    rec_ls.paths = malloc(sizeof(char *) * 2);
                    rec_ls.paths[0] = temp_join;
                    rec_ls.paths[0] = ft_strjoin(temp_join, temp->filename);
                    rec_ls.paths[1] = NULL;
                    get_files(rec_ls, rec_files);
                    free(temp_join);
                    free(rec_ls.paths[0]);
                    ft_free(rec_files, &rec_ls);
                }
                temp = temp->next;
            }
        }
        if (!data)
        {
            closedir(dir);
            ++ls.pathIndex;
        }
    }
}