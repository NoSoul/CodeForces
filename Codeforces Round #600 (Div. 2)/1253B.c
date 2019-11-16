#include <stdio.h>
#include <string.h>

char Flag[1000001];
int Entrances[1000001];

int main()
{
    int n;
    int a[100001];
    int d = 0;
    int ans[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int num = 0;
    int last = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i] > 0) {
            if(!Flag[a[i]]) {
                Flag[a[i]] = 1;
                ++num;
                if(++Entrances[a[i]] > 1) {
                    puts("-1");
                    return 0;
                }
            } else {
                puts("-1");
                return 0;
            }
        } else {
            if(Flag[-a[i]]) {
                Flag[-a[i]] = 0;
                --num;
                if(num == 0) {
                    for(int j = last + 1; j < i; ++j) {
                        if(a[j] > 0) {
                            --Entrances[a[j]];
                        }
                    }
                    ans[d++] = i - last;
                    last = i;
                }
            } else {
                puts("-1");
                return 0;
            }
        }
    }
    if(num != 0) {
        puts("-1");
        return 0;
    }
    printf("%d\n", d);
    for(int i = 0; i < d; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
