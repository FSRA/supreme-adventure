#include<stdio.h>
#include<stdlib.h>

int a[101][101],b[101][101],c[101][101];

int main()
{
    int n1,m1,n2,m2,i,j,k;

    scanf("%d %d",&n1,&m1);
    for(i=0;i<n1;i++)
     for(j=0;j<m1;j++)
     scanf("%d",&a[i][j]);
    scanf("%d %d",&n2,&m2);
    for(i=0;i<n2;i++)
     for(j=0;j<m2;j++)
     scanf("%d",&b[i][j]);

     for(i=0;i<n1;i++)
     for(j=0;j<m2;j++)
     c[i][j]=0;

     for(i=0;i<n1;i++)
     for(j=0;j<m2;j++)
     for(k=0;k<m1;k++)
        c[i][j]+=a[i][k]*b[k][j];

     for(i=0;i<n1;i++)
     {
       for(j=0;j<m2-1;j++)
         printf("%d ",c[i][j]);
       printf("%d",c[i][m2-1]);
       if(i!=n1-1) printf("\n");}


     return 0;
}
