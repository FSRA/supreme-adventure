#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//int main()
//{
//    int n,i,j;
//    scanf("%d",&n);
//    for(i=1;i<=n;i++)
//        {for(j=1;j<=n-i;j++) printf("  ");
//        for(j=i;j>=1;j--) printf("%d ",j);
//        for(j=2;j<=i;j++) printf("%d ",j);
//        printf("\n");}
//    return 0;
//}
//int main()
//{
//    int i,j;
//    double p=0.0;
//    scanf("%d",&i);
//    for(j=1;j<=i;j++)
//   {
//       p+=(pow(-1,j+1))/(2*j-1);
//    }
//    printf("%lf\n",4*p);
//    return 0;
//}
int prime(int n)
{
    int a=sqrt(n),i;
    for(i=2;i<=a;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int cir(int n)
{
    int a[100],length=0,i;
    while(n>0)
    {
        a[++length]=n%10;
        n=n/10;
    }
    for(i=1;i<=length/2;i++)
    {
        if(a[i]!=a[length-i+1])
        return 0;
    }
    return 1;
}
int main()
{
    int i=0,count=0,num=2;
    while(i<100)
    {
        if(prime(num)&&cir(num))
        {
            printf("%d ",num);
            i++;
            count++;
        }
        num++;
        if(count==10)
        {
            printf("\n");
            count=0;
        }

    }
    return 0;
}
