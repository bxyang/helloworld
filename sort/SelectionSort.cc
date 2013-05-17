#include<stdio.h>
#include<stdlib.h>


void SelectionSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int index = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[index])
				index = j;
		}
		if(index!=i)
		{
			int t = a[i];
			a[i] =a[index];
			a[index] = t;
		}
	}
}

void testSelectionSort()
{

	int a[10]={10,9,8,7,6,5,4,3,2,1};
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

	SelectionSort(a,10);

	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

}
int main(int argc,char* argv[])
{
	testSelectionSort();
	return 0;
}
