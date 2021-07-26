#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)source;
	cdest = (char *)destination;
	i = 0;
	while (i < num)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
