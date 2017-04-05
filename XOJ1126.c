#include<stdio.h>
#include<stdlib.h>

int a[5001];
int b[5001];
int h[5001];

int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int n,ans=0;
    int minh;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",h+i);
    a[1]=h[1];
    for(i=2;i<=n;i++)
        a[i]=max(a[i-1],h[i]);
    b[n]=h[n];
    for(i=n-1;i>=1;i--)
        b[i]=max(b[i+1],h[i]);
    for(i=2;i<n;i++)
    {
        minh=min(a[i-1],b[i+1]);
        if(minh>h[i])
            ans+=minh-h[i];
    }
    printf("%d\n",ans);
    return 0;
}
