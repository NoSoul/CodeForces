#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mIndex;
    int mNum;
} Mittens_t;
Mittens_t Color[101];

typedef struct {
    int l, r;
    int extra;
} Ans_t;
Ans_t Ans[5001];
int AnsSize, Cnt;

int cmp(const void *a, const void *b)
{
    return (*(Mittens_t *)b).mNum - (*(Mittens_t *)a).mNum;
}

void Solve(int num)
{
    int i;
    while(1) {
        qsort(Color, num, sizeof(Mittens_t), cmp);
        if(num == 1) {
            for(i = 0; i < AnsSize && Color[0].mNum; ++i) {
                if(Color[0].mIndex != Ans[i].l && Color[0].mIndex != Ans[i].r) {
                    Ans[i].extra = Color[0].mIndex;
                    --Color[0].mNum;
                    ++Cnt;
                }
            }
            while(Color[0].mNum--) {
                Ans[AnsSize].l = Color[0].mIndex;
                Ans[AnsSize++].r = Color[0].mIndex;
            }
            break;
        }
        for(i = 0; i < Color[1].mNum; ++i) {
            Ans[AnsSize].l = Color[0].mIndex;
            Ans[AnsSize++].r = Color[1].mIndex;
            Cnt += 2;
        }
        Color[0].mNum -= Color[1].mNum;
        Color[1] = Color[num - 1];
        --num;
        if(Color[0].mNum == 0) {
            Color[0] = Color[num - 1];
            --num;
        }
        if(num == 0) {
            break;
        }
    }
}

int main()
{
    int N, M, i, num;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%d", &num);
        ++Color[num - 1].mNum;
        Color[num - 1].mIndex = num;
    }
    Solve(M);
    printf("%d\n", Cnt);
    for(i = 0; i < AnsSize; ++i) {
        if(Ans[i].extra) {
            printf("%d %d\n%d %d\n%d %d\n", Ans[i].l, Ans[i].r, Ans[i].r, Ans[i].extra, Ans[i].extra, Ans[i].l);
        } else if(Ans[i].l != Ans[i].r) {
            printf("%d %d\n%d %d\n", Ans[i].l, Ans[i].r, Ans[i].r, Ans[i].l);
        } else {
            printf("%d %d\n", Ans[i].l, Ans[i].r);
        }
    }
    return 0;
}
