#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if(m % n) {
        puts("-1");
    } else {
        m /= n;
        int ans = 0;
        while(m % 2 == 0) {
            m /= 2;
            ++ans;
        }
        while(m % 3 == 0) {
            m /= 3;
            ++ans;
        }
        printf("%d\n", m == 1 ? ans : -1);
    }
    return 0;
}
