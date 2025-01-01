#include "../ft_ls.h"
// TODO: -l
// TODO: -R:((
// TODO: printf with flags:))

int compare_time_modified_nsec(t_file *a, t_file *b)
{
    if (a->status.st_mtim.tv_nsec > b->status.st_mtim.tv_nsec)
        return 1;
    return 0;
}

int compare_access_time_nsec(t_file *a, t_file *b)
{
    if (a->status.st_atim.tv_nsec > b->status.st_atim.tv_nsec)
        return 1;
    return 0;
}

int compare_time_modified(t_file *a, t_file *b)
{
    if (a->status.st_mtime > b->status.st_mtime)
        return 1;
    else if (a->status.st_mtime == b->status.st_mtime)
        return compare_time_modified_nsec(a, b);
    return 0;
}

int compare_access_time(t_file *a, t_file *b)
{
    if (a->status.st_atime > b->status.st_atime)
        return 1;
    else if (a->status.st_atime == b->status.st_atime)
        return compare_access_time_nsec(a, b);
    return 0;
}

int alpha(t_file *a, t_file *b)
{
    char *a_str = ft_strdup(a->filename);
    char *b_str = ft_strdup(b->filename);
    if (ft_strncmp(ft_tolower_string(a_str), ft_tolower_string(b_str), ft_strlen(a_str)) < 0)
    {
        freer(a_str, b_str);
        return 1;
    }
    freer(a_str, b_str);
    return 0;
}

int reverse_alpha(t_file *a, t_file *b)
{
    char *a_str = ft_strdup(a->filename);
    char *b_str = ft_strdup(b->filename);
    if (ft_strncmp(ft_tolower_string(a_str), ft_tolower_string(b_str), ft_strlen(a_str)) > 0)
    {
        freer(a_str, b_str);
        return 1;
    }
    freer(a_str, b_str);
    return 0;
}

int alpha_for_a(t_file *a, t_file *b)
{
    char *a_str = ft_strdup(a->filename_without_dot);
    char *b_str = ft_strdup(b->filename_without_dot);
    if (ft_strncmp(ft_tolower_string(a_str), ft_tolower_string(b_str), ft_strlen(a_str)) < 0)
    {
        freer(a_str, b_str);
        return 1;
    }
    freer(a_str, b_str);
    return 0;
}

int reverse_alpha_for_a(t_file *a, t_file *b)
{
    char *a_str = ft_strdup(a->filename_without_dot);
    char *b_str = ft_strdup(b->filename_without_dot);
    if (ft_strncmp(ft_tolower_string(a_str), ft_tolower_string(b_str), ft_strlen(a_str)) > 0)
    {
        freer(a_str, b_str);
        return 1;
    }
    freer(a_str, b_str);
    return 0;
}


t_file *create_reversed_array(t_file *list, int length)
{
    t_file *res = malloc(length * sizeof(t_file));

    for (int i = length - 1; i >= 0; --i)
    {
        res[i].filename = list->filename;
        res[i].filename_without_dot = list->filename_without_dot;
        res[i].status = list->status;
        if (list->next)
            list = list->next;
    }
    return res;

}

void reverse_list(t_file **list)
{
    t_file *head = *list;
    t_file *temp = *list;

    if (!head)
        return ;

    int length = 0;
    while (temp)
    {
        ++length;
        temp = temp->next;
    }
    t_file *temp_array = create_reversed_array(head, length);
    length = 0;
    temp = head;
    while (temp)
    {
        temp->filename = temp_array[length].filename;
        temp->filename_without_dot = temp_array[length].filename_without_dot;
        temp->status = temp_array[length].status;
        ++length;
        temp = temp->next;
    }
    free(temp_array);
}


t_file *files_order_and_appearance(t_file *files, t_ls ls)
{
    t_file *res = files;

    if (ls.flags.u)
        list_sort(&res, compare_access_time);
    else if (!ls.flags.u && ls.flags.t)
        list_sort(&res, compare_time_modified);
    else
    {
        if (ls.flags.a && ls.flags.r) 
            list_sort(&res, reverse_alpha_for_a);
        else if (ls.flags.a && ls.flags.r)
            list_sort(&res, alpha_for_a);
    }
    if (ls.flags.r && (ls.flags.u || ls.flags.t))
        reverse_list(&res);
    else if (ls.flags.r)
        list_sort(&res, reverse_alpha);
    else
        list_sort(&res, alpha);
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