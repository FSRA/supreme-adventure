#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,a[7],sum=1000,num=0;
    scanf("%d",&n);
    for(i=1;i<=6;i++)
    scanf("%d",&a[i]);
    sum-=n*25;
    while(sum>=500&&a[1])
    {
        sum-=500;
        num++;
        a[1]--;
    }
    while(sum>=100&&a[2])
    {
        sum-=100;
        num++;
        a[2]--;
    }
    while(sum>=50&&a[3])
    {
        sum-=50;
        num++;
        a[3]--;
    }
    while(sum>=10&&a[4])
    {
        sum-=10;
        num++;
        a[4]--;
    }
    while(sum>=5&&a[5])
    {
        sum-=5;
        num++;
        a[5]--;
    }
    while(sum>=1&&a[6])
    {
        sum-=1;
        num++;
        a[6]--;
    }
    if(sum) printf("-1\n");
    else printf("%d\n",num);
    return 0;
}
