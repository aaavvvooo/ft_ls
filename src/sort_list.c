#include "../ft_ls.h"


void split_list(t_file *source, t_file **front, t_file **back)
{
    t_file *slow = source;
    t_file *fast = source->next;

    while (fast)
    {
        fast = fast->next;
        if(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

t_file *merge_lists(t_file *a, t_file *b, int (*compare)(t_file *, t_file *))
{
    if (!a)
        return b;
    if (!b)
        return a;

    t_file *result;
    if (compare(a, b))
    {
        result = a;
        result->next = merge_lists(a->next, b, compare);
    }
    else 
    {
        result = b;
        result->next = merge_lists(a, b->next, compare);
    }
    return result;
}

void list_sort(t_file **files, int (*compare)(t_file *, t_file *))
{
    t_file *head = *files;
    if (!head || !head->next)
        return ;
    
    t_file *a, *b;
    split_list(head, &a, &b);
    list_sort(&a, compare);
    list_sort(&b, compare);
    *files = merge_lists(a, b, compare);
}