/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:51:29 by moaljazz          #+#    #+#             */
/*   Updated: 2025/03/24 16:51:30 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static size_t	word_count(const char *str, char delimiter)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != delimiter)
			i++;
	}
	return (count);
}

static char	*extract_word(const char *str, char delimiter, size_t *index)
{
	char	*word;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[*index + len] && str[*index + len] != delimiter)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[*index + i];
		i++;
	}
	word[i] = '\0';
	*index += len;
	return (word);
}

static void	free_split(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**free_result(char **result, size_t count)
{
	free_split(result, count);
	return (NULL);
}

char	**ft_split(const char *str, char delimiter)
{
	char	**result;
	size_t	words;
	size_t	i;
	size_t	str_index;

	if (!str || !*str)
		return (NULL);
	words = word_count(str, delimiter);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	str_index = 0;
	while (i < words)
	{
		while (str[str_index] == delimiter)
			str_index++;
		result[i] = extract_word(str, delimiter, &str_index);
		if (!result[i])
			return (free_result(result, i));
		i++;
	}
	result[words] = NULL;
	return (result);
}
