#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insert_sort(int a[],int n)//直接插入排序
{
    int i,j,temp;
    for(i=2;i<=n;i++)
    {
        temp=a[i];
        j=i-1;//与前面的1~i-1个元素比较
        while(j>0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }//比temp大的往后移一位，再往前1个数来比较
        a[j+1]=temp;
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int a[N+1];
    int i;
    for(i=1;i<=N;i++)
    {scanf("%d",&a[i]);}
    insert_sort(a,N);
    for(i=1;i<=N;i++)
    {printf("%d ",a[i]);}
    return 0;
}
