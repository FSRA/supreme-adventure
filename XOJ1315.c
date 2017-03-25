STL容器之优先队列

优先级队列，以前刷题的时候用的比较熟，现在竟然我只能记得它的关键字是priority_queue(太伤了)。在一些定义了权重的地方这个数据结构是很有用的。

先回顾队列的定义：队列(queue)维护了一组对象，进入队列的对象被放置在尾部，下一个被取出的元素则取自队列的首部。priority_queue特别之处在于，允许用户为队列中存储的元素设置优先级。这种队列不是直接将新元素放置在队列尾部，而是放在比它优先级低的元素前面。标准库默认使用<操作符来确定对象之间的优先级关系，所以如果要使用自定义对象，需要重载 < 操作符。

优先队列有两种，一种是最大优先队列；一种是最小优先队列；每次取自队列的第一个元素分别是优先级最大和优先级最小的元素。

1) 优先队列的定义

包含头文件："queue.h", "functional.h"

可以使用具有默认优先级的已有数据结构；也可以再定义优先队列的时候传入自定义的优先级比较对象；或者使用自定义对象(数据结构)，但是必须重载好< 操作符。 

2) 优先队列的常用操作

优先级队列支持的操作
q.empty()         如果队列为空，则返回true，否则返回false

q.size()            返回队列中元素的个数

q.pop()             删除队首元素，但不返回其值

q.top()             返回具有最高优先级的元素值，但不删除该元素

q.push(item)     在基于优先级的适当位置插入新元素

其中q.top()为查找操作，在最小优先队列中搜索优先权最小的元素，在最大优先队列中搜索优先权最大的元素。q.pop()为删除该元素。优先队列插入和删除元素的复杂度都是O(lgn)，所以很快

另外，在优先队列中，元素可以具有相同的优先权。

另外优先队列priority_queue是STL库中的,包含在头文件<queue>中,会自动对新放入队列的数据进行排序,这里采用的是队头数最小的排序方式.每次取出前两个(也就是权值最小的两节点)构成新的节点,再放入队列中,直到取到最后一个为止,这也符合HUFFMAN树的构造过程..


#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct cmp
{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

int main()
{
    char a[100005];
    int upper[26],lower[26],res=0;
    memset(upper,0,sizeof(upper));
    memset(lower,0,sizeof(lower));
    scanf("%s",a);
    for(unsigned int i=0;i<strlen(a);i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
            upper[a[i]-'A']++;
        else
            lower[a[i]-'a']++;
    }
    priority_queue<int,vector<int>,cmp> pq;
    for(int i=0;i<26;i++)
    {
        if(upper[i])
            pq.push(upper[i]);
        if(lower[i])
            pq.push(lower[i]);
    }
    if(pq.size()==1)
        res=pq.top();
    while(pq.size()>1)
    {
        int t1=pq.top();
        pq.pop();
        int t2=pq.top();
        pq.pop();
        res+=t1+t2;
        pq.push(t1+t2);
    }
    printf("%d\n",res);
    return 0;
}
