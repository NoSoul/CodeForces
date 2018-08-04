#include <stdio.h>

long long Map[2][300001];

int main()
{
    int n;
    long long a, b, sum, ans;
    a = b = sum = ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &Map[0][i]);
        sum += Map[0][i];
    }
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &Map[1][i]);
        sum += Map[1][i];
    }

    for(int i = 0; i < n; ++i) {
        a += Map[0][i] * i;
    }
    for(int i = 0; i < n; ++i) {
        a += Map[1][i] * (2 * n - 1 - i);
    }
    if(ans < a) {
        ans = a;
    }
    long long delta = 0, remain = sum;
    int step = 0;
    for(int i = 0; i < n; i += 2) {
        delta += step * Map[0][i] + (step + 1) * Map[1][i] + (step + 2) * Map[1][i + 1] + (step + 3) * Map[0][i + 1];
        remain -= Map[0][i] + Map[1][i] + Map[0][i + 1] + Map[1][i + 1];
        a -= Map[0][i] * i + Map[0][i + 1] * (i + 1) + Map[1][i] * (2 * n - 1 - i) + Map[1][i + 1] * (2 * n - 1 - i - 1);
        step += 4;
        if(ans < remain * step / 2 + delta + a) {
            ans = remain * step / 2 + delta + a;
        }
    }

    for(int i = 0; i < n; ++i) {
        b += Map[1][i] * (1 + i);
    }
    for(int i = 1; i < n; ++i) {
        b += Map[0][i] * (2 * n - i);
    }
    delta = Map[1][0];
    remain = sum - Map[0][0] - Map[1][0];
    step = 2;
    if(ans < b) {
        ans = b;
    }
    b -= Map[1][0];
    for(int i = 1; i + 3 < n; i += 2) {
        delta += step * Map[1][i] + (step + 1) * Map[0][i] + (step + 2) * Map[0][i + 1] + (step + 3) * Map[1][i + 1];
        remain -= Map[0][i] + Map[1][i] + Map[0][i + 1] + Map[1][i + 1];
        b -= Map[0][i] * (2 * n - i) + Map[0][i + 1] * (2 * n - i - 1) + Map[1][i] * (i + 1) + Map[1][i + 1] * (i + 2);
        step += 4;
        if(ans < remain * (step / 2 - 1) + delta + b) {
            ans = remain * (step / 2 - 1) + delta + b;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
