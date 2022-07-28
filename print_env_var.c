#include "concept.h"

int main(int argc, char *argv[], char *envp[])
{
	char **env = envp;

	while (*env != 0)
	{
		char *addr = *env;
		printf("%s\n", addr);
		env++;
	}
	return (0);
}
