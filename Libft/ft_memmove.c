#include "libft.h"
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	char	*aux;
	char	new[n];
	size_t	i;

	i = 0;
	aux = new;
	csrc = (char *)src;
	cdest = (char *)dest;
	while (i < n)
	{
		*(aux + i) = *((const char *)csrc + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		cdest[i] = aux[i];
		i++;
	}
	return (cdest);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}
