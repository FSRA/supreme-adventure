#include<stdio.h>
#include<stdlib.h>
#define MAX 130
int maxSum(int b[],int n)//最大字段和函数
{
    int i,sum=0,res=-9999;
    for(i=1;i<=n;i++)
    {
        sum+=b[i];
        if(sum>res)
        res=sum;
        if(sum<0)
        sum=0;
    }
    return res;
}

int solve(int a[][MAX],int n)//传参不能写成a[][]
{
    int i,j,k,b[MAX],result=0;
    for(i=1;i<=n;i++)//从i行到j行 k列的和，注意理解循环变量顺序
    {
        for(k=1;k<=n;k++) b[k]=0;
        for(j=i;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                b[k]+=a[j][k];
                if(maxSum(b,k)>=result)
                result=maxSum(b,k);
            }

        }
    }
    return result;
}

int main()
{
    int n,i,j,a[MAX][MAX];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);

    printf("%d",solve(a,n));
    return 0;
}
