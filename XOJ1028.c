#include<stdio.h>
#include<stdlib.h>

int dp[1005][8200];

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int n,m,i,j,t,out[1005];
    int v[1005],c[1005];
    for(i=0;i<1005;i++)
        dp[i][0]=0;
    for(i=0;i<8200;i++)
        dp[0][i]=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(i=1;i<=n;i++)
        for(j=m;j>=0;j--)
    {
        dp[i][j]=dp[i-1][j];
        if(j>=c[i])
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+v[i]);
    }
    i=n;j=m;t=0;
    while(i>0)
    {
        if(j-c[i]>=0&&dp[i][j]==dp[i-1][j-c[i]]+v[i])
        {
            out[t]=i;
            j-=c[i];
            t++;
        }
        i--;
    }
    printf("%d\n",t);
    for(i=t-1;i>0;i--)
        printf("%d ",out[i]);
    printf("%d\n",out[i]);
    return 0;
}
