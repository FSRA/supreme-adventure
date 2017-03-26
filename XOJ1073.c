#include<bits/stdc++.h>

using namespace std;
#define maxn 510
char name[maxn][50];
int Map[maxn][maxn],deg[maxn],vis[maxn];
int N;

void top_sort()//拓扑排序
{
    queue<int> Q;
    memset(vis,0,sizeof(vis));
    
    for(int i=1;i<=N;i++)
    {
        if(!deg[i])//i课程无先修课程
        Q.push(i),vis[i]=1;//push入队，记vis[i]=1
    }
    vector<int> ans;//先存储下来，因为有可能Impossible

    while(!Q.empty())
    {
        int tp=Q.front();
        Q.pop();
        
        ans.push_back(tp);//弹出一个实体tp
        
        for(int i=1;i<=N;i++)
            if(!vis[i]&&Map[tp][i])//哪一个先修是tp的i课并且vis[i]=0,没有入队的话
                if(--deg[i]==0)//并且他的先修只有一个tp的话
                
                Q.push(i),//入队再设vis=1
                vis[i]=1;
    }
    if((int)ans.size()<N)
    {
        printf("Impossible!\n");
        return;
    }
    for(int i=0;i<ans.size();i++)
    printf("%s%c",name[ans[i]],i+1==ans.size()?'\n':' ');
}

int main()
{
    while(cin>>N)
    {
        for(int i=1;i<=N;i++)
            scanf("%s",name[i]);
        memset(Map,0,sizeof(Map));
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=N;i++)
        {
            int t,a;
            scanf("%d",&t);
            deg[i]=t;//dag用来存每个课程先修课程的数目
            while(t--)
            {
                scanf("%d",&a);
                Map[a][i]=1;//map标记第i列第a行的先修课程为1，a为其先修课程的标号
            }
        }
        top_sort();
    }
    return 0;
}
