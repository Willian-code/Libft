/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:20:42 by wrosendo          #+#    #+#             */
/*   Updated: 2022/05/11 22:12:51 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_TABLE_H
# define FT_HASH_TABLE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TABLE_SIZE 1031
# define MAX_STRING 1024

typedef struct s_hnode
{
	char			*key;
	char			*value;
	struct s_hnode	*next;
}t_hnode;

typedef struct s_hash
{
	int		size;
	t_hnode	*head;
	t_hnode	*tail;
}t_hash;

/**
 * @brief The hash table maintains a position that can be set and queried.
 *
 * @param envp environment pointer
 * @return t_hash*
 */
t_hash	*ft_create_table(char *envp[]);

/**
 * @brief Destroy a hash table
 *
 * @param array hash table, array of size TABLE_SIZE
 */
void	ft_destroy_hash(t_hash *array);

/**
 * @brief Find an item in the table
 *
 * @param list
 * @param key the key to look for
 * @return int
 */
int		ft_find_key(t_hnode *list, char *key);

/**
 * @brief Extract the key value
 *
 * @param array hash table, array of size TABLE_SIZE
 * @param key The key to look for
 * @return char* The value of the key if found or NULL if not
 */
char	*ft_find_value(char *key);

/**
 * @brief Searches for an element in a given position in the hash table
 *
 * @param list hash table, array of size TABLE_SIZE
 * @param find_index The position the element occupies in the table
 * @return t_hnode* The element found
 */
t_hnode	*ft_get_element(t_hnode *list, int find_index);

/**
 * @brief Converts a given alphanumeric key to a integer value.
 *
 * @param key Key that is hashed
 * @return int Returns a position that this key will occupy in the table
 */
int		ft_hashcode(char *key);

/**
 * @brief Set table positions to NULL
 *
 * @param array hash table, array of size TABLE_SIZE
 */
void	ft_init_array(t_hash *array);

/**
 * @brief Insert an item into the table
 *
 * @param array hash table, array of size TABLE_SIZE
 * @param key Key that is hashed
 * @param value Hash value
 */
void	ft_insert(t_hash *array, char *key, char *value);

/**
 * @brief Delete an item from the table
 *
 * @param array hash table, array of size TABLE_SIZE
 * @param key Key that is hashed
 */
void	ft_remove_element(t_hash *array, char *key);

/**
 * @brief Divide an environment variable by the '=' character
 *
 * @param array hash table, array of size TABLE_SIZE
 * @param envp environment pointer
 * @return int
 */
int		ft_split_env(t_hash *array, char *envp[]);

#endif
