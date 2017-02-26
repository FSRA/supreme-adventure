#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
int c,b,a;
scanf("%d", &c);
a =c % 3;
b = c - a;
printf("%d %d", a, b);
return 0;
}
