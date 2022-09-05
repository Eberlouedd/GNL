#include "get_next_line.h"
#include <stdio.h>

int	test_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	formate_line(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if(n > 1)
			return (0);
		i++;
	}
	if(str[i - 1] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*cursor;
	char		*line;
	static char	*stock = NULL;
	int			ret;

	if (!test_n(stock))
	{
		cursor = malloc(BUFFER_SIZE + 1);
		while ((ret = read(fd, cursor, BUFFER_SIZE)) > 0)
		{
			cursor[ret] = '\0';
			stock = ft_strjoin(stock, cursor);
			if(test_n(cursor))
				break;
		}
		free(cursor);
	}
	line = create_line(stock);
	stock = clean_stock(stock);
	return (line);
}
