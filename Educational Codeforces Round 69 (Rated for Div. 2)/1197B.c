#include <stdio.h>

int Valid(int pos, int n)
{
    if(pos >= 0 && pos < n) {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    int a[200001];
    int b[200001];
    scanf("%d", &n);
    int maxVal = 1;
    int maxIdx = -1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(maxVal < a[i]) {
            maxVal = a[i];
            maxIdx = i;
        }
    }
    int cnt = 0;
    b[cnt++] = maxVal;
    int i = maxIdx - 1;
    int j = maxIdx + 1;
    while(1) {
        if(Valid(i, n) && Valid(j, n)) {
            if(a[i] > a[j]) {
                b[cnt++] = a[i--];
            } else {
                b[cnt++] = a[j++];
            }
        } else if(Valid(i, n)) {
            b[cnt++] = a[i--];
        } else if(Valid(j, n)) {
            b[cnt++] = a[j++];
        } else {
            break;
        }
    }
    for(int i = 1; i < n; ++i) {
        if(b[i] > b[i - 1]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
