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

/**
 * @brief Append the NULL-terminated string src to the end fo dst.
 * It will append at most size - ft_strlen(dst) - 1 byte, NULL-terminating
 * the result.
 *
 * @param dst Pointer to the destination area of memory
 * @param src Pointer to the source area of memory
 * @param dstsize Buffer size in bytes
 * @return size_t Return the total length of the string, that is the
 * initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Copies up to size - 1 character from the NULL-terminenated
 * string src to dst, NULL terminating the result.
 *
 * @param dst Pointer to the destination area of memory
 * @param src Pointer to the source area of memory
 * @param dstsize Buffer size in bytes
 * @return size_t Return the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Function only compare the first (at most) n bytes of
 * strings s1 and s2.
 *
 * @param s1 Pointer to the area of memory of the first string.
 * @param s2 Pointer to the area of memory of the second string
 * @param n Buffer size in bytes to compare both strings.
 * @return int Return value < 0: then it indicates s1 is less than s2.
 * Return value > 0: then it indicates s2 is less than s1.
 * Return value == 0: then it indicates s1 is equal to s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Converts the initial portion of the string pointed
 * to by nptr to int. The behavior is the same as
 * strdol(nptr, NULL, 10).
 *
 * @param nptr Pointer to the area of memory of the string
 * to be converted
 * @return int The converted value or 0 on error
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Returns a pointer to the first occurence of the 'c'
 * in the string s.
 *
 * @param s Pointer to the string memory area.
 * @param c Character to be searched inside the string s.
 * @return char* Resturn a pointer to the matched character or
 * NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurrence of the 'c'
 * in the string s.
 *
 * @param s Pointer to the string memory area.
 * @param c Character to be searched inside the string s.
 * @return char* Resturn a pointer to the matched character or
 * NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Locates the first occurrence of the null-terminated string
 * little in the string big, where not more than len character
 * are searched. Characters that appear after a '\0' character are
 * not searched.
 * @param big String to be searched by 'little'
 * @param little String to search in 'big'
 * @param len Number of bytes to search
 * @return char* If little is an empty string, big is returned; if
 * little occurs nowhere in big, NULL is the returned; otherwise a
 * pointer to the first character of the first occurrence of little
 * is returned.
 */
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

/**
 * @brief Scans the initial n bytes of the memory area to by s for
 * the first instance of c.
 *
 * @param s Pointer to the object to be search for.
 * @param c Character to search for.
 * @param n Buffer size.
 * @return void* Return a pointer to the matching byte or NULL if
 * it does not occur
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes (each interpreted as unsigned char)
 * of teh memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area to be compared
 * @param s2 Pointer to the second memory area to be compared
 * @param n This is the number fo bytes to be compared. (Buffer)
 * @return int Return value < 0: then it indicates s1 is less than s2.
 * Return value > 0: then it indicates s2 is less than s1.
 * Return value == 0: then it indicates s1 is equal to s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief function shall allocate unused space for an array of 'nmemb'
 * elements each of whose size in bytes is 'size'. The space shall
 * be initialized to all bits 0.
 *
 * @param nmemb Number of elements.
 * @param size Number of bytes by type.
 * @return void* Return a pointer to the allocated memory, which
 * is suitably aligned for any built-in type. On error, this
 * functions return NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Shall return a pointer to a new string, which is a
 * a duplicate fo the string pointed to by s.
 *
 * @param s Pointer to the start fo the string do be copied.
 * @return char* On success, returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available.
 */
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
