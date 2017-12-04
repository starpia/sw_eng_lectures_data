#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	DIR * dd = opendir(argv[1]);
	if( dd == NULL )
	{
		perror("oepndir");
		return 0;
	}

	while(1)
	{
		struct dirent *the_directory = readdir(dd);
		if(the_directory == NULL)
		{
			break;
		}
		
		printf("%s ",the_directory->d_name);
	}

	printf("\n");
	closedir(dd);
	return 0;
}
