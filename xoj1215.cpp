#include<bits/stdc++.h>
#define INF 0x7FFFFFFF
using namespace std;
 
struct de
{
    int x;
    int y;
    int w;
}a;
 
bool operator < (const de a, const de b)
{
    return a.w> b.w;
}
 
int main()
{
    priority_queue<de> s;
 
    int min[210][210] = {0}, b[210][210] = {0};
    int n, m;
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
            min[i][j] =INF ;
        }
    min[1][2] = b[1][2];
    a.x=1;a.y=2;a.w=b[1][2];
    s.push(a);
    min[2][1] = b[2][1];
    a.x=2;a.y=1;a.w=b[2][1];
    s.push(a);
    while (!s.empty())
    {
        de c = s.top();
        s.pop();
         if (min[c.x - 1][c.y] > min[c.x][c.y] + b[c.x - 1][c.y])
        {
            min[c.x - 1][c.y] = min[c.x][c.y] + b[c.x - 1][c.y];
            a.x=c.x - 1;a.y=c.y;a.w=min[c.x - 1][c.y];
            s.push(a);
        }
        if (min[c.x + 1][c.y] > min[c.x][c.y] +b[c.x + 1][c.y])
        {
            min[c.x + 1][c.y] = min[c.x][c.y] + b[c.x + 1][c.y];
            a.x=c.x + 1;a.y=c.y;a.w=min[c.x +1][c.y];
            s.push(a);
        }
        if (min[c.x][c.y - 1] > min[c.x][c.y] + b[c.x][c.y - 1])
        {
            min[c.x][c.y - 1] = min[c.x][c.y] + b[c.x][c.y - 1];
            a.x=c.x;a.y=c.y-1;a.w=min[c.x][c.y-1];
            s.push(a);
        }
        if (min[c.x][c.y + 1] > min[c.x][c.y] + b[c.x][c.y + 1])
        {
            min[c.x][c.y + 1] = min[c.x][c.y] + b[c.x][c.y + 1];
            a.x=c.x;a.y=c.y+1;a.w=min[c.x][c.y+1];
            s.push(a);
        }
 
    }
    cout << min[n][m]<<endl;
}
