#include<bits/stdc++.h>
const int N=100000+3;
const int M=200000+3;
using namespace std;

int n,m,ans,cnt;
int fa[N];

struct st
{
    int x,y,z;
}e[M];

bool cmp(st t1,st t2)
{
    return t1.z<t2.z;//应该是从小到大排序
}
int getfa(int id)
{
    return fa[id]==id?id:fa[id]=getfa(fa[id]);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    sort(e+1,e+m+1,cmp);

    cnt=1;
    for(int i=1;i<=m&&cnt<n;++i)
    {
        int a=getfa(e[i].x);
        int b=getfa(e[i].y);
        if(a!=b)
        {
            ++cnt;
            ans+=e[i].z;
            fa[a]=b;
        }
    }
    printf("%d\n",cnt==n?ans:-1);
    return 0;
}
