#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Function checks whether the argument passed is an
 * alphanumeric character (alphabet or number) or not.
 *
 * @param c Character to be analysed
 * @return int Returns 1 - If argument is a alphanumeric character.
 * Retuns 0 - If argument is neither an alphabet nor a digit.
 */
int		ft_isalnum(int c);

/**
 * @brief Function checks whether a character is an alphabet
 * (a to z or A-Z) or not.
 *
 * @param c Character to be analysed.
 * @return int Zero(0) - if the parameter isn't an alphabet.
 * Non zero number - if the parameter is an alphabet.
 */
int		ft_isalpha(int c);

/**
 * @brief Function checkes whether the argument passed can
 * be represented as a valid 7–bit US-ASCII character.
 *
 * @param c Character bo analysed
 * @return int Zero (0) - Argument cannot be represented
 * as a valid 7–bit US-ASCII character.
 * Non-Zero integer (x > 0) - Argument can be represented as
 * a valid 7–bit US-ASCII character.
 */
int		ft_isascii(int c);

/**
 * @brief Takes a single argument in the form of an integer
 * ('0' to '9' or 45-57) an returns the value of type int.
 *
 * @param c Character to be analysed.
 * @return int Zero (0) - Argument is not a numeric character.
 * Non-Zero integer (x > 0) - Argument is a numeric character.
 */
int		ft_isdigit(int c);

/**
 * @brief Function checks whether a character is printable
 * character or not. (unprintable are the control characters
 * 0-31).
 *
 * @param c Character to be analysed.
 * @return int Zero (0) - Argument is not a printable character.
 * Non-Zero integer (x > 0) - Argument is a printable character.
 */
int		ft_isprint(int c);

/**
 * @brief Function takes uppercase alphabet and convert it to a
 * lowercase character.
 *
 * @param c Character to be analysed.
 * @return int c - if the conversion was not possible.
 * c += 32 - conversion is possible.
 */
int		ft_tolower(int c);

/**
 * @brief Function converts a lowercase alphabet to an uppercase
 * alphabet.
 *
 * @param c Character to be analysed.
 * @return int c - if the conversion was not possible.
 * c -= 32 - conversion is possible.
 */
int		ft_toupper(int c);

/**
 * @brief Function calculates the length of a given string.
 * It doesn't count null character.
 *
 * @param s Represents the string variable whose length we have
 * to find.
 * @return size_t This funcition return the length of string passed.
 */
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Is uset to fill a block of memory with a particular value.
 *
 * @param s Pointer of memory area.
 * @param c Constant bytes to fill memory area.
 * @param n Number of bytes fill.
 * @return void* Returns a pointer to the memory are s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Function copies n bytes from memory area src to memory
 * area dest. The memory areas must not overlap.
 * Use memmove if the memory areas do overlap.
 *
 * @param dest Pointer to the memory location where the contents
 * are copied to.
 * @param src Pointer to the memory location where the contents
 * are copied from.
 * @param n Number of bytes to copy from src to dest.
 * @return void* Returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Used to copy a block of memory from a location to another.
 *
 * @param dest Pointer to the memory location where the contents
 * are copied to.
 * @param src Pointer to the memory location where the contents
 * are copied from.
 * @param n Number of bytes to copy from src to dest.
 * @return void* Returns a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Sets n bytes of s to 0.
 *
 * @param s Pointer to the start of the memory location
 * @param n Buffer size
 */
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int num, char* str, int base);

#endif
