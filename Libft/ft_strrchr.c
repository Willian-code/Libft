#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*p;

	p = NULL;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			p = &s[i];
		else if (s[i + 1] == '\0')
			return ((char *)p);
		i++;
	}
	return ((char *)p);
}
