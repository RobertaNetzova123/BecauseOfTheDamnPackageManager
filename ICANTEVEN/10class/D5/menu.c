#include <stdio.h>
#define clear() printf ("\033[H\033[J")
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
int main()
{
	int zadacha;

	do
	{	
		
		printf ("\n Menu \n");
		printf ("\n 1. Bubble sort \n"
			"\n 2. Selection sort \n"
			"\n 3. Insertion sort \n"
			"\n FOR EXIT PRESS 4 \n"
			"\n ---------------------------------\n"); 
		printf (BOLDRED"\n Enter the number of the task:"RESET);
		scanf("%d",&zadacha);
		clear();
		switch (zadacha)
		{
			case 1: printf ("\n 1. Bubble sort \n");
			{	int zad;
				do
				{	
					
					printf(BOLDRED"\n 1.1. Show the code \n"RESET);
					printf(BOLDYELLOW"\n 1.2. Execute the code \n"RESET);
					printf(BOLDGREEN"\n 1.3. Demo of the code \n"RESET);
					printf(BOLDWHITE"\n FOR EXIT PRESS 4 \n"RESET);
					printf (BOLDCYAN"\n Choose one..."RESET);
					scanf("%d",&zad);
					clear();
					switch(zad)
					{
						case 1: printf (BOLDRED"\n 1.1. Show the code \n"RESET);
							printf(
							"\n #include <stdio.h>"
							"\n int main ()"
							"\n {"
							"\n 	float b[50],c;"
                                			"\n 	int sorted,j,i,n,k;"
                            			        "\n 	sorted=0;"
                                			"\n 	printf(""\"\\n"" Input n:\""");"
                                			"\n 	scanf(""\"%%""d\""",&n"");"
                                			"\n 	i=0;"
                                			"\n 	for(k=0;k<n;k++)"
                                			"\n 	{"
                                        		"\n 		printf(""\"\\n"" Input a number ""%%""%d""\":,k+1"");"
                                        		"\n 		scanf(""\"%%""f\""",&b[k]"");"
                                			"\n 	}"
                                			"\n 	i=0;"
                                			"\n 	for(i=1;1<n;i++)"
                                			"\n 	{"
                                        		"\n 		sorted=1;"
                                        		"\n 		for(j=0;j<n-i;j++)"
                                        		"\n 		{"
                                               		"\n 			 if(b[j]<b[j+1])"
                                               		"\n 			 {"	
                                                        "\n 	 			c=b[j];"
                                                       	"\n 			 	b[j]=b[j+1];"
                                                        "\n 	      			b[j+1]=c;"
                                                        "\n 				sorted=0;"
                                               	        "\n 	         	 }"
							"\n 		}"
                                        		"\n 		if(sorted) break;"
                                			"\n 	}"
                                			"\n 	for (k=0;k<n;k++)"
                                			"\n 	printf(""\"\\n""%%"".f""\",b[k]"");"
							"\n } \n");break;

						case 2: printf (BOLDYELLOW"\n 1.2. Execute the code \n"RESET);
							{
								float b[50],c;
        				                        int sorted,j,i,n,k;
                              				        sorted=0;
                               			              	printf("\n Input n:");
                                				scanf("%d",&n);
                                				i=0;
                                				for(k=0;k<n;k++)
                                				{
                                        				printf("\n Input a number %d:",k+1);
                                        				scanf("%f",&b[k]);
                                				}
                               				        i=0;
                                				for(i=1;1<n;i++)
                                				{
                                        				sorted=1;
                                        				for(j=0;j<n-i;j++)
                                       					{
                                                				if(b[j]<b[j+1])
                                                				{
                                                        				c=b[j];
                                                        				b[j]=b[j+1];
                                                       		 			b[j+1]=c;
                                                        				sorted=0;
                                                				}
                                        				}
                                        				if(sorted) break;
                                				}
                                				for (k=0;k<n;k++)
                               					 printf("\n%.f \n",b[k]);
							}; break;

						case 3: printf (BOLDGREEN"\n 1.3. Demo of the code \n"RESET);
							printf(
								BLUE"\n For example:\n"RESET
								"\n ~We have to arranged these numbers in descending order~\n"
								"\n 7  12  -6  18  4  51   *We take the first element of the array and compare it with the second and exchanging their values if the first is									 larger than the second. Then compare the second element with the third and again exchanging, if it's necessary.*\n"
								"\n 12  7  18  4  51  |_-6   *Do the same thing with the other elements.*\n"
								"\n 12  18  7  51  |_4  -6   *again*\n"
								"\n 18  12  51  |_7  4  -6   *and again*\n"
								"\n 18  51  |_12  7  4  -6   *againnnn*\n"
								"\n 51  |_18  12  7  4  -6   *ready?*\n"
								"\n 51  18  12  7  4  -6   *ready!*\n"); break;

						default: printf (CYAN"\nOooooops! Error! Are you an idiot?? There is no such an option...\n"RESET); break;
					}		
					
				}while(zad!=4);

			};break;	

			case 2: printf ("\n 2. Selection sort \n");
			{	int zad1;
                                do
                                {

                                        printf(BOLDRED"\n 1.1. Show the code \n"RESET);
                                        printf(BOLDYELLOW"\n 1.2. Execute the code \n"RESET);
                                        printf(BOLDGREEN"\n 1.3. Demo of the code \n"RESET);
					printf(BOLDWHITE"\n FOR EXIT PRESS 4 \n"RESET);
                                        printf (BOLDCYAN"\n Choose one..."RESET);
                                        scanf("%d",&zad1);
                                        clear();
                                        switch(zad1)
					{
						case 1: printf (BOLDRED"\n 1.1. Show the code\n"RESET);
							 printf(
                                                        "\n #include <stdio.h>"
                                                        "\n int main ()"
                                                        "\n {"
                                                        "\n     float sl[50],;"
                                                        "\n     int max,maxindex,j,i,n;"
                                                        "\n     maxindex=0;"
                                                        "\n     printf(""\"\\n"" Input n:\""");"
                                                        "\n     scanf(""\"%%""d\""",&n"");"
                                                        "\n     for(i=0;i<n;i++)"
                                                        "\n     {"
                                                        "\n             printf(""\"\\n"" Input a number ""%%""%d""\":,i+1"");"
                                                        "\n             scanf(""\"%%""f\""",&sl[i]"");"
                                                        "\n     }"
                                                        "\n     i=0;"
                                                        "\n     for(i=0;i<n;i++)"
                                                        "\n     {"
                                                        "\n             max=sl[i];"
							"\n 		maxindex=i;"
                                                        "\n             for(j=i+1;j<n-i;j++)"
                                                        "\n             {"
                                                        "\n                      if(max<sl[j])"
                                                        "\n                      {"
                                                        "\n                             max=sl[j];"
                                                        "\n                             maxindex=j;"
                                                        "\n                      }"
                                                        "\n             }"
                                                        "\n           	sl[maxindex]=sl[i];"
							"\n		sl[i]=max;"
                                                        "\n     }"
                                                        "\n     for (i=0;i<n;i++)"
                                                        "\n     printf(""\"\\n""%%"".f""\",sl[i]"");"
                                                        "\n } \n");break;

						case 2: printf (BOLDYELLOW"\n 1.2. Execute the code \n"RESET);
							{
								float sl[50];
								int i,j,n,max,maxindex;
								maxindex=0;
								printf("\n Input n:");
								scanf("%d",&n);
								for(i=0;i<n;i++)
								{
									printf("\n Input a number %d:",i+1);
									scanf("%f",&sl[i]);
								}
								for(i=0;i<n;i++)
								{
									max=sl[i];
									maxindex=i;
									for(j=i+1;j<n;j++)
									{
										if(max<sl[j]) { max=sl[j]; maxindex=j; }

									}
									sl[maxindex]=sl[i];
									sl[i]=max;
								}
								for(i=0;i<n;i++)
								printf("\n %.f \n",sl[i]);
								
							};break;
						case 3: printf (BOLDGREEN"\n 1.3. Demo of the code \n"RESET);
							printf(
                                                                BLUE"\n For example:\n"RESET
                                                                "\n ~We have to arranged these numbers in descending order~\n"
                                                                "\n 7  12  -6  18  4  51   *We find the maximum element of the array and exchanging it with the first one. Then we find the next maximum element and exchanging it with the second element in the array*\n"
								"\n 7  12  -6  18  4  51   *We mark the elements....*"
								"\n ^                  ^ \n"
                                                                "\n 51  12  -6  18  4  7   *...and exchange their places *\n"
								"\n 51  12  -6  18  4  7   *Now we do the same process with the other elements.*"
								"\n      ^       ^\n"
                                                                "\n 51  18  -6  12  4  7    *OKAY, It's almost done!*\n"
								"\n 51  18  -6  12  4  7"
								"\n          ^   ^\n"
                                                                "\n 51  18  12  -6  4  7   *almost...*\n"
								"\n 51  18  12  -6  4  7"
								"\n              ^     ^\n"
                                                                "\n 51  18  12  7  4  -6   *oh..*\n"
								"\n 51  18  12  7  4  -6"
								"\n                ^   ^\n" 
                                                                "\n 51  18  12  7  4  -6   *ol..It's fine*\n"); break;

						default: printf (CYAN"\nOooooops! Error! Are you an idiot?? There is no such an option...\n"RESET); break;
					}
				}while(zad1!=4);
			};break;

			case 3: printf("\n 3. Insertion sort\n");
			{	int zad2;
				do
				{
					printf(BOLDRED"\n 1.1. Show the code \n"RESET);
                                        printf(BOLDYELLOW"\n 1.2. Execute the code \n"RESET);
                                        printf(BOLDGREEN"\n 1.3. Demo of the code \n"RESET);
					printf(BOLDWHITE"\n FOR EXIT PRESS 4 \n"RESET);
                                        printf (BOLDCYAN"\n Choose one..."RESET);
                                        scanf("%d",&zad2);
                                        clear();
                                        switch(zad2)
					{
						case 1: printf (BOLDRED"\n 1.1. Show the code \n"RESET);
							 printf(
                                                        "\n #include <stdio.h>"
                                                        "\n int main ()"
                                                        "\n {"
                                                        "\n     float vm[50],;"
                                                        "\n     int i,j,n,x;"
                                                        "\n     printf(""\"\\n"" Input n:\""");"
                                                        "\n     scanf(""\"%%""d\""",&n"");"
                                                        "\n     for(i=0;i<n;i++)"
                                                        "\n     {"
                                                        "\n             printf(""\"\\n"" Input a number ""%%""%d""\":,i+1"");"
                                                        "\n             scanf(""\"%%""f\""",&vm[i]"");"
                                                        "\n     }"
                                                        "\n     for(i=1;i<n;i++)"
                                                        "\n     {"
                                                        "\n             x=vm[i];"
                                                        "\n             for(j=i-1;j>=0;j--)"
                                                        "\n             {"
                                                        "\n                      if(x>vm[j])"
                                                        "\n                      vm[j+1]=vm[j];"
							"\n 			 else break;"
                                                        "\n             }"
                                                        "\n             vm[j+1]=x;"
                                                        "\n     }"
                                                        "\n     for (i=0;i<n;i++)"
                                                        "\n     printf(""\"\\n""%%"".f""\",vm[i]"");"
                                                        "\n } \n");break;

						case 2: printf (BOLDYELLOW"\n 1.2. Execute the code\n"RESET);
							{
								float vm[50];
								int i,j,n,x;
								printf("\n Input n:");
								scanf("%d",&n);
								for(i=0;i<n;i++)
								{
									printf("\n Input a number %d:",i+1);
									scanf("%f",&vm[i]);
								}
								for(i=1;i<n;i++)
								{
									x=vm[i];
									for(j=i-1;j>=0;j--)
									{
										if(x>vm[j])
										vm[j+1]=vm[j];
										else break;
									}
									vm[j+1]=x;
								}
								for(i=0;i<n;i++)
								printf("\n %.f\n",vm[i]);
							};break;
						case 3: printf (BOLDGREEN"\n1.3. Demo of the code\n"RESET);
							printf(
                                                                BLUE"\n For example:\n"RESET
                                                                "\n ~We have to arranged these numbers in descending order~\n"
                                                                "\n 7  12  -6  18  4  51   *The array of the elements that will e sorted is divided into two parts: sorted part and unsorted part. We take the first element of the unsorted list and inserted it in the correct position in the sorted part of the list.*\n"
                                                                "\n 7  12  -6  18  4  51   *Let's start*"
                                                                "\n ^  \n"
                                                                "\n 7  12   18  4  51   *This will be loooong*\n"
                                                                "\n 7  12  -6  18  4  51   *And because 12>7 we exchange its place.*"
                                                                "\n     ^\n"
                                                                "\n 12  7  -6  18  4  51    *I think -6 is OKAY here.*\n"
                                                                "\n 12  7  -6  18  4  51"
                                                                "\n         ^\n"
                                                                "\n 12  7  -6  18  4  51     *Just a few more numbers and we're ready. Don't worry..*\n"
                                                                "\n 12  7  -6  18  4  51"
                                                                "\n             ^\n"
                                                                "\n 18  12  7  -6  4  51   *We exchanged 18 before 12.Why? Because 18>12...obviously.*\n"
                                                                "\n 18  12  7  -6  4  51"
                                                                "\n                ^\n"
                                                                "\n 18  12  7  4  -6  51   *We put 4 between 7 and -6. This is its place! MOVE AWAY!*\n"
								"\n 18  12  7  4  -6  51   *Calm down. Just one number left.*"
								"\n                    ^\n"
								"\n 51  18  12  7  4  -6   *Well, it's done. Congratulations! We made it!*\n");break;


						default: printf (CYAN"\nOooooops! Error! Are you an idiot?? There is no such an option...\n"RESET); break;

					}

				}while(zad2!=4);
			};break;
					
				
	
	}	
	}while(zadacha!=4);




	return 0;
}

