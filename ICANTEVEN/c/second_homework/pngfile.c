#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

void *read_image(const char *filepath);

/*
void *read_image(char *path) {
        int fd = open(path, O_RDONLY);
        if (fd < 0) {
            return NULL;
        }
        size_t size = 1000;
        size_t offset = 0;
        size_t res;
        char *buff = malloc(size);

        while((res = read(fd, buff + offset, 100)) != 0) {
                offset += res;
                if (offset + 100 > size) {
                        size *= 2;
                        buff = realloc(buff, size);
                }
        }
        close(fd);
        return buff;
}

*/

int main (int argc, char **argv)
{
	//we have to check if the file that we try to compile even exist
	//if we can read the file read.c -> read_image() != NULL -> return Unable to open file
	if(read_image(argv[1]) != NULL) 
	{
		//and here we have to check if the file we read, is PNG file
		int i = 0;
		char *check;
		check = argv[1];
		while(*check != '\0') { check++; }
		if(*(check-3) == 'p' && *(check-2) == 'n' && *(check-1) == 'g')
		{
			char *help = read_image(argv[1]);
			uint32_t *width = help + 16;
			uint32_t *height = help + 20;
			//convert from network byte order to the form that my computer use
			uint32_t wdth = ntohl(*width);
			uint32_t hght = ntohl(*height);

			printf("PNG image width: %d\n", wdth);
			printf("PNG image height: %d\n", hght);

			while(1)
			{
				//we will go through the cicle until we get to IEND
				
				if(help[i] == 'I' && help[i+1] == 'E' && help[i+2] == 'N' && 
				help[i+3] == 'D') break;
				//we have to add 8 bytes to i because IEND contains 4 bytes and 
				//and also the block ends with 4 more bytes for CRC
				//printf("PNG file size: %d\n", i + 8);
				i++;
			}
			printf("PNG file size: %d\n", i+8);
			
		} else printf("Unable to parse file\n");
	} else printf("Unable to open file\n");

	return 0;
}
