#include "concept.h"

int main(void)
{
	int MAX_BUF = 200;
	char path[MAX_BUF];

	errno = 0;
	if (getcwd(path, MAX_BUF) == NULL)
	{
		if (errno == ERANGE)
			printf("Error\n");
		else
			perror("getcwd");
		return (-1);
	}
	printf("Current working directory: %s\n", path);

	return (0);
}
