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
    free(files);
    if (ls->pathCount > 1)
    {
        for (int i = 0; i < ls->pathCount; ++i)
            free(ls->paths[i]);
    }
    free(ls->paths);
}

void print_list(t_file *head) {
    while (head) {
        printf("%s\n", head->filename);
        head = head->next;
    }
}