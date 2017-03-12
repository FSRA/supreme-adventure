#include<stdio.h>
#include<stdlib.h>

int dp[1005][1005];

int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}

int main()
{
    int i,j,n,m;
    char a[1005],b[1005];
    for(i=0;i<=1005;i++)
        dp[i][0]=0;
    for(i=0;i<=1005;i++)
        dp[0][i]=0;

    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%c",&a[i]);
    getchar();

    for(i=1;i<=m;i++)
    scanf("%c",&b[i]);
    getchar();

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    printf("%d\n",dp[n][m]);
    return 0;
}
