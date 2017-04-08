
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char* c = "10X98765432";
int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

bool is_leap(int y) {
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return true;
    return false;
}

bool check_birth(int y, int m, int d) {
    if (m < 1 || m > 12)
        return false;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 1 <= d && d <= 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 1 <= d && d <= 30;
    else if (is_leap(y))
        return 1 <= d && d <= 29;
    else
        return 1 <= d && d <= 28;
}

bool check(string st) {
    int y = atoi(st.substr(6, 4).c_str());
    int m = atoi(st.substr(10, 2).c_str());
    int d = atoi(st.substr(12, 2).c_str());
    if (!check_birth(y, m, d))
        return false;
    int s = 0;
    for (int i = 0; i < 17; i++)
        s += w[i] * (st[i] - '0');
    return st[17] == c[s % 11];
}

int main(int argc, char* argv[]) {
    int cas;
    char s[19];

    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", s);
        printf("%s\n", check(s) ? "yes" : "no");
    }

    return 0;
}
