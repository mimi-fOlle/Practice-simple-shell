#include "concept.h"

pid_t getpid(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}

pid_t getppid(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}

ssize_t getline(char **lines, size_t *n, FILE *stream)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	printf("cisfun$ ");

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		printf("Error");
		free(line);
		return (1);
	}
	else
		printf("%s", line);
	free(line);
	return (0);
}

char **split_str(char *str)
{
	char *token;
	char **array;
	int buffer = 1024;
	int i = 0;

	token = strtok(str, " ");

	array = malloc(sizeof(char *) * buffer);

	while (token != NULL)
	{
		array[i] = malloc(sizeof(char) * strlen(token));
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	return (array);
}

int execve(const char *pathname, char *const argv[], char *const envp[])
{
	char *args[] = {"/bin/ls", "-l", 0};
	char *env[] = {0};

	if (execve("/bin/ls", args, env) == -1)
	{
		perror("Error");
	}
	exit(1);
}

