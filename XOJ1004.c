#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int data[1000005];
int partition(int data[],int low,int high)
{
    int t;
    t=data[low];
    while(low<high)
    {
    while(low<high&&data[high]>=t)
        high--;
    data[low]=data[high];
    while(low<high&&data[low]<=t)
        low++;
    data[high]=data[low];
    }
    data[low]=t;
    return low;
}

void sort(int data[],int low,int high)
{
    if(low>high) return;
    int m=partition(data,low,high);
    partition(data,low,m-1);
    partition(data,m+1,high);
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&data[i]);
    sort(data,1,n);
    for(i=1;i<=n;i++)
    printf("%d ",data[i]);
    return 0;
}
