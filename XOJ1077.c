#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int data;
    int son;
	struct NODE *next;
};
NODE *list[100100];
bool flag[100100];
int queue[1001000];
int distance[100100];
int main()
{
    int a,b,t,n,m,i,x,y;
	NODE *p;
    scanf("%d %d",&n,&m);
	for(i=1;i<n;i++)
		list[i]=NULL;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&t);
		p=(NODE*)malloc(sizeof(NODE));
		p->data=t;
		p->son=b;
		p->next=list[a];
		list[a]=p;
		p=(NODE*)malloc(sizeof(NODE));
		p->data=t;
		p->son=a;
		p->next=list[b];
		list[b]=p;
	}
    for(i=1;i<=n;i++)
	{
		distance[i]=2147483647;
		queue[i]=0;
		flag[i]=false;
	}
	distance[1]=0;
     flag[1]=true;
	  queue[1]=1;
	  x=0;
	  y=1;
	  while(x<y)
	  {
		  ++x;
		  a=queue[x];
          p=list[a];
		  while(p!=NULL)
		  {
			  b=p->son;
			  if(distance[a]+p->data<distance[b])
			  {
				  distance[b]=distance[a]+p->data;
				 if(!flag[b])
				  {
					 flag[b]=true;
					 ++y;
					 queue[y]=b;
                   }
                 }
			  p=p->next;
              }
		  flag[a]=false;
        }
	  if(distance[n]==2147483647)
	  {
		  printf("-1\n");
		  return 0;
       }
	  else
	  {
		  printf("%d\n",distance[n]);
		  return 0;
        }
}
