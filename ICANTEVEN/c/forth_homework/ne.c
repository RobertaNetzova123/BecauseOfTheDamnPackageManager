//------------------------------------------------------------------------
// NAME: Roberta Netzova
// CLASS: XIb
// NUMBER: 21
// PROBLEM: #1
// FILE NAME: fail.c
// FILE PURPOSE:
//Програмата приема  файлове от командния ред и изпълнява системната функция tail 
// за последните 10 реда от файловете. Ако редовете са по –малко от 10,  се извежда целият файл.
//------------------------------------------------------------------------
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <string.h>
int main(int argc, char  **argv) {
	int i = 0;
	int temp =1;
	char ch;
		for (;temp < argc; temp ++) {
		char *filename = argv[temp];
		int fd = open(filename, O_RDONLY);
		if(argc > 2) { 
				write(STDOUT_FILENO, "==> ",4);
				write(STDOUT_FILENO, argv[temp],strlen(argv[temp])); 
				write(STDOUT_FILENO, " <==\n",5);
			
		}
		/*if(fd < 0) {
			perror ("open ");
			return 1;
		}*/
		 int m = 0; 		// m  will be used as couter in the lseek function
		 //i = 0;
		off_t size =  lseek(fd,0, SEEK_END); // the size of the file
		for(;lseek(fd,m, SEEK_END); m--) {   
			read (fd,&ch,1);		   
			if(ch == '\n') {	   
     		 		m++;
    	 	 	}
					
				     
		}	m=0;
		off_t pos = 0;		
		if (i == 10 && temp > 1) {
			m--;
			pos = lseek(fd,--m, SEEK_END); 
		} else  pos = lseek(fd,m, SEEK_END); 
		for(;pos < size; pos++) {	
			read (fd,&ch,1);
			write(STDOUT_FILENO, &ch, 1);
		}
		
		close(fd);
	}

return 0;
}
