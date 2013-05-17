#include<stdlib.h>
#include<stdio.h>


void Sift(int a[],int k,int n)
{
	int i=k;
	int j = 2*(i+1) -1;
	while(j<n)
	{
		if(j<(n-1) && a[j+1]>a[j])
			j++;
		if(a[i]>a[j])
			break;
		else
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i = j;
			j = 2*(i+1)-1;
		}
	}
}
void HeapSort(int a[],int n)
{
	for(int i = (n/2-1);i>-1;i--)
		Sift(a,i,n);
	for(int j=0;j<n;j++)
	{
		int t = a[0];
		a[0] = a[n-j-1];
		a[n-j-1] = t;
		Sift(a,0,n-j-1);
	}
}

void testHeapSort()
{

	int a[10]={10,9,8,7,6,5,4,3,2,1};
	//int a[10] ={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

	HeapSort(a,10);

	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

}
int main(int argc,char* argv[])
{
	testHeapSort();
	return 0;
}
