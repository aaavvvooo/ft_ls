#include "../ft_ls.h"

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

void    files_order_and_appearance(t_file **files, t_ls ls)
{
    t_file *res = *files;

    if (ls.flags.u && !ls.flags.r)
    {
        list_sort(&res, compare_access_time);
        *files = res;
        return ;
    }
    else if (!ls.flags.u && ls.flags.t && !ls.flags.r)
    {
        list_sort(&res, compare_time_modified);
        *files = res;
        return ;
    }
    else
    {
        if (ls.flags.a && ls.flags.r) 
            list_sort(&res, reverse_alpha_for_a);
        else if (ls.flags.a && !ls.flags.r)
            list_sort(&res, alpha_for_a);
    }
    if (ls.flags.r && (ls.flags.u || ls.flags.t))
        reverse_list(&res);
    else if (ls.flags.r & !ls.flags.a)
        list_sort(&res, reverse_alpha);
    else if (!ls.flags.a)
        list_sort(&res, alpha);
    *files = res;
}

//PRINT FILES SECTION =====> to another file

int get_file_type(t_file *list)
{
    if (S_ISREG(list->status.st_mode))
        return 0;
    else if (S_ISDIR(list->status.st_mode))
        return 1;
    else if (S_ISLNK(list->status.st_mode))
        return 2;
    else if (S_ISCHR(list->status.st_mode))
        return 3;
    else if (S_ISBLK(list->status.st_mode))
        return 4;
    else if (S_ISSOCK(list->status.st_mode))
        return 5;
    else if (S_ISFIFO(list->status.st_mode))
        return 6;
    return -1;
}

void permission_printer(t_file *file)
{
    ft_printf((file->status.st_mode & S_IRUSR) ? "r" : "-");
    ft_printf((file->status.st_mode & S_IWUSR) ? "w" : "-");
    ft_printf((file->status.st_mode & S_IXUSR) ? "x" : "-");
    ft_printf((file->status.st_mode & S_IRGRP) ? "r" : "-");
    ft_printf((file->status.st_mode & S_IWGRP) ? "w" : "-");
    ft_printf((file->status.st_mode & S_IXGRP) ? "x" : "-");
    ft_printf((file->status.st_mode & S_IROTH) ? "r" : "-");
    ft_printf((file->status.st_mode & S_IWOTH) ? "w" : "-");
    ft_printf((file->status.st_mode & S_IXOTH) ? "x" : "-");
}

void print_permissions(t_file *list)
{
    char fileTypes[7] = "-dlcbsp";

    int fileType = get_file_type(list);
    if (fileType == -1)
        ft_error("Unknown file type detected\n");
    ft_printf("%c", fileTypes[fileType]);
    permission_printer(list);
}

int get_total_count(t_file *list)
{
    t_file *temp = list;
    int totalMemory = 0;

    while(temp)
    {
        totalMemory += temp->status.st_blocks;
        temp = temp->next;
    }
    return totalMemory / 2;
}

int getMaxLength(t_file *list, char *type)
{
    int res = 0;
    t_file *temp = list;
    int tempLength = 0;

    while(temp)
    {
        if (!ft_strncmp(type, "link", ft_strlen(type)))
        {
            char *itoa_str = ft_itoa(temp->status.st_nlink);
            tempLength = ft_strlen(itoa_str);
            free(itoa_str);
        }
        else if (!ft_strncmp(type, "author", ft_strlen(type)))
        {
            struct passwd *user;
            user = getpwuid(temp->status.st_uid);
            tempLength = ft_strlen(user->pw_name);
        }
        else if (!ft_strncmp(type, "group", ft_strlen(type)))
        {
            struct group *group;
            group = getgrgid(temp->status.st_gid);
            tempLength = ft_strlen(group->gr_name);
        }
        else if (!ft_strncmp(type, "size", ft_strlen(type)))
        {
            char *itoa_str = ft_itoa((int)temp->status.st_size);
            tempLength = ft_strlen(itoa_str);
            free(itoa_str);
        }
        if (tempLength > res)
            res = tempLength;
        temp = temp->next;
    }
    return res;
}

