#include "concept.h" 

int main(int argc, char **argv)
{
	char *args[] = {"/bin/ls", "-l", "/usr/", 0};
	char *env[] = {0};

	printf("Before execve\n");
	if (execve("/bin/ls", args, env) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	exit(1);
}
