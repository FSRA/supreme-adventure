#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int a[205];
int dp[205][205];

int dpmatrix(int n)
{
    int c,i,j,k,q;
    for(c=2;c<=n;c++)
        for(i=1;i<=n-c+1;i++)
        {
            j=i+c-1;
            for(k=i;k<=j-1;k++)
            {
                q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<dp[i][j])
                    dp[i][j]=q;
            }
        }
    return dp[1][n];
}
int main()
{
    int n,i,j,time;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<205;i++)
        for(j=0;j<205;j++)
        dp[i][j]=INT_MAX;
    for(i=0;i<205;i++)
        dp[i][i]=0;
    time=dpmatrix(n);
    printf("%d",time);
    return 0;
}
