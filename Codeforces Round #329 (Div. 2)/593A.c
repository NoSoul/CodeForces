#include <stdio.h>
#include <string.h>

typedef struct {
    char ch[2];
    int cnt[2];
} Node_t;
Node_t A[100];
int Size;

void Fun(char *str)
{
    int i, j;
    int cur = 0;
    memset(&A[Size], 0, sizeof(Node_t));
    for(i = 0; str[i] != '\0'; ++i) {
        for(j = 0; j < cur; ++j) {
            if(A[Size].ch[j] == str[i]) {
                ++A[Size].cnt[j];
                break;
            }
        }
        if(j == cur) {
            if(cur == 2) {
                return;
            }
            A[Size].ch[cur] = str[i];
            A[Size].cnt[cur++] = 1;
        }
    }
    ++Size;
}

int main()
{
    int N, i, j, k;
    char Str[1001];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s", Str);
        Fun(Str);
    }
    int Max = 0;
    for(i = 0; i < 26; ++i) {
        int cur = 0;
        for(k = 0; k < Size; ++k) {
            if(A[k].cnt[1] == 0 && A[k].ch[0] == 'a' + i) {
                cur += A[k].cnt[0];
            }
        }
        if(cur > Max) {
            Max = cur;
        }
    }
    for(i = 0; i < 26; ++i) {
        for(j = 0; j < 26; ++j) {
            if(i != j) {
                int cur = 0;
                for(k = 0; k < Size; ++k) {
                    if(A[k].cnt[1]) {
                        if((A[k].ch[0] == 'a' + i && A[k].ch[1] == 'a' + j) || (A[k].ch[0] == 'a' + j && A[k].ch[1] == 'a' + i)) {
                            cur += A[k].cnt[0] + A[k].cnt[1];
                        }
                    } else {
                        if(A[k].ch[0] == 'a' + i || A[k].ch[0] == 'a' + j) {
                            cur += A[k].cnt[0];
                        }
                    }
                }
                if(cur > Max) {
                    Max = cur;
                }
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
