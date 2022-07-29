#include "concept.h"

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
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	array[i] = NULL;
	return (array);
}

int main()
{
	int i = 0;	
 	char tst[] = "ls -l";	
	char **arr = split_str(tst);

	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i++]);
	}	
	free(arr);
	return (0);
}
