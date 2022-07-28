#include "concept.h" 

int main(int argc, char *argv[])
{
	char *token;

	if (argc <= 1)
	{
		printf("Retry, type something!\n");
		return (-1);
	}

	token = strtok(argv[1], argv[2]);
	
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, argv[2]);
	}
	return (0);
}
