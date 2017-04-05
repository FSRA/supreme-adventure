#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int p[50001];
int r[50001];

int find(int u) {
    int y = u;
    int z = u;
    int w;
    while (p[y] != 0)
        y = p[y];
    while (p[z] != 0) {
        w = p[z];
        p[z] = y;
        z = w;
    }
    return y;
}

void unio(int u, int v) {
    if (r[u] >= r[v]) {
        p[v] = u;
        if (r[u] == r[v])
            r[u]++;
        return;
    }
    p[u] = v;
}

int main(int argc, char* argv[]) {
    int n, m, q;
    int u, v;
    char ch;

    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        u = find(u);
        v = find(v);
        if (u != v)
            unio(u, v);
    }

    scanf("%d", &q);
    while (q--) {
        scanf(" %c %d %d", &ch, &u, &v);
        u = find(u);
        v = find(v);
        if (ch == 'Q')
            printf("%s\n", u == v ? "yes" : "no");
        else if (u != v)
            unio(u, v);
    }

    return 0;
}
