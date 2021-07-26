#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = ((char *)s);
	while (i < n)
	{
		*((unsigned char *)s) = (unsigned char)c;
		i++;
		s++;
	}
	return (p);
}
