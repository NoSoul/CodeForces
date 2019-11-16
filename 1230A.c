#include <stdio.h>

int main()
{
    int a[4];
    for(int i = 0; i < 4; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 4; ++i) {
        for(int j = i + 1; j < 4; ++j) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%s\n", a[0] + a[3] == a[1] + a[2] || a[3] == a[0] + a[1] + a[2] ? "YES" : "NO");
    return 0;
}
