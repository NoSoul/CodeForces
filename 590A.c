#include <stdio.h>

#define MAXN    500001

char Str[MAXN];

int main()
{
    int N, i, j, Ans;
    while(scanf("%d", &N) != EOF) {
        for(i = 0; i < N; ++i) {
            scanf("%hhd", &Str[i]);
        }
        Ans = 0;
        for(i = 1; i < N - 1; ++i) {
            if(Str[i] != Str[i - 1]) {
                int s = i, e = i;
                while(Str[e] != Str[e - 1] && e < N - 1) {
                    ++e;
                }
                --e;
                int newPos = e;
                if(Str[e] == Str[e + 1]) {
                    --e;
                }
                int len = (e - s + 1) / 2;
                char a = Str[i + 1];
                char b = Str[e + 1];
                char flag = 0;
                for(j = s; j <= e; ++j) {
                    if(j - s < len) {
                        if(Str[j] != a && j == s) {
                            flag = 1;
                        }
                        Str[j] = a;
                    } else {
                        if(Str[j] != b && j == s) {
                            flag = 1;
                        }
                        Str[j] = b;
                    }
                }
                if(s != e) {
                    if((e - s + 2) / 2 > Ans) {
                        Ans = (e - s + 2) / 2;
                    }
                } else {
                    if(flag) {
                        if(Ans < 1) {
                            Ans = 1;
                        }
                    }
                }
                i = newPos;
            }
        }
        printf("%d\n", Ans);
        for(i = 0; i < N; ++i) {
            printf("%d ", Str[i]);
        }
        puts("");
    }
    return 0;
}
