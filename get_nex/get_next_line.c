#include "get_next_line.h"

/*
char *get_next_line(int fd)
{
	int i;
	static char *n;
	int x,y;

	i = 0;
	char *buf = (char *)calloc(100 , sizeof(char));
	y = read(fd, buf, BUFFER_SIZE);
	printf("%d", y);
	read(fd, buf, BUFFER_SIZE);
	read(fd, buf, BUFFER_SIZE);
	read(fd, buf, BUFFER_SIZE);
	read(fd, buf, BUFFER_SIZE);
	x = read(fd, buf, BUFFER_SIZE);
	printf("%d", x);


	////while (buf[i] != '\n')
	////    i++;
	////buf[i + 1] = '\0';

	return ((char *)buf);
}
*/
/*
int main(int argc, char *argv[])
{
	int fd;
	char *ptr;

	fd = open(argv[1], O_RDONLY);

	ptr = get_next_line(fd);

	printf("%s", ptr);

	return (0);
}
*/
/*
int main(int argc, char *argv[])
{
	int fd;
	char *s;

	fd = open(argv[1], O_RDONLY);

	s = get_next_line(fd);

	printf("%s", s);

	return (0);
}
*/
char	*trim(char **str)
{
	int		i;
	char	*trim;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		trim = ft_strdup(*str);
		free(*str);
		*str = 0;
	}
	else
	{
		trim = ft_substr(*str, 0, i + 1);
		temp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = 0;
		if (*temp)
			*str = ft_strdup(temp);
		free(temp);
	}
	return (trim);
}

char *get_next_line(int fd)
{
	static char	*str_left;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	n_bytes_rd;

    n_bytes_rd = 0;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	while (n_bytes_rd > 0)
	{
		buff[n_bytes_rd] = '\0';
		if (!str_left)
			str_left = ft_strdup("");
		temp = ft_strdup(str_left);
		free(str_left);
		str_left = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(str_left, '\n'))
			break ;
		n_bytes_rd = read(fd, buff, BUFFER_SIZE);
	}
	if (n_bytes_rd < 0 || (n_bytes_rd == 0 && !str_left))
		return (NULL);
	return (trim(&str_left));
}

/*
int main(int argc, char *argv[])
{
	int fd;
	char *s;

	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		fd = 0;

	s = get_next_line(fd);
    printf("%s", s);
    free(s);
	//while (s != NULL)
	//{
	//	s = get_next_line(fd);
	//	printf("%s", s);
	//	free(s);
	//}
	//printf("%d", fd);

	return (0);
}

*/
