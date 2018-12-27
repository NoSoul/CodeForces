#include <stdio.h>

int main()
{
    long long n, x, y;
    scanf("%I64d %I64d %I64d", &n, &x, &y);
    long long white;
    long long black;
    if(x <= y) {
        white = x - 1;
        white += y - x;
        black = n - y;
        black += y - x;
    } else {
        white = y - 1;
        white += x - y;
        black = n - x;
        black += x - y;
    }
    puts(white <= black ? "White" : "Black");
    return 0;
}
