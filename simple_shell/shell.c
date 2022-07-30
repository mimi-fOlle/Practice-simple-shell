#include "shell.h"

int main(int argc, char **argv)
{
	char *cmdline;
	char **cmdargs;
	int signal = 1;

	while (signal == 1)
	{
		printf("#cisfun$ ");

		cmdline = readprompt();

		if (cmdline != NULL)
		{
			//check if command is exit to exit program
//			if (!strcmp(cmdline, "exit"))
//				return (1);

			//format the command to be used with execve
			cmdargs = format_cmd(cmdline);

			//excute command and maintain status to continue or stop loop of prompt
			signal = exec_cmd(argv, cmdargs);

			//free allocated memories of pointers
			free(cmdargs);
		}
		else
		{
			printf("detected NULL cmd\n");
		}
		free(cmdline);
	}
	return (0);
}
