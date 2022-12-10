#include "utils.h"

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	if (str == NULL && str2 == NULL)
		return (0);
	if (str == NULL)
		return (1);
	if (str2 == NULL)
		return (1);
	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (1);
		++i;
	}
	if (str[i] != str2[i])
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	ret = (char *)malloc(len + 1);
	while (i < len)
	{
		ret[i] = str[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_substr(char *str, int s, int e)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(e - s + 1);
	while (i + s < e)
	{
		ret[i] = str[i + s];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

void	safety_free(void **type)
{
	if (*type != NULL)
	{
		free(*type);
		(*type) = NULL;
	}
}
