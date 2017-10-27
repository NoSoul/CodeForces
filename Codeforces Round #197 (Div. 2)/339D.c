#include <stdio.h>
#include <math.h>

int Tree[1 << 18];
int N, OpX, OpY;

void Build(int left, int right, int id)
{
    if(left == right) {
        return;
    }
    Build(left, (left + right) >> 1, id << 1);
    Build(((left + right) >> 1) + 1, right, id << 1 | 1);
    if((N - (int)log2(id)) & 1) {
        Tree[id] = Tree[id << 1] | Tree[id << 1 | 1];
    } else {
        Tree[id] = Tree[id << 1] ^ Tree[id << 1 | 1];
    }
}

void Update(int left, int right, int id, int value)
{
    if(OpY < left || OpX > right) {
        return;
    }
    if(OpX <= left && OpY >= right) {
        Tree[id] = value;
        return;
    }
    Update(left, (left + right) >> 1, id << 1, value);
    Update(((left + right) >> 1) + 1, right, id << 1 | 1, value);
    if((N - (int)log2(id)) & 1) {
        Tree[id] = Tree[id << 1] | Tree[id << 1 | 1];
    } else {
        Tree[id] = Tree[id << 1] ^ Tree[id << 1 | 1];
    }
}

int main()
{
    int M, Q, i;
    scanf("%d %d", &N, &Q);
    M = 1 << N;
    for(i = 0; i < M; ++i) {
        scanf("%d", &Tree[M + i]);
    }
    Build(1, M, 1);
    while(Q--) {
        int p, b;
        scanf("%d %d", &p, &b);
        OpX = OpY = p;
        Update(1, M, 1, b);
        printf("%d\n", Tree[1]);
    }
    return 0;
}
