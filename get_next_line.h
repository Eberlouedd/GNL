#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*create_line(char *str);
char	*clean_stock(char *str);
int     test_n(char *str);
char	*get_next_line(int fd);
int		formate_line(char *str);

#endif