#include "concept.h" 

int main(int argc, char **argv)
{
	pid_t parent;
	pid_t child;
	int status;
	int i = 0;
	char *args[] = {"/bin/ls", "-l", "/tmp", 0};
	char *env[] = {0};

	for (i = 0; i < 5; i++)
	{
		printf("%d _____________\n", i);
		
		child = fork();

		if (child != 0)
			wait(&status);

		if (child == -1) //negative means fork fails
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
			else
				execve("/bin/ls", args, env);
		}
	}
	return (0);
}
