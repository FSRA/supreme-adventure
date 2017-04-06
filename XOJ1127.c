#include<stdio.h>
#include<stdlib.h>
#define inf 0x3fffffff

int f[101][101];
int w[101][101];
int t[101];
int n,m,r;


int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}

int partition(int t[],int low,int high)
{
    int temp,mid;
    mid=(high+low)/2;

    temp=t[mid];
    t[mid]=t[low];
    t[low]=temp;

    while(low<high)
    {
        while(low<high&&t[high]>=temp)
        high--;
        t[low]=t[high];
        while(low<high&&t[low]<=temp)
        low++;
        t[high]=t[low];
    }
    t[low]=temp;
    return low;
}

void sort(int t[],int low,int high)
{
    if(low>high) return;
    int m=partition(t,low,high);
    sort(t,low,m-1);
    sort(t,m+1,high);
}

int dyna()
{
    int i,j,k,tmp;
    sort(t,1,n);

    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            for(k=i;t[j]-t[k]>r;k++)
            w[i][j]+=t[j]-t[k]-r;

    for(i=1;i<=n;i++)
        f[i][1]=w[1][i];

    for(j=2;j<=m;j++)
    {
        for(i=j;i<=n;i++)
        {
            f[i][j]=inf;
            for(k=j-1;k<i;k++)
            {
                tmp=f[k][j-1]+w[k+1][i];
                f[i][j]=min(f[i][j],tmp);
            }
        }
    }
    return f[n][m];
}


int main()
{
    int i;
    scanf("%d%d%d",&n,&m,&r);
    for(i=1;i<=n;i++)
        scanf("%d",&t[i]);
        
    printf("%d\n",dyna());
    return 0;
}
