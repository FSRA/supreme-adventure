#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
	int lena,lenb,i,j,k,t=0;
	char a[100500],b[100500];
	int aa[100500],bb[100500],c[200500];
	memset(c,0,sizeof(c));

	scanf("%s %s",a,b);
	lena=strlen(a);
	lenb=strlen(b);

	c[lena+lenb]=10000;

	for(i=0;i<lena;i++)
		aa[i]=a[i]-'0';
	for(i=0;i<lenb;i++)
		bb[i]=b[i]-'0';

	for(i=0;i<lena;i++)
	{
		for(j=0;j<lenb;j++)
		{
			c[i+j+1]+=aa[i]*bb[j];//b*a
		}
	}

	for(k=lena+lenb-1;k>0;k--)
	{
		c[k-1]+=(c[k]/10);
		c[k]=c[k]%10;
	}

	if(c[0]==0)
		t++;
	while(c[t]==0&&c[t+1]==0)
		t++;//跳过头部为0元素
	for(i=t;i<lena+lenb;i++)
		printf("%d",c[i]);
	return 0;
}
