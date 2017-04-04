#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N1 1001
char name[N1][16],yue[N1][16];
int start[N1][2],end[N1][2],s[N1],f[N1];

void SelectSort(int n)
{
    int i,j,temp,k;
    char str[16];
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(f[k]>f[j])
            k=j;
        }
        if(k!=i)
        {
            temp=f[k];
            f[k]=f[i];
            f[i]=temp;

            temp=s[k];
            s[k]=s[i];
            s[i]=temp;

            strcpy(str,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],str);
        }
    }
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
    SelectSort(N);
    t=GreedySelect(N);
    printf("%d\n",t);
    for(i=0;i<t-1;i++)
        printf("%s ",yue[i]);
    printf("%s",yue[i]);
    return 0;
}
