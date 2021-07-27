#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0')
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			if ((i + j) == len - 1)
				return (NULL);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
//#include <bsd/string.h>

int main()
{
    const char *largestring = "aaabcabcd";
    const char *smallstring = "cd";
    //char *ptr;
	char *ptr2;

    //ptr = strnstr(largestring, smallstring, 8);
	ptr2 = ft_strnstr(largestring, smallstring, 8);

	//printf("%s\n", ptr);
	printf("%s\n", ptr2);

    return (0);
}
*/
