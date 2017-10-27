#include <stdio.h>

int Data[2001];
int Cnt[2001];
char Flag[2001];

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &Data[i]);
        if(Data[i] > M) {
            ++Cnt[0];
        } else {
            ++Cnt[Data[i]];
        }
    }
    A = N / M;
    B = 0;
    for(int i = 1; i <= M; ++i) {
        if(Cnt[i] < A) {
            Flag[i] = 1;
        }
    }
    for(int i = 1; i <= M; ++i) {
        if(Flag[i]) {
            if(Cnt[0]) {
                for(int j = 0; j < N; ++j) {
                    if(Data[j] > M) {
                        ++B;
                        --Cnt[0];
                        Data[j] = i;
                        if(++Cnt[i] == A) {
                            Flag[i] = 0;
                            break;
                        }
                    }
                }
            }
            if(!Flag[i]) {
                continue;
            }
            for(int j = 0; j < N; ++j) {
                if(Cnt[Data[j]] > A) {
                    ++B;
                    --Cnt[Data[j]];
                    Data[j] = i;
                    if(++Cnt[i] == A) {
                        break;
                    }
                }
            }
        }
    }
    printf("%d %d\n", A, B);
    for(int i = 0; i < N; ++i) {
        printf("%d ", Data[i]);
    }
    puts("");
    return 0;
}
