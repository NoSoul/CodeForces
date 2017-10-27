#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, Ans = 0;
    char Mat[100][101];
    char Visited[100] = {0};
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s", Mat[i]);
    }
    for(i = 0; i < N; ++i) {
        if(!Visited[i]) {
            Visited[i] = 1;
            int Cur = 1;
            for(j = i + 1; j < N; ++j) {
                if(strcmp(Mat[i], Mat[j]) == 0) {
                    Visited[j] = 1;
                    ++Cur;
                }
            }
            if(Cur > Ans) {
                Ans = Cur;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
