#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N1 1001
char name[N1][16],yue[N1][16];
int start[N1][2],end[N1][2],s[N1],f[N1];

int partition(int f[],int low,int high)
{
    int t,mid;
    mid=(high+low)/2;
    t=f[mid];
    f[mid]=f[low];
    f[low]=t;

    while(low<high)
    {
        while(low<high&&f[high]>=t)
            high--;
        f[low]=f[high];
        while(low<high&&f[low]<=t)
            low++;
        f[high]=f[low];
    }
    f[low]=t;
    return low;
}

void sort(int f[],int low,int high)
{
    if(low>high) return;
    int m=partition(f,low,high);
    sort(f,low,m-1);
    sort(f,m+1,high);
}

int GreedySelect(int n)
{
    int i=0,m,j=1;
    strcpy(yue[0],name[0]);
    for(m=1;m<n;m++)
    {
        if(s[m]>=f[i])
        {
            strcpy(yue[j],name[m]);
            j++;
            i=m;
        }
    }
    return j;
}


int main()
{
    int N,i,t;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",name[i]);
        scanf("%d:%d",&start[i][0],&start[i][1]);
        s[i]=start[i][0]*60+start[i][1];
        scanf("%d:%d",&end[i][0],&end[i][1]);
        f[i]=end[i][0]*60+end[i][1];
    }
    sort(f,0,N-1);
    t=GreedySelect(N);
    printf("%d\n",t);
    for(i=0;i<t-1;i++)
        printf("%s ",yue[i]);
    printf("%s",yue[i]);
    return 0;
}
