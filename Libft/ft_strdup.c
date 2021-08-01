#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (str == 0)
		return (NULL);
	return (ft_memmove(str, s, ft_strlen(s) + 1));
}
