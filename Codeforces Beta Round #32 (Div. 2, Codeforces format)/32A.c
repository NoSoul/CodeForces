#include <stdio.h>
int Data[1000][2];
int Size;

int main()
{
    int n, d;
    int a[1000];
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    Data[Size][0] = a[0];
    Data[Size++][1] = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] != a[i - 1]) {
            Data[Size][0] = a[i];
            Data[Size++][1] = 1;
        } else {
            ++Data[Size - 1][1];
        }
    }
    int ans = 0;
    for(int i = 0; i < Size; ++i) {
        ans += Data[i][1] * (Data[i][1] - 1) / 2 * 2;
        for(int j = i + 1; j < Size && Data[i][0] + d >= Data[j][0]; ++j) {
            if(Data[i][0] + d < Data[j][0]) {
                break;
            }
            ans += Data[i][1] * Data[j][1] * 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
