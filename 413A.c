#include <stdio.h>

int main()
{
    int n, m, min, max;
    int t[100];
    scanf("%d %d %d %d", &n, &m, &min, &max);
    char haveMin = 0;
    char haveMax = 0;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &t[i]);
        if(t[i] == min) {
            haveMin = 1;
        }
        if(t[i] == max) {
            haveMax = 1;
        }
        if(t[i] < min || t[i] > max) {
            puts("Incorrect");
            return 0;
        }
    }
    if(!haveMin) {
        ++m;
    }
    if(!haveMax) {
        ++m;
    }
    puts(m <= n ? "Correct" : "Incorrect");
    return 0;
}
