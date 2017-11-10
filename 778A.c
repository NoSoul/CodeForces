#include <stdio.h>
#include <string.h>

char P[200001];
char T[200001];
char Backup[200001];
int A[200001];

int Check(int idx)
{
    memcpy(Backup, T, sizeof(T));
    for(int i = 0; i <= idx; ++i) {
        Backup[A[i] - 1] = ' ';
    }
    int len = 0;
    for(int i = 0; Backup[i]; ++i) {
        if(Backup[i] != ' ') {
            Backup[len++] = Backup[i];
        }
    }
    Backup[len] = '\0';
    int i = 0;
    int j = 0;
    while(P[i] && Backup[j]) {
        if(Backup[j] == P[i]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    return P[i] == '\0';
}

int main()
{
    scanf("%s %s", T, P);
    int len = strlen(T);
    for(int i = 0; i < len; ++i) {
        scanf("%d", &A[i]);
    }
    int left = 0;
    int right = len - 1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(Check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", left);
    return 0;
}
