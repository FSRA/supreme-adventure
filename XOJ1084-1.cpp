#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int a[100001];
int b[100001];

void min_heapify(int i, int k) {
    int mini = i;
    if (i * 2 <= k && a[i * 2] < a[mini])
        mini = i * 2;
    if (i * 2 + 1 <= k && a[i * 2 + 1] < a[mini])
        mini = i * 2 + 1;
    if (mini != i) {
        swap(a[i], a[mini]);
        min_heapify(mini, k);
    }
}

int main(int argc, char* argv[]) {
    int n, m, k, i;

    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (i = k / 2; i >= 1; i--)
        min_heapify(i, k);
    for (i = 1; i < k; i++)
        b[i] = -1;
    b[k] = a[1];
    for (i = k + 1; i <= n; i++) {
        if (a[i] > a[1]) {
            a[1] = a[i];
            min_heapify(1, k);
        }
        b[i] = a[1];
    }

    scanf("%d", &m);
    while (m--) {
        scanf("%d", &i);
        printf("%d %d\n", i, b[i]);
    }

    return 0;
}
