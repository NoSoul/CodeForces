#include <stdio.h>

int main()
{
    int n, p;
    char str[2001];
    scanf("%d %d %s", &n, &p, str);
    for(int i = 0; i < n; ++i) {
        if(str[i] == '.') {
            int k = i % p;
            int cnt = 0;
            for(int j = k; j < n; j += p) {
                cnt += str[j] == '0';
            }
            str[i] = cnt ? '1' : '0';
        }
    }
    int i;
    for(i = 0; i < n - p; ++i) {
        if(str[i] != str[i + p]) {
            break;
        }
    }
    puts(i == n - p ? "No" : str);
    return 0;
}
