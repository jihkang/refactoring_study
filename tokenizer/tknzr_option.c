#include "token.h"

int	ft_correct_input_ascii(char c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c == '\'' || c == '\"' || c == '$'));
}
