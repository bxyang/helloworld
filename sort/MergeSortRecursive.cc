#include<stdio.h>
#include<stdlib.h>


void Merge(int a[],int s,int m,int t)
{
	int i = s;
	int j = m + 1;
	int k = 0;

	int *b = new int[t-s+1];
	while( (i<(m+1)) && (j<(t+1)) ) 
	{
		if(a[i]<a[j])
		{
			b[k++] =a[i];
			i++;
		}
		else
		{
			b[k++] =a[j];
			j++;
		}
	}
	
	if(i<(m+1))
	{
		while(i<(m+1))
		{
			b[k++] = a[i];
			i++;
		}
	}
	else
	{
		while(j<(t+1))
		{
			b[k++] = a[j];
			j++;
		}
	}

	for(int i=0;i<(t-s+1);i++)
		a[i+s] = b[i];

	delete []b;
}

void MergeSortRecursive(int a[], int s,int t)
{
	if(s<t)
	{
		int m = (s+t)/2;
		MergeSortRecursive(a,s,m);
		MergeSortRecursive(a,m+1,t);
		Merge(a,s,m,t);
	}
	else if(s==t)
	{
	}
		//rb[s] = a[s];
	else
		printf("s > t");

}
void testMergeSortRecursive()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	//int a[10] = {10,5,7,3,6,9,2,1,5,3};
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	int b[10];
	MergeSortRecursive(a,0,9);

	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(int argc,char* argv[])
{
	testMergeSortRecursive();
	return 0;	
}
