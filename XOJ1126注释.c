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
        scanf("%d",&h[i]);
        
    a[1]=h[1];
    for(i=2;i<=n;i++)
        a[i]=max(a[i-1],h[i]);//从左到右找最高的轮廓
        
    b[n]=h[n];
    for(i=n-1;i>=1;i--)
        b[i]=max(b[i+1],h[i]);//从右到左找最高的轮廓
        
    for(i=2;i<n;i++)
    {
        minh=min(a[i-1],b[i+1]);//取外沿的轮廓
        if(minh>h[i])//如果大于高度，则减去剩余余量为所求的余量积水高度
            ans+=minh-h[i];
    }
    printf("%d\n",ans);
    return 0;
}
