#include <stdio.h>
#include <string.h>

int A[200001];
char Visit[200001];
char TempVisit[200001];

int main()
{
    int N, Ans = 0, root = -1;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] == i) {
            root = i;
        }
    }
    if(root != -1) {
        Visit[root] = 1;
    }
    for(int i = 1; i <= N; ++i) {
        if(!Visit[i]) {
            memset(TempVisit, 0, sizeof(TempVisit));
            int cur = i;
            while(1) {
                TempVisit[cur] = 1;
                if(TempVisit[A[cur]] || Visit[A[cur]]) {
                    break;
                }
                cur = A[cur];
            }
            if(!Visit[A[cur]]) {
                if(root == -1) {
                    ++Ans;
                    root = cur;
                    A[cur] = root;
                } else {
                    if(A[cur] != root) {
                        ++Ans;
                        A[cur] = root;
                    }
                }
            }
            cur = i;
            while(1) {
                if(Visit[cur]) {
                    break;
                }
                Visit[cur] = 1;
                cur = A[cur];
            }
        }
    }
    printf("%d\n", Ans);
    for(int i = 1; i <= N; ++i) {
        printf("%d ", A[i]);
    }
    puts("");
    return 0;
}
