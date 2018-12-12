#include <stdio.h>
#include <string.h>

typedef struct {
    char m_Cnt[26];
} Node_t;
Node_t A[1000];
int Size;

int main()
{
    int n;
    char s[1001];
    char cur[26];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", s);
        memset(cur, 0, sizeof(cur));
        for(int j = 0; s[j]; ++j) {
            cur[s[j] - 'a'] = 1;
        }
        int j;
        for(j = 0; j < Size; ++j) {
            int k;
            for(k = 0; k < 26; ++k) {
                if(A[j].m_Cnt[k] != cur[k]) {
                    break;
                }
            }
            if(k == 26) {
                break;
            }
        }
        if(j == Size) {
            memcpy(A[Size].m_Cnt, cur, sizeof(cur));
            ++Size;
        }
    }
    printf("%d\n", Size);
    return 0;
}
