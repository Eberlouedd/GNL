#include "get_next_line.h"

#include <stdio.h>
char *get_next_line(int fd)
{
	char		str[BUFFER_SIZE + 1];
	static char	*buffer;
	char		*line;
	int			i;
	int			r;
	
	i = 0;
	r = read(fd, str, BUFFER_SIZE);
	printf("%d\n", r);
	str[BUFFER_SIZE] = '\0';
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	buffer = r - i;
	line = malloc(i + 1);
	while(i >= 0)
	{
		line[i] = str[i];
		i--;
	}
	//free(str);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return 0;
}