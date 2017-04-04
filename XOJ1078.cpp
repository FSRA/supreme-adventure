#include<bits/stdc++.h>
#define inf 0x2fffffff
using namespace std;
int a[100][100];
int n;

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

int main(int argc,char*argv[])
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
       {    scanf("%d",&a[i][j]);//读入本来的数据
            if(i==j)
            a[i][j]=0;//如果是自己对自己，则初始化为0
            else if(a[i][j]==0)
            a[i][j]=inf;//如果某两个不可达，则初始化为无穷大
       }
    }
    printf("%d\n",func());
    return 0;
}
