#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	src = (unsigned char *)s2;
	dest = (unsigned char *)s1;
	while (i < n)
	{
		if (*(dest + i) != *(src + i))
			return (*(dest + i) - *(src + i));
		i++;
	}
	return (0);
}
