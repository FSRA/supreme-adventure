#include<stdio.h>
#include<stdlib.h>

char s[16][17];

int main()
 {
    int n, m, i, j;
    char ch = '1';

    scanf("%d %d", &n, &m);
    int si = 0;
    int ei = n - 1;
    int sj = 0;
    int ej = m - 1;
    while (si <= ei && sj <= ej) 
    {
        for (i = si; i <= ei; i++) 
        {
            s[i][sj] = ch;
            s[i][ej] = ch;
        }
        for (j = sj; j <= ej; j++) 
        {
            s[si][j] = ch;
            s[ei][j] = ch;
        }
        si++; ei--;
        sj++; ej--;
        ch++;
    }

    for (i = 0; i < n; i++) {
        s[i][m] = '\0';
        printf("%s\n", s[i]);
    }

    return 0;
}
