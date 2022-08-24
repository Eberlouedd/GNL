#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*retour;
	int		i;
	int		taille;

	taille = 0;
	i = 0;
	if (!src)
		return (NULL);
	while (src[taille])
		taille++;
	retour = malloc(sizeof(char) * (taille + 1));
	if (!retour)
		return (NULL);
	while (src[i])
	{
		retour[i] = src[i];
		i++;
	}
	retour[i] = '\0';
	return (retour);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_chain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	new_chain = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_chain)
		return (NULL);
	new_chain[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (j < ft_strlen(s2) || (s2[0] == '\0' && j <= ft_strlen(s2)))
	{
		while (i < ft_strlen(s1))
		{
			new_chain[i] = s1[i];
			i++;
		}
		new_chain[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (new_chain);
}

char	*create_line(char *str)
{
	char	*line;
	int		i;
	int		mem;

	if (!str)
		return (NULL);
	i = 0;
	while(str[i] != '\n' && str[i])
		i++;
	i++;
	line = malloc(i + 1);
	line[i] = '\0';
	mem = i;
	i = 0;
	while(i < mem)
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

char	*clean_stock(char *str)
{
	char	*new;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	if (!test_n(str) || !str)
		new = NULL;
	else
	{
		while (str[i] != '\n' && str[i])
			i++;
		i++;
		new = malloc(ft_strlen(str) - i + 1);
		new[ft_strlen(str) - i] = '\0';
		while (str[i])
		{
			new[j] = str[i];
			j++;
			i++;
		}
	}
	free(str);
	return (new);
}