#include<stdio.h>
#include<stdlib.h>
#define inf 0x2fffffff
int a[100][100];
int n;

int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a>b?b:a;
}
int func()
{
    int i,j,k;
    int ans=0;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==inf)
            return -1;
            ans=max(ans,a[i][j]);
        }
    }
    return ans-1;

}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(i==j)
            a[i][j]=0;
            else if(a[i][j]==0)
            a[i][j]=inf;
        }
    }
    printf("%d",func());
    return 0;
}
