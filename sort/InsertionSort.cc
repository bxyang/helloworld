#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int p = a[i];
		int j = i-1;
		for(;j>-1;j--)
		{
			if(a[j]>p)
				a[j+1] = a[j];
			else
				break;
		}
		a[j+1] = p;
	}
}
void testInsertionSort()
{
	int a[10] ={10,9,8,7,6,5,4,3,2,1};
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

	InsertionSort(a,10);
	
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(int argc,char* argv[])
{
	testInsertionSort();
	return 0;
}
