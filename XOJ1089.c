#include<stdio.h>
#include<stdlib.h>
#define M 220
#define INF 100000
int n, m, src, des; //src：源点 des：汇点 n：顶点个数
int map[M][M], dep[M];    //dep[i]表示当前点到起点src的层数


int DFS(int u, int minx);

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void InitQueue(LinkQueue* Q)  //建队列
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
}

void EnQueue(LinkQueue* Q, int* e)  //进队列
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = *e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

void DeQueue(LinkQueue* Q, int* e)  //出队列
{
	if (Q->front != Q->rear)
	{
		QNode *p = Q->front->next;
		*e = p->data;
		Q->front->next = p->next;
		if (Q->rear == p)Q->rear = Q->front;
		free(p);
	}
}

int EmptyQueue(LinkQueue* Q)  //判空
{
	if (Q->front == Q->rear)
		return 1;
	return 0;
}

int BFS()  //按层次建图
{
	int e, i, v;
	LinkQueue q;
	InitQueue(&q);
	while (!EmptyQueue(&q))
		DeQueue(&q, &e);
	for (i = 0; i<M; i++)
	{
		dep[i] = -1;
	}
	dep[src] = 0;

	EnQueue(&q, &src);

	while (!EmptyQueue(&q))
	{
		int u;
		DeQueue(&q, &u);
		for (v = 1; v <= m; v++)
		{
			if (map[u][v]>0 && dep[v] == -1)  //可以到达且没有访问
			{
				dep[v] = dep[u] + 1;
				EnQueue(&q, &v);
			}
		}
	}
	return dep[des] != -1;
}


int DFS(int u, int minx)  //查找最小流量
{
	int v;
	if (u == des)
		return minx;
	int tmp;
	for (v = 1; v <= m; v++)
	{
		if (map[u][v]>0 && dep[v] == dep[u] + 1 && (tmp = DFS(v, minx>map[u][v] ? map[u][v] : minx)))
		{
			map[u][v] -= tmp;     //正向减少
			map[v][u] += tmp;     //反向增加
			return tmp;
		}
	}
	return 0;
}

int MaxFlow()
{
	int ans = 0, tmp;
	while (BFS())
	{
		while (1)
		{
			tmp = DFS(1, INF);
			if (tmp == 0)
				break;
			ans += tmp;
		}
	}
	return ans;
}

int main()
{

	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<M; j++)
		{
			map[i][j] = 0;
		}
	}
	int u, v, w;
	for (i = 0; i<n; i++){
		scanf("%d%d%d", &u, &v, &w);
		map[u][v] += w;   //防止有重边
	}
	src = 1;
	des = m;
	printf("%d\n", MaxFlow());
	return 0;
}
