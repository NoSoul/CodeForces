#include <stdio.h>

int A[100];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < N; ++i) {
        while(1) {
            int minIdx = i;
            for(int j = i + 1; j < N; ++j) {
                if(A[j] < A[minIdx]) {
                    minIdx = j;
                }
            }
            if(minIdx != i) {
                printf("%d %d\n", minIdx, minIdx + 1);
                int temp = A[minIdx];
                A[minIdx] = A[minIdx - 1];
                A[minIdx - 1] = temp;
                if(minIdx == i + 1) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return 0;
}
