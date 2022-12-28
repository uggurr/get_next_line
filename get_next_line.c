#include "get_next_line.h"

char *scan(int fd, char *s)
{
    int i;
    char *a;
    int lw;

    i = 0;
    a = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!a)
        return (NULL);
    lw = 1;
    while (lw != 0 && !ft_strchr(s, '\n'))
    {
        lw = read(fd, a, BUFFER_SIZE);
        if (lw == -1)
        {
            free(a);
            return (NULL);
        }
        a[lw] = '\0';
        s = add(s, a);
        if (!s)
            return (NULL);
    }
    free(a);
    return (s);
}

char *get_next_line(int fd)
{
    static char *stc;
    char        *str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stc = scan(fd, stc);
    if (!stc)
        return (NULL);
    str = line(stc);
    stc = next(stc);
    return (str);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd;
    fd = open("deneme.txt",O_RDONLY,0777);
    char *s = get_next_line(fd);
    printf("%s", s);
}