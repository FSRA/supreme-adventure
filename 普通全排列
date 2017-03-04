普通全排列，实现课本p37 固定位置放元素
#include<stdio.h>
#include<stdlib.h>
int list[9];

void swap(int*a,int*b)
{
    int m;
    m=*a;
    *a=*b;
    *b=m;
}

void perm(int list[],int p,int q)
{
    int i;
    if(p>q)
    {
        for(i=0;i<q;i++)
        printf("%d ",list[i]);
        printf("%d",list[q]);
        printf("\n");
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            swap(&list[p],&list[i]);
            perm(list,p+1,q);
            swap(&list[p],&list[i]);
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    list[i]=i+1;
    perm(list,0,n-1);
    return 0;
}
