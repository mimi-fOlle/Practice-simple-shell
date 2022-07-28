#include "concept.h" 

int main(int argc, char *argv[])
{
	char *str1;
	char *token;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s string delim\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (str1 = argv[1]; ; str1 = NULL)
	{	
		token = strtok(str1, argv[2]);
		if (token == NULL)
			break;
		printf("%s\n", token);
	}
	exit(EXIT_SUCCESS);
}
