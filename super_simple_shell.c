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

int main(int argc, char *argv[])
{
	char *token;

	if (argc <= 0)
		return (-1);
	token = strtok(argv[1], argv[2]);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, argv[2]);
	}
	return (0);
}
/**
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
*/

int main()
{
	pid_t parent;
	pid_t child;
	int status;
	char *args[] = {"/bin/ls", "-l", 0};
	char *env[] = {0};

	child = fork();
	
	if (child == -1)
	{
		perror("Error:");
		return (1);
	}

	if (child == 0)
	{
		if (execve("/bin/ls", args, env) == -1)
		{
			perror("Error:");
			return (1);
		}
		execve("ls", args, env);
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("father work\n");
	}
	return (0);
}
