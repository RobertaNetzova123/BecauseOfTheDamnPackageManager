#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc, char **argv)
{
	for(int i=1;i<argc;i++)
	{

		char ch;
		char new_line = '\n';
		int br=0;
		int fd = open(argv[i],0,O_RDONLY);
		int i,k,check=0;
		off_t size = lseek(fd,0,SEEK_END);
		off_t position;
		ssize_t read_bytes,write_bytes;
		
		if(argc > 2) {
			write(1,"==> ",4);
			write(1,argv[i],strlen(argv[i]));
			write(1," <==\n",5);
		}
		
		for(i=-1;br<=10;i--)
		{
			position = lseek(fd,i,SEEK_END);
			ssize_t readed = read(fd,&ch,1);
			if(ch == '\n')br++;		
		}
		br--;
		if(br < 10)
		{
			do{
	
				read_bytes = read(fd,&ch,1);
				write_bytes = write(1,&ch,1);
	
			  }while(read_bytes != 0);
		}
		else
		{
			for(k=position;k<size-1;k++)
			{
				ssize_t readed = read(fd,&ch,1);
				ssize_t written = write(1,&ch,1);
			}
		}
		br = 0;
		close(fd);
	}
	return 0;
}
