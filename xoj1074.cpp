#include<bits/stdc++.h>
#define maxn 110
#define INF 0x7fffffff//32位int 最大值，符号为0,其余位为1

using namespace std;
int Map[maxn][maxn],dis[maxn],vis[maxn];
int N;

void prim()
{
    memset(vis,0,sizeof(vis));//将vis数组清空
    for(int i=2;i<=N;i++)
    dis[i]=Map[1][i];//dis[i]为第一个节点到各个节点的权值。以i为终点的边的权值

    vis[1]=1;//dis[i]的起点

    int ans=0;

    for(int p=1;p<=N-1;p++)//注意这里只能循环N-1次，因为只用再收进去n-1个点
    {
        int Min=INF;
        int t;
        for(int i=1;i<=N;i++)
        {
            if(!vis[i]&&dis[i]<Min)
            Min=dis[t=i];
        }
        ans+=Min;//第一个最小的权值包含进去

        vis[t]=1;//将t包含进去，以t为头开始做
        for(int i=1;i<=N;i++)
        {
            if(!vis[i]&&dis[i]>Map[t][i])
            dis[i]=Map[t][i];
        }
    }
        printf("%d\n",ans);
}
int main()
{
    while(cin>>N)
    {
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        scanf("%d",&Map[i][j]);//注意可以写成Map[i]+j,直接定位到地址所在的元素
        prim();
    }
    return 0;
}
