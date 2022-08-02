#include "concept.h"
#include <limits.h>
#include <libgen.h>

/* int checkifexecutable(const char *filename)
 * 
 * Return non-zero if the name is an executable file, and
 * zero if it is not executable, or if it does not exist.
 */

int checkifexecutable(const char *filename)
{
	int result;
	struct stat statinfo;

	result = stat(filename, &statinfo);
	if (result < 0)
		return (0);
	if (!S_ISREG(statinfo.st_mode))
		return (0);
	if (statinfo.st_uid == geteuid())
		return (statinfo.st_mode & S_IXUSR);
	if (statinfo.st_gid == getegid())
		return (statinfo.st_mode & S_IXGRP);
	return (statinfo.st_mode & S_IXOTH);
}

/* int findpathof(char *pth, const char *exe)
 *
 * Find executable by searching the PATH environment variable.
 *
 * const char *exe - executable name to search for.
 *       char *pth - the path found is stored here, space
 *                   needs to be available.
 *
 * If a path is found, returns non-zero, and the path is stored
 * in pth.  If exe is not found returns 0, with pth undefined.
 */

int findpathof(char *pth, const char *exe)
{
	char *searchpath;
	char *beg, *end;
	int stop, found;
	int len;

	if (strchr(exe, '/') != NULL)
	{
		if (realpath(exe,pth) == NULL)
			return (0);
/*		return (checkifexecutable(pth);*/
	}

	searchpath = getenv("PATH");
	if (searchpath == NULL)
		return (0);
	if (strlen(searchpath) <= 0)
		return (0);

	beg = searchpath;
	stop = 0;
	found = 0;
	do {
		end = strchr(beg, ':');
		if (end == NULL)
		{
			stop = 1;
			strncpy(pth, beg, PATH_MAX);
			len = strlen(pth);
		}
		else
		{
			strncpy(pth, beg, end - beg);
			pth[end - beg] = '\0';
			len = end - beg;
		}
		if (pth[len - 1] != '/')
		{
			strncat(pth, "/", 1);
		}
		strncat(pth, exe, PATH_MAX - len);
		found = checkifexecutable(pth);
		if (!stop)
			beg = end + 1;
	}	
	while (!stop && !found);
	return (found);
}

int main(int argc, char *argv[])
{
	char path[PATH_MAX + 1];
	char *progpath = strdup(argv[0]);
	char *prog = basename(progpath);
	char *exe;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <executable file>\n", prog);
		return (1);
	}
	exe = argv[1];

	if (!findpathof(path, exe))
	{
		fprintf(stderr, "No executable \"%s\" found\n", exe);
		return (1);
	}
	puts(path);
	free(progpath);
	return (0);
}
