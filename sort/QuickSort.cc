#include<stdio.h>
#include<stdlib.h>


int Partion(int a[],int first,int end)
{
    int i = first;
    for(int j = first + 1; j <= end; j++){
        if(a[j] < a[first])
        {   
            i++;
            int mid = a[i];
            a[i] = a[j];
            a[j] = mid;
        }  
    }
    int mid = a[i];
    a[i] = a[first];
    a[first] = mid;
    for(int q=first; q<=end; q++)
        printf("%d ",a[q]);
    printf("\n");
    return i;
}
void QuickSort(int a[],int first,int end)
{
    if(first<end)
    {
        int axis = Partion(a, first, end);
        printf("%d\n", axis);
        QuickSort(a, first, axis-1);
        QuickSort(a, axis+1, end);
    }    
}
void testQuickSort()
{
    //int a[10]={10,9,8,7,6,5,4,3,2,1};
    //int a[9] = {54,38,96,23,15,72,60,45,83};
    int a[9] = {};
    for(int i=0;i<9;i++)
        printf("%d ",a[i]);
    printf("\n");

    QuickSort(a,0,8);

    for(int i=0;i<9;i++)
        printf("%d ",a[i]);
    printf("\n");

}
int main(int argc,char* argv[])
{
    testQuickSort();
    return 0;
}
