#include<stdio.h>
#include<stdlib.h>

void ShellSort(int a[],int n)
{
    for(int d=n/2;d>0;d=d/2)
    {
        for(int i=d;i<n;i++)
        {
            int j=i-d;
            int p = a[i];
            for(;j>-1;j-=d)
            {
                if(a[j]>p)
                    a[j+d] = a[j];
                else
                    break;
            }
            a[j+d] = p;
        }
    }
}

void testShellSort()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    ShellSort(a,10);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");

}
int main(int argc,char* argv[])
{
    testShellSort();
    return 0;
}
