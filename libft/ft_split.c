/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 11:57:54 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/02/01 15:34:32 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ft_split allocates with malloc and returns an array of strings 			  */
/* obtained by splitting ’s’ using the character ’c’ as a delimiter. 		  */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *string, char separator_char)
{
	int	count;

	count = 0;
	while (*string)
	{
		if (*string != separator_char)
		{
			while (*string != separator_char && *string)
				string++;
			count++;
		}
		if (*string == separator_char)
			string++;
	}
	return (count);
}

static int	ft_free(char **split, int index)
{
	while (index-- > 0)
		free(split[index]);
	free(split);
	return (1);
}

static int	word(const char *string, char separator_char, char **split)
{
	size_t	start;
	size_t	end;
	int		index;

	start = 0;
	end = 0;
	index = 0;
	while (string[start])
	{
		if (string[start] != separator_char)
		{
			end = start;
			while (string[end] != separator_char && string[end])
				end++;
			split[index] = ft_substr(string, start, (end - start));
			if (!split[index])
				return (ft_free(split, index));
			index++;
			start = end;
		}
		if (string[start] == separator_char && string[start])
			start++;
	}
	split[index] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	if (word(s, c, split) == 1)
		return (NULL);
	return (split);
}
