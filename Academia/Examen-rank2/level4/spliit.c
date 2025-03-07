#include <stdlib.h>

int	ft_is_delimiter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_words_len(char *str)
{
	int	idx;
	int	length;

	idx = 0;
	length = 0;
	while (str[idx] != '\0')
	{
		if (!ft_is_delimiter(str[idx]))
		{
			length++;
			idx++;
		}
		else
			idx++;
	}
	return (length);
}

char	*ft_get_word(char *str)
{
	int			idx;
	char		*word;

	idx = 0;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
		idx++;
	word = (char *)malloc(sizeof(char) * (idx + 1));
	if (!word)
		return (NULL);
	idx = 0;
	while (str[idx] != '\0' && !ft_is_delimiter(str[idx]))
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		idx;
	char	**split;

	idx = 0;
	split = (char **)malloc(sizeof(char *) * ft_words_len(str) + 1);
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_delimiter(*str))
			str++;
		if (*str && !ft_is_delimiter(*str))
		{
			split[idx] = ft_get_word(str);
			idx++;
		}
		while (*str && !ft_is_delimiter(*str))
			str++;
	}
	split[idx] = NULL;
	return (split);
}


#include <stdio.h>
int	main(void)
{
	int		idx;
	char	**tab;
	idx = 0;
	tab = ft_split("The prophecy is true");
	while (idx < 4)
	{
		printf("String %d : %s\n", idx, tab[idx]);
		idx++;
	}
	return (0);
}