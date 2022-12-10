#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>

int		ft_strcmp(char *str, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char *str, int s, int e);
void	safety_free(void **ptr);
#endif
