#include <stdio.h>
#include <string.h>

#define MAXN 100002

typedef struct {
    int m_L;
    int m_R;
} Op_t;
Op_t His[300];
int A[MAXN];
int B[MAXN];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &His[i].m_L, &His[i].m_R);
    }
    int ans = -0x7fffffff;
    int maxIdx = 1;
    for(int i = 1; i <= n; ++i) {
        memcpy(B + 1, A + 1, n * sizeof(int));
        for(int j = 0; j < m; ++j) {
            if(i < His[j].m_L || i > His[j].m_R) {
                for(int k = His[j].m_L; k <= His[j].m_R; ++k) {
                    --B[k];
                }
            }
        }
        int max = B[1];
        int min = B[1];
        for(int j = 2; j <= n; ++j) {
            if(max < B[j]) {
                max = B[j];
            }
            if(min > B[j]) {
                min = B[j];
            }
        }
        if(ans < max - min) {
            ans = max - min;
            maxIdx = i;
        }
    }
    printf("%d\n", ans);
    int cnt = 0;
    int choice[300];
    for(int j = 0; j < m; ++j) {
        if(maxIdx < His[j].m_L || maxIdx > His[j].m_R) {
            choice[cnt++] = j + 1;
        }
    }
    printf("%d\n", cnt);
    for(int j = 0; j < cnt; ++j) {
        printf("%d ", choice[j]);
    }
    puts("");
    return 0;
}
