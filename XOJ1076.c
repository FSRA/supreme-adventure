#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
struct edge
{
    int u,v,w;
    bool operator<(const edge&a)const
    {
        return w<a.w;//从大到小排序
    }
}E[maxn*2];

int N,M,pre[maxn];

int find(int x)//并查集
{
    int t=x;
    while(pre[t]!=t)
    t=pre[t];
    while(x!=t)
    pre[x]=t,x=pre[x];
    return t;
}

void Kruscal()//生成最小树
{
    int cnt=1,ans=0;
    for(int i=1;i<=N;i++)
    pre[i]=i;//初始代表元为自己
    for(int i=0;i<M;i++)
    {
        int u=E[i].u,v=E[i].v,w=E[i].w;
        int fu=find(u),fv=find(v);//查找
        if(fu==fv) continue;
        ans+=w;
        pre[fu]=fv;
        if(++cnt==N)
        break;
    }
    printf("%d\n",cnt==N?ans:-1);
}

int main()
{
    while(cin>>N>>M)//先输入N,再输入M
    {
        for(int i=0;i<M;i++)
            scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
        sort(E,E+M);//按照权值由大到小排列
        Kruscal();
    }
    return 0;
}
