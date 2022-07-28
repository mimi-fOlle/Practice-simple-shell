#include "concept.h"

extern char **environ;

int main(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%p\n", environ[i]);
		i++;
	}
	return (0);
}
