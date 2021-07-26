#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	c;

	if (dstsize == ft_strlen(dst) + 1)
		return (ft_strlen(src) + ft_strlen(dst));
	if (dstsize < ft_strlen(dst) + 2)
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	i = 0;
	while (*(src + i) != '\0' && c + 1 < dstsize)
	{
		*(dst + c) = *(src + i);
		i++;
		c++;
	}
	*(dst + c) = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
/*
#include <stdio.h>
#include <bsd/string.h>

int main()
{
    char *str_base;
    char dest[100];
    char dest2[100];
    char *src;
    int  i;

    str_base = "rrrrrrrrrrrrrr";
    src = "lorem ipsum dolor sit amet";
    i = 0;
    while (i < 15)
    {
        dest[i] = str_base[i];
        dest2[i] = str_base[i];
        i++;
    }

    printf("c : (%ld) %s\n", strlcat(dest, src, 15), dest);
    printf("ft : (%ld) %s\n", ft_strlcat(dest2, src, 15), dest2);

    return(0);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main()
{
    char dest[15];

    memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[14] = 'a';
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	write(1, "\n", 1);
	write(1, dest, 15);
}
*/
