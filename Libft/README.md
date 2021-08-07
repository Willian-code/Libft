# LIBFT

C programming can be very tedious when one doesn’t have access to those highly useful
standard functions. This project allows you to re-write those functions, understand them,
and learn to use them. This library will help you with all your future C projects.

## Getting Started

Run the command `make` to create the **libft.a** library file.

In future projects, the libft will be used by placing this libft folder in the projects folder. The libft.a library will be compiled at the same time as the project by adding the following rule to the Makefile :
```
libft:
    make -C libft/
```
As well as the following flags to the compilation of the sources of the project :
```
-I./libft/includes/ -L./libft -lft
```

## Available functions

### :mag: Character recon and transformation
- [`ft_isalpha`](ft_isalpha)
- [`ft_isdigit`](ft_isdigit)
- [`ft_isalnum`](ft_isalnum)
- [`ft_isascii`](ft_isascii)
- [`ft_isprint`](ft_isprint)
- [`ft_toupper`](ft_toupper)
- [`ft_tolower`](ft_tolower)

### :fountain_pen: String manipulations
- `ft_strlen`
- `ft_strnew`
- `ft_strdel`
- `ft_strclr`
- `ft_striter`
- `ft_striteri`
- `ft_strcmp`
- `ft_strncmp`
- `ft_strequ`
- `ft_strnequ`
- `ft_strdup`
- `ft_strcpy`
- `ft_strncpy`
- `ft_strcat`
- `ft_strncat`
- `ft_strlcat`
- `ft_strchr`
- `ft_strstr`
- `ft_strnstr`
- `ft_strsub`
- `ft_strjoin`
- `ft_strtrim`
- `ft_strsplit`

### :floppy_disk: Memory manipulation
- [`ft_memset`](ft_memset)
- [`ft_bzero`](ft_bzero)
- [`ft_memcpy`](ft_memcpy)
- [`ft_memmove`](ft_memmove)
- [`ft_memchr`](ft_memchr)
- [`ft_memcmp`](ft_memcmp)
- [`ft_calloc`](ft_calloc)

### :chains: Chained lists manipulation (BONUS)
- `ft_lstnew`()
- `ft_lstadd_front`()
- `ft_lstisize`()
- `ft_lstlast`()
- `ft_lstadd_back()
- `ft_lstdelone`()
- `ft_lst
- `ft_lstdel`
- `ft_lstadd`
- `ft_lstiter`
- `ft_lstmap`

### :money_with_wings: Conversions
- [`ft_atoi`](ft_atoi)
- [`ft_itoa`](ft_itoa)

### :scroll: Printing
- [`ft_putchar_fd`](ft_putchar_fd)
- [`ft_putstr_fd`](ft_putstr_fd)
- [`ft_putendl_fd`](ft_putendl_fd)
- [`ft_putnbr_fd`](ft_putnbr_fd)

### :rowing_woman: Stream reading (BONUS)
- `ft_fopen`
- `ft_fclose`
- `ft_fgetc`

### :tornado: Misc (BONUS)
- `ft_filelinecount`
- `ft_double_power`
- `ft_ldouble_power`
- `ft_wchar_to_bytes`
- `ft_array_swap`
- `ft_tabdel`
- `ft_nbdigits`
- `ft_nbdigits_base`

## Updating

The project is updated regularly with new functions that could be useful for other projects, or when I learn something new, or when I realize my code looks awful :wink:

## Authors

* **[anaiel](https://github.com/anaiel)**

<img align="right" src="https://i.imgur.com/FW5Sd6I.png" />
