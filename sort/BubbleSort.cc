#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[],int n) {
    int bound = n - 1;
    int exchange = n - 1;
    while(exchange) {
        exchange = 0;
        for(int i = 0;i < bound; i++) {
            if(a[i+1] < a[i]) {
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                exchange = i+1;
            }
        }
        bound = exchange;
    }
}

void testBubbleSort() {
    int a[10]={10,9,8,7,6,5,4,3,2,1};
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    BubbleSort(a,10);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(int argc,char* argv[]) {
    testBubbleSort();
}
