#include <stdio.h>
int main()
{
        int n,nechetni[n],i,p,k;
        scanf("%d",&n);
        i=1;
        while(i<n)
        {
                while(nechetni[i]%2==0);
                {
                        scanf("%d",&nechetni[i]);
                }
                i++;
        }

        for(i=0;i<n/2;i++)
        {
                p=nechetni[i] - nechetni[n-i-1];
                printf("%d",p);
        }

        if(n%2!=0)
        {
                k=nechetni[n/2];
                printf("%d",k);
        }

        return 0;
}
    
