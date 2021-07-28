#include "libft.h"

/*
** ft_strtrim - remove leading and trailing charset(char const *set)
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	len = ft_strlen(s1);
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}
