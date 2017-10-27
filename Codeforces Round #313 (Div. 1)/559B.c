#include <stdio.h>
#include <string.h>

typedef struct {
    int mLen;
} Node_t;

Node_t TreeA[1 << 20];
Node_t TreeB[1 << 20];
char StrA[200001];
char StrB[200001];

void Build(Node_t *tree, char *str, int left, int right, int id)
{
    tree[id].mLen = right - left + 1;
    if(tree[id].mLen & 1) {
        return;
    }
    int mid = (left + right) >> 1;
    Build(tree, str, left, mid, id << 1);
    Build(tree, str, mid + 1, right, id << 1 | 1);
}

int DFS(int lefta, int righta, int ida, int leftb, int rightb, int idb)
{
    if(TreeA[ida].mLen != TreeB[idb].mLen) {
        return 0;
    }
    if(TreeA[ida].mLen & 1) {
        int i, j;
        for(i = lefta, j = leftb; i <= righta; ++i, ++j) {
            if(StrA[i] != StrB[j]) {
                return 0;
            }
        }
        return 1;
    }
    int mida = (lefta + righta) >> 1;
    int midb = (leftb + rightb) >> 1;
    return (DFS(lefta, mida, ida << 1, leftb, midb, idb << 1) && DFS(mida + 1, righta, ida << 1 | 1, midb + 1, rightb, idb << 1 | 1)) ||
           (DFS(lefta, mida, ida << 1, midb + 1, rightb, idb << 1 | 1) && DFS(mida + 1, righta, ida << 1 | 1, leftb, midb, idb << 1));
}

int main()
{
    scanf("%s %s", StrA, StrB);
    Build(TreeA, StrA, 0, strlen(StrA) - 1, 1);
    Build(TreeB, StrB, 0, strlen(StrB) - 1, 1);
    puts(DFS(0, strlen(StrA) - 1, 1, 0, strlen(StrB) - 1, 1) ? "YES" : "NO");
    return 0;
}
