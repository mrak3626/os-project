/*3. Write a multithreaded program in C that outputs prime numbers. This program should
work as follows: The user will run the program and will enter a number on the command
line. The program will then create a separate thread that outputs all the prime numbers*/
less than or equal to the number entered by the user.
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *show(void *num)
{
	printf("\n\n  Output Thread :\n");
	printf("  **************\n");
	printf("\n\nPrime Numbers are : \n");
	int i,j,flag;
	int *n=(int *)num;
	for(i=1;i<=*n;i++)
	{
		flag=0;
		for(j=1;j<=*n;j++)
		{
			if(i%j==0)
		 {
			flag=flag+1;
		 }
	    }
		if(flag==2)
		{
			printf("%d ",i);
		}
	}
	
}
int main()
{
	int n;
	printf("\n\n  Input Thread :\n");
	printf("  *************\n");
	printf("\n\n  Enter a number upto which prime numbers are required:-\n");
	scanf("%d",&n);
	pthread_t tid;
	pthread_create(&tid,NULL,show,&n);
	pthread_join(tid,NULL);
	return 0;
}
