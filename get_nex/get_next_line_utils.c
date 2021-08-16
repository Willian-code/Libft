#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (str == 0)
		return (NULL);
	return (ft_memmove(str, s, ft_strlen(s) + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	src_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (src_len > start)
		while (s[i + start] && i < len)
			i++;
	else
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, i + 1);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	c;

	if (dstsize == ft_strlen(dst) + 1)
		return (ft_strlen(src) + ft_strlen(dst));
	if (dstsize < ft_strlen(dst) + 2)
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	i = 0;
	while (*(src + i) != '\0' && c + 1 < dstsize)
	{
		*(dst + c) = *(src + i);
		i++;
		c++;
	}
	*(dst + c) = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = ((char *)s);
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (!dest && !src)
		return (0);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (num--)
		*cdest++ = *csrc++;
	return (dest);
}
