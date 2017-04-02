#include<bits/stdc++.h>
#define maxn 110
#define INF 0x7fffffff

using namespace std;

int Map[maxn][maxn],vis[maxn],dis[maxn];
int N;

void SPFA(){//最短路算法
    queue<int> Q;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=N;i++) dis[i]=INF;
    Q.push(1);vis[1]=1;dis[1]=0;
    while(!Q.empty()){
        int tp=Q.front();Q.pop();vis[tp]=0;
        for(int i=1;i<=N;i++){
            if(Map[tp][i]+dis[tp]>=dis[i]) continue;
            dis[i]=dis[tp]+Map[tp][i];
            if(!vis[i]) {Q.push(i);vis[i]=1;}
        }
    }
    printf("%d\n",dis[N]);
}


int main(){
    while(cin>>N){
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
            scanf("%d",Map[i]+j);
        SPFA();
    }
    return 0;
}

