#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	DIR * dd = opendir(argv[1]);
	struct stat *buf = (struct stat *)malloc(sizeof(struct stat *));

	if( dd == NULL )
	{
		perror("oepndir");
		return 0;
	}

	while(1)
	{
		struct dirent *the_directory = readdir(dd);
		char total_dir[200] = {0,};

		if(the_directory == NULL)
		{
			break;
		}
		strcpy(total_dir, argv[1]);
		strcat(total_dir, the_directory->d_name);
		if(stat(total_dir, buf) == 0)
		{
			printf("%s ",the_directory->d_name);
		}
		else
		{
			break;
		}

		if(S_ISREG(buf->st_mode))
		{
			printf("is Regular file\n");
		}
		else if(S_ISDIR(buf->st_mode))
		{
			printf("is Directory file\n");
		}
		else if(S_ISCHR(buf->st_mode))
		{
			printf("is Character device\n");
		}
		else if(S_ISBLK(buf->st_mode))
		{
			printf("is Block device\n");
		}
		else if(S_ISFIFO(buf->st_mode))
		{
			printf("is FIFO or pipe\n");
		}
		else if(S_ISSOCK(buf->st_mode))
		{
			printf("Socket\n");
		}
		else if(S_ISLNK(buf->st_mode))
		{
			printf("Symbolic link\n");
		}
		//printf("%s %s %s %S",the_directory->d_name);
	}

	//printf("\n");
	closedir(dd);
	return 0;
}
