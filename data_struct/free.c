#include "utils.h"
#include <stdlib.h>

void	safety_free(void **ptr)
{
	if (*ptr == NULL)
		free(*ptr);
	*ptr = NULL;
}
