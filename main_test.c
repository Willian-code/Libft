#include <stdio.h>
#include "Libft/libft.h"

int main()
{
	char	str[3] = "oi";
	char	*num;

	num = NULL;
	ft_putstr_fd("String de exemplo: oi\n", STDOUT_FILENO);
	ft_putstr_fd("Quantidade de bytes da string: ", STDOUT_FILENO);
	num = ft_itoa(ft_strlen(str));
	ft_putstr_fd(num, STDOUT_FILENO);
	free(num);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
