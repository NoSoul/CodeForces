#include <stdio.h>

long long  Map[500][500];
long long SumRow[500];
long long SumCol[500];

int main()
{
    int n, fillRow, fillCol;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%I64d", &Map[i][j]);
            if(Map[i][j] == 0) {
                fillRow = i;
                fillCol = j;
            }
            SumRow[i] += Map[i][j];
            SumCol[j] += Map[i][j];
        }
    }
    if(n == 1) {
        puts("1");
        return 0;
    }
    if(fillRow == 0) {
        Map[fillRow][fillCol] = SumRow[1] - SumRow[0];
    } else {
        Map[fillRow][fillCol] = SumRow[0] - SumRow[fillRow];
    }
    SumRow[fillRow] += Map[fillRow][fillCol];
    SumCol[fillCol] += Map[fillRow][fillCol];
    long long left = 0;
    long long right = 0;
    for(int i = 0; i < n; ++i) {
        left += Map[i][i];
        right += Map[i][n - i - 1];
    }
    char flag = 1;
    for(int i = 0; i < n; ++i) {
        if(SumRow[i] != left || SumCol[i] != left || right != left) {
            flag = 0;
        }
    }
    if(Map[fillRow][fillCol] < 1) {
        flag = 0;
    }
    if(flag) {
        printf("%I64d\n", Map[fillRow][fillCol]);
    } else {
        printf("-1\n");
    }
    return 0;
}