void print_links(t_file *list, int maxLength)
{
    int         tempLength;
    t_file      *temp = list;

    char    *itoa_str = ft_itoa(temp->status.st_nlink);
    tempLength = ft_strlen(itoa_str);
    for (int i = 0; i < maxLength - tempLength; ++i)
        ft_printf(" ");
    ft_printf("%d ", (int)temp->status.st_nlink);
    free(itoa_str);
}

void print_author(t_file *list, int maxLength)
{
    struct passwd *user;
    t_file *temp = list;
    int tempLength;

    user = getpwuid(temp->status.st_uid);
    tempLength = ft_strlen(user->pw_name);
    ft_printf("%s", user->pw_name);
    for (int i = 0; i < maxLength - tempLength; ++i)
        ft_printf(" ");
}

void print_group(t_file *list, int maxLength)
{
    struct passwd *group;
    t_file *temp = list;
    int tempLength;

    group = getpwuid(temp->status.st_uid);
    tempLength = ft_strlen(group->pw_name);
    ft_printf("%s", group->pw_name);
    for (int i = 0; i < maxLength - tempLength; ++i)
        ft_printf(" ");
}

void print_size(t_file *list, int maxLength)
{
    int         tempLength;
    t_file      *temp = list;

    char *itoa_str = ft_itoa((int)temp->status.st_size);
    tempLength = ft_strlen(itoa_str);
    for (int i = 0; i < maxLength - tempLength; ++i)
        ft_printf(" ");
    ft_printf("%d ", (int)temp->status.st_size);
    free(itoa_str);
}

int get_year_from_time_t(time_t timestamp)
{
    const int SECONDS_IN_A_DAY = 86400;
    const int EPOCH_YEAR = 1970;
    int year = EPOCH_YEAR;
    time_t seconds = timestamp;

    while (seconds >= 0)
    {
        int days_in_year = 365;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            days_in_year = 366;
        time_t seconds_in_year = days_in_year * SECONDS_IN_A_DAY;
        if (seconds < seconds_in_year)
            break;
        seconds -= seconds_in_year;
        year++;
    }
    return year;
}

void print_date(t_file *list)
{
    time_t time_n = time(NULL);
    unsigned long seconds_in_year = 365 * 24 * 60 * 60;
    unsigned long timediff = time_n - list->status.st_mtime;
    int file_year = get_year_from_time_t((list->status.st_mtime));
    char *time_str = ctime(&list->status.st_mtime);
    char *sub_str1 = ft_substr(time_str, 4, 6);
    char *sub_str2 = ft_substr(time_str, 10, 6);

    ft_printf("%s", sub_str1);
    if (timediff > seconds_in_year)
        ft_printf("  %d", file_year);
    else
        ft_printf("%s", sub_str2);
    free(sub_str1);
    free(sub_str2);
}

void print_link_filename(t_file *list)
{
    char buf[1024];

    readlink(list->filename, buf, sizeof(buf) - 1);
    ft_printf (" %s -> ", list->filename);
    buf[1023] = '\0';
    ft_printf("%s\n", buf);
}

void print_files(t_file *list, t_ls ls)
{
    t_file *temp = list;
    int maxLengthLinks;
    int maxLengthAuthor;
    int maxLengthGroup;
    int maxLengthSize;

    if (ls.pathCount > 1 || ls.flags.R)
        ft_printf("%s:\n", ls.paths[ls.pathIndex]);
    if (ls.flags.l)
    {
        ft_printf("total %d\n", get_total_count(list));
        maxLengthLinks = getMaxLength(list, "link") + 1;
        maxLengthAuthor = getMaxLength(list, "author") + 1;
        maxLengthGroup = getMaxLength(list, "group") + 1;
        maxLengthSize = getMaxLength(list, "size");
        while(temp)
        {
            print_permissions(temp);
            print_links(temp, maxLengthLinks);
            print_author(temp, maxLengthAuthor);
            print_group(temp, maxLengthGroup);
            print_size(temp, maxLengthSize);
            print_date(temp);
            if (ls.flags.l && S_ISLNK(temp->status.st_mode))
                print_link_filename(temp);
            else
                ft_printf(" %s\n", temp->filename);  
            temp = temp->next;
        }
    }
    else
    {
        while (temp)
        {
            if(temp->next)
                ft_printf("%s   ", temp->filename);
            else
                ft_printf("%s\n", temp->filename);
            temp = temp->next;
        }
    }
    if (ls.flags.R || ls.pathCount > 1)
        ft_printf("\n");
}