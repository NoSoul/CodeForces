#include <stdio.h>

int CntS[10];
int CntM[10];

int main()
{
    int n;
    char strS[1001], strM[1001];
    scanf("%d %s %s", &n, strS, strM);
    for(int i = 0; i < n; ++i) {
        ++CntS[strS[i] - '0'];
        ++CntM[strM[i] - '0'];
    }
    int min = 0;
    for(int i = 9; i >= 0; --i) {
        while(CntM[i]) {
            --CntM[i];
            char find = 0;
            for(int j = i; j >= 0; --j) {
                if(CntS[j]) {
                    --CntS[j];
                    find = 1;
                    break;
                }
            }
            if(!find) {
                ++min;
            }
        }
    }
    for(int i = 0; i < 10; ++i) {
        CntS[i] = CntM[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        ++CntS[strS[i] - '0'];
        ++CntM[strM[i] - '0'];
    }
    int max = 0;
    for(int i = 9; i >= 0; --i) {
        while(CntM[i]) {
            --CntM[i];
            for(int j = i - 1; j >= 0; --j) {
                if(CntS[j]) {
                    --CntS[j];
                    ++max;
                    break;
                }
            }
        }
    }
    printf("%d\n%d\n", min, max);
    return 0;
}
