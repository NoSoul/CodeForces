#include <stdio.h>

void TryAppend(int (*Queue)[2], int head, int *tail, int val)
{
    int i;
    for(i = head + 1; i < *tail; ++i) {
        if(Queue[i][0] == val) {
            break;
        }
    }
    if(i == *tail) {
        Queue[*tail][0] = val;
        Queue[*tail][1] = head;
        ++(*tail);
    }
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int Queue[10000][2];
    int Ans[10000];
    int size = 0;
    int head = 0, tail = 1;
    Queue[head][0] = b;
    Queue[head][1] = -1;
    while(head < tail) {
        if(Queue[head][0] == a) {
            puts("YES");
            Ans[size++] = Queue[head][0];
            int pre = Queue[head][1];
            while(~pre) {
                Ans[size++] = Queue[pre][0];
                pre = Queue[pre][1];
            }
            printf("%d\n", size);
            for(int i = 0; i < size; ++i) {
                printf("%d ", Ans[i]);
            }
            return 0;
        }
        int new;
        if(!(Queue[head][0] & 1)) {
            new = Queue[head][0] / 2;
            if(new >= a) {
                TryAppend(Queue, head, &tail, new);
            }
        }
        if(Queue[head][0] % 10 == 1) {
            new = (Queue[head][0] - 1) / 10;
            if(new >= a) {
                TryAppend(Queue, head, &tail, new);
            }
        }
        ++head;
    }
    puts("NO");
    return 0;
}
