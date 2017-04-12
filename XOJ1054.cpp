
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n, nr, cas = 1;
    char s[16], t[16];

    scanf("%d", &n);
    while (n) {
        nr = 0;
        while (n--) {
            scanf("%s", s);
            if (!nr) {
                strcpy(t, s);
                nr = 1;
            } else {
                nr += strcmp(s, t) ? -1 : 1;
            }
        }
        printf("Case %d:\n", cas++);
        printf("%s\n", t);
        scanf("%d", &n);
    }

    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int n, nr, cas = 1;
    char s[16], t[16];

    scanf("%d", &n);
    while (n) {
        nr = 0;
        while (n--) {
            scanf("%s", s);
            if (!nr) {
                strcpy(t, s);
                nr = 1;
            } else {
                nr += strcmp(s, t) ? -1 : 1;
            }
        }
        printf("Case %d:\n", cas++);
        printf("%s\n", t);
        scanf("%d", &n);
    }

    return 0;
}
