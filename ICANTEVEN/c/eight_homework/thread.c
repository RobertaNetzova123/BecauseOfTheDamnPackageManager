//------------------------------------------------------------------------
// NAME: Mihaela Gadzhalova
// CLASS: XIb
// NUMBER: 18
// PROBLEM: #1
// FILE NAME: thread.c
// FILE PURPOSE:
// Realisation of a program which find the number of prime numbers between 
//2 and N using a one thread for each calculation
//------------------------------------------------------------------------

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#define N 555
#define ARRAY_SIZE 777

//------------------------------------------------------------------------
// FUNCTION: prime
// find the count of prime numbers between 2 and N
// PARAMETERS:
// pr - the number to where we are looking for prime numbers
//------------------------------------------------------------------------

void *prime(void * pr) {
	long number = (long) pr;
	int i, j, end, isPrime; 
	int count = 0;
  
	printf("Prime calculation started for N=%ld\n",number);
    	for(i=2; i<number; i++) {
		isPrime = 1; 
		for(j=2; j<=i/2; j++) {
            		if(i%j==0) {
                		isPrime = 0;
                		break;
            		}
        	}
        	if(isPrime==1) {
        	 count++; 
        	}
    	}
	printf("Number of primes for N=%lu is %d\n",number,count);

}


int main() {

	pthread_t thread[N];
	char array[ARRAY_SIZE];
	int t = 0;
	int insert_numbers;
	while(1) {
		scanf("%s",array);
		int length = strlen(array); //take the length of the given command; to be sure that it is actually a command
		if(length == 1) { //if it is actually the command it should be, check which one it is
			if(array[0] == 'p') {
				scanf("%d", &insert_numbers);
				int th = pthread_create(&thread[t], NULL, prime, (void*)insert_numbers); //create thread and save in it a calculation
				if(th) {
					exit(-1);
				}
			}
			if(array[0] == 'e') {
				break;
			}
		} else {
			printf("Supported commands:\np N - Starts a new calculation for the number ot primes from 1 to N\n e - Waits for all calculations to finish and exits\n");
		}
		t++;
	
	}

	for(int i = 0; i < t; i++) {
		int th = pthread_join(thread[i],NULL); //wait the thread before stopping it
	}

	return 0;
}

