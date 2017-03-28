#include<stdio.h>
#include<stdlib.h>

void huisu(int l);
int place(int l,int hl); //hl=h[l]

int  n,h[14];
int  solnum;
int   t=1;
int  b[20];

int main()
{
    int i;
    scanf("%d",&n);
    solnum=0;//一共solunum种
    huisu(1);//从第一行开始回溯
    printf("%d\n",solnum);
    for(i=1;i<=n;i++)
			printf("%d %d\n",i,b[i]);//输出每一行i，与b[i]第i行的棋子列数
    return 0;
}

void huisu(int l)
{
    int i;
    if(l==n+1)//如果要放的行数已经超过n行，即前面n行已经全部放完
    {
    solnum=solnum+1;//总数+1
    }
    if (l==n+1&&t==1)//如果已经前面已经放完，并且没有记录过
    {
		for(i=1;i<=n;i++)//每一行记录h[i]保存到b[i]中记录下来
			b[i]=h[i];
			t=0;//标记放置空，表示已经记录过
    }
    for (i=1;i<=n;i++)//试探l行以及l行以后能放的位置
    {
        h[l]=i;
        if (place(l,i))
			huisu(l+1);
    }
}

int place(int l,int hl) //l行hl列能否放置棋子
{
	int k;
	for (k=1;k<l;k++)//对于已经放过棋子的每一行
		if (abs(l-k)==abs(h[k]-hl)||hl==h[k])//如果对角线有，并且列上也有
			return 0;//则不行
		return 1;//则可以
}
