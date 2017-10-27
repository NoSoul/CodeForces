#include <stdio.h>

int A[3];
int Size;

int main()
{
    int N, Num;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &Num);
        int j;
        for(j = 0; j < Size; ++j) {
            if(Num == A[j]) {
                break;
            }
        }
        if(j == Size) {
            if(Size == 3) {
                puts("NO");
                return 0;
            }
            A[Size++] = Num;
        }
    }
    for(int i = 0; i < Size; ++i) {
        int k = i;
        for(int j = i + 1; j < Size; ++j) {
            if(A[k] > A[j]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
    if(Size < 3) {
        puts("YES");
    }  else {
        puts((A[1] - A[0]) != (A[2] - A[1]) ? "NO" : "YES");
    }
    return 0;
}
