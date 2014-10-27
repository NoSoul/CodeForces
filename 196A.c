#include <stdio.h>
#include <string.h>

#define MAXN    100001

typedef struct
{
    int id;
    char ch;
} Segment_t;
Segment_t Tree[MAXN<<2];
char Str[MAXN];
Segment_t NullOb;
int QueryX, QueryY;

void Build(int left, int right, int id)
{
    int Mid;
    if(left == right)
    {
        Tree[id].id = left;
        Tree[id].ch = Str[left];
        return ;
    }
    int mid = (left+right)>>1;
    Build(left, mid, id<<1);
    Build(mid+1, right, (id<<1)+1);
    Tree[id] = Tree[(id<<1)+1];
    if(Tree[id<<1].ch > Tree[id].ch)
    {
        Tree[id] = Tree[id<<1];
    }
    if(Tree[id<<1].ch==Tree[id].ch && Tree[id<<1].id<Tree[id].id)
    {
        Tree[id] = Tree[id<<1];
    }
}

Segment_t Query(int left, int right, int id)
{
    if(QueryX>right || QueryY<left)
    {
        return NullOb;
    }
    if(QueryX<=left && QueryY>=right)
    {
        return Tree[id];
    }
    int mid = (left+right)>>1;
    Segment_t l = Query(left, mid, id<<1);
    Segment_t r = Query(mid+1, right, (id<<1)+1);
    if(r.ch > l.ch)
    {
        return r;
    }
    if(r.ch==l.ch && r.id<l.id)
    {
        return r;
    }
    return l;
}

int main()
{
    scanf("%s", Str+1);
    int Len = strlen(Str+1);
    Build(1, Len, 1);
    QueryX = 1;
    QueryY = Len;
    while(1)
    {
        Segment_t Ans = Query(1, Len, 1);
        putchar(Ans.ch);
        if(Ans.id == Len)
        {
            break;
        }
        QueryX = Ans.id+1;
    }
    putchar('\n');
    return 0;
}
