#include "stdafx.h"
#include "conio.h"
#include "math.h"
	
void check_id(int *arr)
	{
		int sum=0,check_dig;
		for (int w=0;w<9;w+=2)
			sum+=arr[w];
		for (int w=1; w<9;w+=2)
			if (arr[w]*2<10) sum+=(arr[w]*2);
				else 
				{
				int tmp=arr[w]*2;
			 	sum+=(tmp%10)+(tmp/10);
				}
			
			sum=sum%10;
		check_dig=abs(10-sum);

		if (check_dig==arr[9]) printf("id OK");
	else printf("id error");

	
	}
void main(void)
	{
	unsigned int id;	
	int arr[9]={0};

	printf("enter the id\n");
	scanf("%d",&id);
	if ((id>1000000000)&&(id<1))
		printf("id error");
	else	
		{
		//braking up the number to the array
		int div=100000000;
		for (int i=8;i>0;--i)
			{
			if (id!=0)
				{
				arr[i]=id%10;
				id/=10;
				}
			else arr[i]=0;
			}
		check_id(arr);
		getch();
		}
	}