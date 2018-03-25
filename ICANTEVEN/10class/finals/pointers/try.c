#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int sample = 42;
	int *p = &sample;
	
	printf("variable values %d\n", sample);
	printf("variable values %d\n",*p);
	printf("variable adress %p\n",(void*)&sample);
	printf("pointer points to %p\n",(void*)p);
	printf("pointer adress %p\n",(void*)&p);

	return 0;
}

