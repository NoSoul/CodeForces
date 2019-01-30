#include <stdio.h>

int Ans[200000];

int main()
{
    int n, m;
    int x[200000];
    int t[200000];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n + m; ++i) {
        scanf("%d", &x[i]);
    }
    int pos = -1;
    for(int i = 0; i < n + m; ++i) {
        scanf("%d", &t[i]);
        if(t[i]) {
            for(int j = pos + 1; j < i; ++j) {
                if(t[j] == 0) {
                    if(pos == -1) {
                        ++Ans[i];
                    } else {
                        if(x[i] - x[j] < x[j] - x[pos]) {
                            ++Ans[i];
                        } else {
                            ++Ans[pos];
                        }
                    }
                }
            }
            pos = i;
        }
    }
    for(int j = pos + 1; j < n + m; ++j) {
        if(t[j] == 0) {
            ++Ans[pos];
        }
    }
    for(int i = 0; i < n + m; ++i) {
        if(t[i]) {
            printf("%d ", Ans[i]);
        }
    }
    return 0;
}
