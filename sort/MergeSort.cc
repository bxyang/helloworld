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

void MergePass(int a[],int n,int h)
{
    int i = 0;
    for(;i<n-2*h+2;i+=2*h)
    {
        Merge(a,i,i+h-1,i+2*h-1);
    }
    //i = i-2*h;
    if(n-i>h)
        Merge(a,i,i+h-1,n-1);
}

void MergeSort(int a[],int n)
{    
    int h = 1;
    while(h<n)
    {
        MergePass(a,n,h);
        h = 2*h;
    }
}
void testMergeSort()
{

    int a[10]={10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");

    MergeSort(a,10);

    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(int argc,char* argv[])
{
    testMergeSort();
}
