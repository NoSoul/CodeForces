#include <stdio.h>
#include <string.h>

char Flag[100];
int Ans[100];

int main()
{
    int n, cnt = 0;
    char str[100][101];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str[i]);
    }
    while(1) {
        char fail = 1;
        for(int i = 0; i < n; ++i) {
            if(!Flag[i]) {
                char bad = 0;
                for(int j = 0; j < n; ++j) {
                    if(!Flag[j]) {
                        if(strstr(str[j], str[i]) == NULL) {
                            bad = 1;
                            break;
                        }
                    }
                }
                if(!bad) {
                    Ans[cnt++] = i;
                    Flag[i] = 1;
                    fail = 0;
                    break;
                }
            }
        }
        if(fail) {
            break;
        }
    }
    if(cnt == n) {
        puts("YES");
        for(int i = 0; i < n; ++i) {
            printf("%s\n", str[Ans[i]]);
        }
    } else {
        puts("NO");
    }
    return 0;
}
