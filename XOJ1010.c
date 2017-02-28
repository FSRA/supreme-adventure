#include <stdio.h>
#include <stdlib.h>

int a[1005][1005];
int dp[1005][1005];

int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int main()
{
    int i,j,n,res=0;

    for(i=0;i<1004;i++)
    for(j=0;j<1004;j++)
    dp[i][j]=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    for(j=0;j<=i;j++)
    scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
    for(j=0;j<=i;j++)
    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];

    for(i=0;i<n;i++)
    {if(dp[n-1][i]>res) res=dp[n-1][i];}

    printf("%d",res);
    return 0;
    }
