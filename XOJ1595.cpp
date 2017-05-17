


  #include<iostream>
#include<algorithm>
   #include<string>
   #include<iomanip>
   #include<memory.h>
   #include<time.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
 #include<stdbool.h>
 #include<math.h>
 #define min(a,b) ((a)<(b)?(a):(b))
 #define max(a,b) ((a)>(b)?(a):(b))
 #define abs(a) ((a)>0?(a):(-(a)))
 #define lowbit(a) (a&(-a))
 #define sqr(a) ((a)*(a))
  #define swap(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
 #define eps 1e-8
  #define J 10
 #define MAX 0x7f7f7f7f
 #define PI 3.1415926535897
 #define inf 10000000
 #define N 504
  #define M 50004
 using namespace std;
  int n,m,lll,ans,cas;
  int nn,fl,s,t;
  int last[N],d[N],vd[N];
  struct xxx
  {
     int next,e,q;
  }a[M];
 void add(int x,int y,int z)
  {
      a[++lll].next=last[x];
      a[lll].e=y;
      a[lll].q=z;
      last[x]=lll;
  }
  int sap(int u,int f)
  {
      int i,v,tt,asp=0,mix=nn-1;
      if(u==t)return f;
      for(i=last[u];i!=0;i=a[i].next)
      {
          v=a[i].e;
          if(a[i].q>0)
          {
              if(d[u]==d[v]+1)
              {
                  tt=sap(v,min(f-asp,a[i].q));
                  asp+=tt;
                  a[i].q-=tt;
                  a[i^1].q+=tt;
                  if(asp==f || d[s]==nn)
                     return asp;
             }
              mix=min(mix,d[v]);
          }
      }
      if(asp!=0)return asp;
      if(!--vd[d[u]])d[s]=nn;
      else vd[d[u]=mix+1]++;
      return asp;
  }
  void build()
 {
     int i,j,x,y,z;
     s=100+200+1;t=100+200+2;
     nn=0;
      for(i=1;i<=n;i++)
      {
         scanf("%d%d%d",&x,&y,&z);
          fl+=x;nn=max(nn,z);
          add(s,i,x);add(i,s,0);
         for(j=y;j<z;j++)
         {
              add(i,n+j,1);add(n+j,i,0);
          }
      }
      for(i=1;i<=nn;i++)
      {
          add(n+i,t,m);add(t,n+i,0);
     }
      nn+=n+2;
      vd[0]=nn;
  }
  int main()
  {
      #ifndef ONLINE_JUDGE
 //    freopen("1.txt","r",stdin);
 //    freopen("2.txt","w",stdout);
      #endif
      int l,f;
  //    while(~scanf("%s",s1))
  //    while(~scanf("%d",&n))
     for(scanf("%d",&cas),l=1;l<=cas;l++)
     {
         fl=ans=0;lll=1;
         memset(d,0,sizeof(d));
         memset(vd,0,sizeof(vd));
         memset(last,0,sizeof(last));
         scanf("%d%d",&n,&m);
         build();
         while(d[s]<nn)
        {
             f=sap(s,MAX);
             ans+=f;
         }
         if(ans==fl)puts("Yes");
         else puts("No");
     }
    return 0;
 }
