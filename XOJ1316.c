#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    double w;
    double v;
}kache;

int partition(kache k[],int p,int r)
{
    int i,j;
    double x,temp;
    x=k[r].v/k[r].w;
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(k[j].v/k[j].w>x)
        {
            i=i+1;
            temp=k[i].v;
            k[i].v=k[j].v;
            k[j].v=temp;
            temp=k[i].w;
            k[i].w=k[j].w;
            k[j].w=temp;
        }
    }
    temp=k[i+1].v;
    k[i+1].v=k[r].v;
    k[r].v=temp;
    temp=k[i+1].w;
    k[i+1].w=k[r].w;
    k[r].w=temp;
    return i+1;
}

void Quicksort(kache k[],int low,int high)
{
    if(low>high) return;
    int m=partition(k,low,high);
    Quicksort(k,low,m-1);
    Quicksort(k,m+1,high);
}
int main()
{
    int N,i,j;
    double temp,count=0,M,we,x;
    kache*k;
    scanf("%lf%d",&M,&N);
    k=(kache*)malloc(sizeof(kache)*(N+1));
    for(i=1;i<=N;i++)
    {
        scanf("%lf%lf",&k[i].w,&k[i].v);
    }
    Quicksort(k,1,N);

    we=M;
    i=1;
    while(we>0&&i<=N)//包里还有空，并且还有货物没有考虑过
    {
        if(we/k[i].w<1)
        x=we/k[i].w;//（0）
        else x=1;//有几个k[i]

        we=we-k[i].w*x;
        count=count+k[i].v*x;
        i=i+1;
    }
    printf("%.6f\n",count);
    return 0;
}
