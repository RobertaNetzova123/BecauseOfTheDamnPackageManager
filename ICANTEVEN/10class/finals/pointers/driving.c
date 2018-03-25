#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct driving_license_t
{
	char letters[10];
	int is_master;
};

int can_drive(struct driving_license_t, char[3]);
int is_between(int*, int*, int*);
int* rotate(int*, int*, int*, int*);

int main ()
{
	struct driving_license_t drive;
	fgets(drive.letters,10,stdin);
	scanf("%d",&drive.is_master);
	char ctg[3];
	fgets(ctg,3,stdin);
	printf("%d",can_drive(drive,ctg));
	
	int arr[10];
	int first, middle, last;
	for(int i = 0; i < 10; i++) 
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d %d\n %d\n",&first,&middle,&last);
	rotate(arr,&first,&middle,&last);
	for(int i = 0; i < 10; i++)
	{
		printf("%d",arr[i]);
	}	
	return 0;
}

int can_drive(struct driving_license_t drive, char category[3])
{
	int lenght = strlen(drive.letters);
	for (int i = 0; i < lenght; i++)
	{
		if(category[0] == drive.letters[i])
		{
			if(drive.is_master == 0)
			{
				if(category[1] -'0' < 4)
				{
					return 1;
				}
				else return 0;
			}
			if(drive.is_master == 1) return 1;
		}
	}
	return 0;
}

int is_between(int *first, int *middle, int *last)
{
	if(*middle >= *first && *middle <= *last) return 1;
	else return 0;
}

int* rotate(int *arr, int *first, int *middle, int *last)
{
	int between = is_between(first,middle,last);
	if(between == 1)
	{
	        int help[*last - *first];
		for(int i = 0; i < *last - *middle; i++) { help[i] = arr[i + *middle]; }
		for(int i = 0; i < *middle - *first; i++) { help[*last - *first + i + 1] = arr[i + *first]; }
		for(int i = 0; i < *last - *first; i++) { arr[i + *first] = help[i]; }

	}
	else return 0;
	return 0;
}










