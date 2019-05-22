#include <stdio.h>

int main()
{
    int n;
    int a[200001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int i = 0, j = n - 1;
    char ans[200001];
    int size = 0;
    int last = 0;
    while(i <= j) {
        if(a[i] > last && a[j] > last) {
            if(a[i] <= a[j]) {
                last = a[i];
                ans[size++] = 'L';
                ++i;
            } else {
                last = a[j];
                ans[size++] = 'R';
                --j;
            }
        } else if(a[i] > last) {
            last = a[i];
            ans[size++] = 'L';
            ++i;
        } else if(a[j] > last) {
            last = a[j];
            ans[size++] = 'R';
            --j;
        } else {
            break;
        }
    }
    ans[size] = '\0';
    printf("%d\n%s\n", size, ans);
    return 0;
}
