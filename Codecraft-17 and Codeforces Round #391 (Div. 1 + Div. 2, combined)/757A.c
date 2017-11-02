#include <stdio.h>

int A[52];
int B[52];

void Func(char *str, int *num)
{
    for(int i = 0; str[i] != '\0'; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            ++num[str[i] - 'a'];
        } else {
            ++num[str[i] - 'A' + 26];
        }
    }
}

int main()
{
    char StrA[] = "Bulbasaur";
    char StrB[100001];
    int ans = 100001;
    scanf("%s", StrB);
    Func(StrA, A);
    Func(StrB, B);
    for(int i = 0; i < 52; ++i) {
        if(A[i]) {
            if(ans > B[i] / A[i]) {
                ans = B[i] / A[i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
