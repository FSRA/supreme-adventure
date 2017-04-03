#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
        int t=0,i,j,k,m,n,len;
        char a[1001],b[1001],c[1001];

        memset(c,0,sizeof(c));
        scanf("%s %s",a,b);

        m=strlen(a);
        n=strlen(b);

        len=m>n?m:n;

        for(i=m-1,j=n-1,k=len-1;i>=0&&j>=0;j--,i--,k--)
        {
            c[k]=(a[i]-'0'+b[j]-'0'+t)%10+'0';
            t=(a[i]-'0'+b[j]-'0'+t)/10;
        }
        for(;i>=0;i--,k--)
        {
            c[k]=(a[i]-'0'+t)%10+'0';
            t=(a[i]-'0'+t)/10;
        }
        for(;j>=0;j--,k--)
        {
            c[k]=(b[j]-'0'+t)%10+'0';
            t=(b[j]-'0'+t)/10;
        }

        if(t!=0)
        {
            for(k=len-1;k>=0;k--)
                c[k+1]=c[k];
            c[0]=t+'0';
        }

        printf("%s\n",c);
        return 0;
}
