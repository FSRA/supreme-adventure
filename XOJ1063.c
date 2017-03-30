#include<stdio.h>
#include<limits.h>

int n;  //城市总数
int x[13];  //城市
int w[13][13];  //边
int cw=0;  //当前已构造路径权和
int bestw=INT_MAX,bestx[13];  //最优长度和最优边序列

int min(int i)
{
	int j,k,m,sum=0;
	for(j=i-1;j<=n;j++)
	{
		if(w[x[j]][1]!=0)
		m=w[x[j]][1];
		else
		m=w[x[j]][2];
		for(k=2;k<=n;k++)
		{
			if(w[x[j]][k]!=0&&m>w[x[j]][k])
			m=w[x[j]][k];

		}
		sum=sum+m;
	}
	return sum;
}

int best(int i)
{
	int p;
	p=cw+min(i);
	return p;
}
void BacktrackTSP(int i)
{
	int j,t;
	if(i==n)
	{
		if(w[x[n-1]][x[n]]!=0 && w[x[n]][1]!=0)
		{
			if(cw+w[x[n-1]][x[n]]+w[x[n]][1]<bestw)
			{
				bestw=cw+w[x[n-1]][x[n]]+w[x[n]][1];
				for(j=1;j<=n;j++)
				{
					bestx[j]=x[j];
				}
			}
		}
	}
	else
	{
		for(j=i;j<=n;j++)
		{
			if(w[x[i-1]][x[j]]!=0 && best(i)<bestw)
			{
				t=x[i];x[i]=x[j];x[j]=t;
				cw=cw+w[x[i-1]][x[i]];
				BacktrackTSP(i+1);
				cw=cw-w[x[i-1]][x[i]];
				t=x[i];x[i]=x[j];x[j]=t;
			}
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		x[i]=i;
	}
        BacktrackTSP(2);
		printf("%d",bestw);
		return 0;
}
