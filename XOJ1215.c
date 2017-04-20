#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int M1;
int min(int a,int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
void find(int ex,int ey,int com[][M1],int L[][M1],int fx,int fy)
{


    if((ex+1<fx)&&(L[ex][ey]+com[ex+1][ey]<L[ex+1][ey]))//向下
    {
        L[ex+1][ey]=com[ex+1][ey]+L[ex][ey];
        find(ex+1,ey,com,L,fx,fy);

    }

    if((ex-1>=0)&&(L[ex][ey]+com[ex-1][ey]<L[ex-1][ey]))//向上
    {
        L[ex-1][ey]=com[ex-1][ey]+L[ex][ey];
        find(ex-1,ey,com,L,fx,fy);
    }

    if((ey+1<fy)&&(L[ex][ey]+com[ex][ey+1]<L[ex][ey+1]))//向右
    {
        L[ex][ey+1]=com[ex][ey+1]+L[ex][ey];
        find(ex,ey+1,com,L,fx,fy);
    }


    if((ey-1>=0)&&(L[ex][ey]+com[ex][ey-1]<L[ex][ey-1]))//向左
    {
        L[ex][ey-1]=com[ex][ey-1]+L[ex][ey];
        find(ex,ey-1,com,L,fx,fy);
    }

}
int main()
{
    int N,M,i,j;
    scanf("%d %d",&N,&M);
    int com[N][M];
    int L[N][M];

    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        {
           scanf("%d",&com[i][j]);
           L[i][j]=INT_MAX;
        }

     L[0][0]=0;
     M1=M;

     for(i=0;i<N;i++)
     {
         for(j=0;j<M;j++)
         {
             if(i-1>=0)
             {
                 if(j-1>=0)
                    L[i][j]=min((L[i-1][j]+com[i][j]),(L[i][j-1]+com[i][j]));
                 else
                    L[i][j]=L[i-1][j]+com[i][j];
             }
             else if(j-1>=0)
                   L[i][j]=L[i][j-1]+com[i][j];

             if(i+1<N)
                 find(i,j,com,L,i+1,M);
             else if((i+1)>=N)
                 find(i,j,com,L,N,M);
         }
     }
     printf("%d",L[N-1][M-1]);
     return 0;
}
