#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((char)str[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
