#include<stdio.h>
#include<stdlib.h>
#define MAX 130
int maxSum(int b[],int n)
{
    int max=b[1];
    int sum=0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(sum<0) sum=b[i];
        else sum+=b[i];
        if(sum>max) max=sum;
    }
    return max;
}

int solve(int a[][MAX],int n)
{
    int i,j,k,b[MAX];
    int result=a[1][1];
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n;k++) b[k]=0;
        for(j=i;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            b[k]+=a[j][k];
            if(maxSum(b,n)>result) result=maxSum(b,n);
        }
    }
    return result;
}

int main()
{
    int i,j,n,a[MAX][MAX];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    }
    printf("%d\n",solve(a,n));
    return 0;
}
