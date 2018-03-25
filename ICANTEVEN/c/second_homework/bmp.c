#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
#include <string.h>
#include <stdint.h>


void *read_image(char *path);

/*void *read_image(char * path) {
	int fd = open(path, O_RDONLY);
	if (fd < 0) {
		return NULL;
	}
	size_t size = 100;
	size_t offset = 0;
	size_t res;
	char *buff = malloc(size);

	while((res = read(fd, buff + offset, 100)) != 0) {
		offset = offset + res;
		if(offset + 100 > size) {
			size = size * 2;
			buff = realloc(buff, size);
		}
	}
	close(fd);
	return buff;
}*/

int main(int argc, char **argv) {

	//int32_t height;
	//int32_t width;

	char *help = read_image(argv[1]);
	// the image height is located on the 22nd byte from the beggining of the file
	int32_t *height = (help + 22);
	//the image width is located on the 18th byte from the beggining of the file
	int32_t *width = (help + 18);
	
	printf("BMP image width: %d\n", *width);
	printf("BMP image height: %d\n", *height);
	return 0;
}


