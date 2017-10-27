#include <stdio.h>

char Flag[2000001];

int main()
{
    int n;
    int a[2000];
    int b[2000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        Flag[a[i]] = 1;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        Flag[b[i]] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((a[i]^b[j]) < 2000001) {
                if(Flag[a[i]^b[j]]) {
                    ++ans;
                }
            }
        }
    }
    puts(ans & 1 ? "Koyomi" : "Karen");
    return 0;
}
