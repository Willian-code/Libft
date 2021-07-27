#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}
