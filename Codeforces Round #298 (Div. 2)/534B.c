#include <stdio.h>

int main()
{
    int v1, v2, t, d, i;
    int V[100];
    int Ans = 0;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);
    if(t == 2) {
        printf("%d\n", v1 + v2);
        return 0;
    }
    V[0] = v1;
    for(i = 1; i < t; ++i) {
        V[i] = V[i - 1] + d;
    }
    V[t - 1] = v2;
    for(i = t - 2; i > 0; --i) {
        if(V[i] > V[i + 1] + d) {
            V[i] = V[i + 1] + d;
        } else {
            break;
        }
    }
    for(i = 0; i < t; ++i) {
        Ans += V[i];
    }
    printf("%d\n", Ans);
    return 0;
}
