#include "../libft.h"

char	*ft_tolower_string(char *str)
{
    if (!str)
        return 0;
    for (int i = 0; i < ft_strlen(str); ++i)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    return str;
}
