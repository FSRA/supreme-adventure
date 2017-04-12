#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

string tobinary(int n) {
    string st = "";
    do {
        st.insert(st.begin(), n % 2 + '0');
        n /= 2;
    } while (n);
    return st;
}

int main(int argc, char* argv[]) {
    int n, m, i;
    string st;

    scanf("%d %d", &m, &n);
    for (i = 1; i <= 255; i++) {
        if (i != m)
            continue;
        st = tobinary(i);
        if (i % 7 == 0 || st.find("111") != string::npos)
            printf("pass\n");
        else
            printf("%s\n", st.c_str());
        m += n;
    }

    return 0;
}
