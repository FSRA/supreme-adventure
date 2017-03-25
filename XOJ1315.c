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
