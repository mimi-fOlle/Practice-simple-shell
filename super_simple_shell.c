#include "concept.h"

char *readprompt()
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	int sizeline = 0;

	printf("cisfun$ ");

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		printf("Error");
		free(line);
		return (NULL);
	}
	else
	{
		sizeline = strlen(line);
		line[sizeline-1] = '\0';
		return (line);
	}
}

int main()
{
	pid_t parent;
	pid_t child;
	int status;
	char *args[]={"00000000000", "/usr/",0};
	char *env[] = {0};

	args[0] = readprompt();	
	
	printf("args[0] = %s with strelen of: %ld\n", args[0], strlen(args[0])); 
	child = fork();
	
	if (child == -1)
	{
		perror("Error child = -1 \n");
		return (1);
	}

	if (child == 0)
	{
		chdir()
		if (execve(args[0], args, env) == -1)
		{
			perror("Error execute\n");
			return (1);
		}
	}
	else
	{
		wait(&status);
		printf("father work\n");
	}
	return (0);
}
