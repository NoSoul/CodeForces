#include <stdio.h>
#include <string.h>

typedef struct {
    char show;
    int next[26];
} Node_t;
Node_t Trie[2000001];
char Str[2000001][11];

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s", Str[i]);
    }
    memset(Trie[0].next, -1, sizeof(Trie[0].next));
    int alloc = 1;
    for(i = N - 1; i >= 0; --i) {
        int s = 0;
        int l = strlen(Str[i]);
        for(j = 0; j < l; ++j) {
            if(Trie[s].next[Str[i][j] - 'a'] == -1) {
                memset(Trie[alloc].next, -1, sizeof(Trie[alloc].next));
                Trie[s].next[Str[i][j] - 'a'] = alloc;
                ++alloc;
            }
            s = Trie[s].next[Str[i][j] - 'a'];
        }
        if(!Trie[s].show) {
            puts(Str[i]);
            Trie[s].show = 1;
        }
    }
    return 0;
}
