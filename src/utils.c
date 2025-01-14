#include "../ft_ls.h"

char *mini_strdup(char *str)
{
    char * ret;

    if (!str)
        return NULL;

    if (*str == '.' && *(str + 1) != '.')
        ++str;
    ret = ft_strdup(str);
    return ret;
}
void freer(char *a, char *b)
{
    free(a);
    free(b);
}

int ft_error(char *msg)
{
    printf("%s\n", msg);
    exit (1);
}

void ft_free(t_file **files, t_ls *ls)
{
    t_file *temp1, *temp2;
    for (int i = 0; i < ls->pathCount; ++i)
    {
        temp1 = files[i];
        while(temp1)
        {
            free(temp1->filename);
            free(temp1->filename_without_dot);
            temp2 = temp1;
            temp1 = temp1->next;
            free(temp2);
        }
    }
    free(files);
    if (ls->pathCount > 1)
    {
        for (int i = 0; i < ls->pathCount; ++i)
            free(ls->paths[i]);
    }
    free(ls->paths);
}

void print_list(t_file *head) {
    if (!head)
    {
        printf("The list is empty\n");
        return ;
    }
    while (head)
    {
        printf("filename ==== %s\n", head->filename);
        head = head->next;
    }
}