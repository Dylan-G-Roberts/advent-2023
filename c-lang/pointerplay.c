#include <stdio.h>
int main() {
    int x = 4, y = 2, z[10];
    int *ip, *iq;

    ip = &x;
    y = *ip;
    iq = &y;
    *ip = 0;
    z[0] = 1;
    ip = &z[0];

    *ip = *ip + 10;
    (*ip)++;
    ip = iq;
    printf("\n ip=%d, y=%d \n", *ip, *iq);
}