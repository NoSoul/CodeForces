#include <stdio.h>
#include <stdlib.h>

typedef long long PrimaryType_t;
typedef struct {
    PrimaryType_t mPrimaryVal;
} RBData_t;

typedef enum {
    RB_RED,
    RB_BLACK
} RBColor_t;

struct RBNode_t {
    struct RBNode_t *mLeft, *mRight, *mParent;
    RBColor_t mColor;
    RBData_t mKey;
};

typedef struct {
    struct RBNode_t mSentinelLeaf;
    struct RBNode_t *mTreeRoot;
} RBTree_t;

void Show(struct RBNode_t *node)
{
    printf("%p %p %p %p %lld %d\n", node, node->mParent, node->mLeft, node->mRight, node->mKey.mPrimaryVal, node->mColor);
}

void RBTreeInitialize(RBTree_t *tree)
{
    tree->mTreeRoot = &tree->mSentinelLeaf;
    tree->mSentinelLeaf.mColor = RB_BLACK;
}

void RBTreeInorder(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node != stop) {
        RBTreeInorder(node->mLeft, stop);
        Show(node);
        RBTreeInorder(node->mRight, stop);
    }
}

void RBTreePostorderFree(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node != stop) {
        RBTreePostorderFree(node->mLeft, stop);
        RBTreePostorderFree(node->mRight, stop);
        free(node);
    }
}

void RBTreeDestroy(RBTree_t *tree)
{
    RBTreePostorderFree(tree->mTreeRoot, &tree->mSentinelLeaf);
    RBTreeInitialize(tree);
}

struct RBNode_t *RBTreeSearch(struct RBNode_t *node, RBData_t *key, struct RBNode_t *stop)
{
    while(node != stop && key->mPrimaryVal != node->mKey.mPrimaryVal) {
        if(key->mPrimaryVal < node->mKey.mPrimaryVal) {
            node = node->mLeft;
        } else {
            node = node->mRight;
        }
    }
    return node;
}

struct RBNode_t *RBTreeSearchRange(struct RBNode_t *node, RBData_t *key, struct RBNode_t *stop)
{
    while(node != stop && (key->mPrimaryVal < (node->mKey.mPrimaryVal >> 32) || key->mPrimaryVal > ((node->mKey.mPrimaryVal << 32) >> 32))) {
        if(key->mPrimaryVal < (node->mKey.mPrimaryVal >> 32)) {
            node = node->mLeft;
        } else {
            node = node->mRight;
        }
    }
    return node;
}

struct RBNode_t *RBTreeMinimum(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node == stop) {
        return node;
    }
    while(node->mLeft != stop) {
        node = node->mLeft;
    }
    return node;
}

struct RBNode_t *RBTreeMaximum(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node == stop) {
        return node;
    }
    while(node->mRight != stop) {
        node = node->mRight;
    }
    return node;
}

struct RBNode_t *RBTreeSuccessor(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node->mRight != stop) {
        return RBTreeMinimum(node->mRight, stop);
    }
    struct RBNode_t *p = node->mParent;
    while(p != stop && node == p->mRight) {
        node = p;
        p = node->mParent;
    }
    return p;
}

struct RBNode_t *RBTreePredecessor(struct RBNode_t *node, struct RBNode_t *stop)
{
    if(node->mLeft != stop) {
        return RBTreeMaximum(node->mLeft, stop);
    }
    struct RBNode_t *p = node->mParent;
    while(p != stop && node == p->mLeft) {
        node = p;
        p = node->mParent;
    }
    return p;
}

void RBTreeLeftRotate(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = node->mRight;
    node->mRight = y->mLeft;
    if(y->mLeft != &tree->mSentinelLeaf) {
        y->mLeft->mParent = node;
    }
    y->mParent = node->mParent;
    if(node->mParent == &tree->mSentinelLeaf) {
        tree->mTreeRoot = y;
    } else if(node == node->mParent->mLeft) {
        node->mParent->mLeft = y;
    } else {
        node->mParent->mRight = y;
    }
    y->mLeft = node;
    node->mParent = y;
}

void RBTreeRightRotate(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = node->mLeft;
    node->mLeft = y->mRight;
    if(y->mRight != &tree->mSentinelLeaf) {
        y->mRight->mParent = node;
    }
    y->mParent = node->mParent;
    if(node->mParent == &tree->mSentinelLeaf) {
        tree->mTreeRoot = y;
    } else if(node == node->mParent->mLeft) {
        node->mParent->mLeft = y;
    } else {
        node->mParent->mRight = y;
    }
    y->mRight = node;
    node->mParent = y;
}

void RBTreeInsertFixup(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *s;
    while(node->mParent->mColor == RB_RED) {
        if(node->mParent == node->mParent->mParent->mLeft) {
            s = node->mParent->mParent->mRight;
        } else {
            s = node->mParent->mParent->mLeft;
        }
        if(s->mColor == RB_RED) {
            node->mParent->mColor = RB_BLACK;
            s->mColor = RB_BLACK;
            node->mParent->mParent->mColor = RB_RED;
            node = node->mParent->mParent;
        } else {
            if(node == node->mParent->mRight && node->mParent == node->mParent->mParent->mLeft) {
                node = node->mParent;
                RBTreeLeftRotate(tree, node);
            } else if(node == node->mParent->mLeft && node->mParent == node->mParent->mParent->mRight) {
                node = node->mParent;
                RBTreeRightRotate(tree, node);
            }
            node->mParent->mColor = RB_BLACK;
            node->mParent->mParent->mColor = RB_RED;
            if(node == node->mParent->mLeft) {
                RBTreeRightRotate(tree, node->mParent->mParent);
            } else {
                RBTreeLeftRotate(tree, node->mParent->mParent);
            }
        }
    }
    tree->mTreeRoot->mColor = RB_BLACK;
}

void RBTreeInsert(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = &tree->mSentinelLeaf;
    struct RBNode_t *x = tree->mTreeRoot;
    while(x != &tree->mSentinelLeaf) {
        y = x;
        if(node->mKey.mPrimaryVal < x->mKey.mPrimaryVal) {
            x = x->mLeft;
        } else {
            x = x->mRight;
        }
    }
    node->mParent = y;
    if(y == &tree->mSentinelLeaf) {
        tree->mTreeRoot = node;
    } else if(node->mKey.mPrimaryVal < y->mKey.mPrimaryVal) {
        y->mLeft = node;
    } else {
        y->mRight = node;
    }
    node->mLeft = &tree->mSentinelLeaf;
    node->mRight = &tree->mSentinelLeaf;
    node->mColor = RB_RED;
    RBTreeInsertFixup(tree, node);
}

void RBTreeTransplant(RBTree_t *tree, struct RBNode_t *u, struct RBNode_t *v)
{
    if(u->mParent == &tree->mSentinelLeaf) {
        tree->mTreeRoot = v;
    } else if(u == u->mParent->mLeft) {
        u->mParent->mLeft = v;
    } else {
        u->mParent->mRight = v;
    }
    v->mParent = u->mParent;
}

void RBTreeDeleteFixup(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *s;
    while(node != tree->mTreeRoot && node->mColor == RB_BLACK) {
        if(node == node->mParent->mLeft) {
            s = node->mParent->mRight;
            if(s->mColor == RB_RED) {
                s->mColor = RB_BLACK;
                node->mParent->mColor = RB_RED;
                RBTreeLeftRotate(tree, node->mParent);
                s = node->mParent->mRight;
            }
            if(s->mLeft->mColor == RB_BLACK && s->mRight->mColor == RB_BLACK) {
                s->mColor = RB_RED;
                node = node->mParent;
            } else {
                if(s->mRight->mColor == RB_BLACK) {
                    s->mLeft->mColor = RB_BLACK;
                    s->mColor = RB_RED;
                    RBTreeRightRotate(tree, s);
                    s = node->mParent->mRight;
                }
                s->mColor = node->mParent->mColor;
                node->mParent->mColor = RB_BLACK;
                s->mRight->mColor = RB_BLACK;
                RBTreeLeftRotate(tree, node->mParent);
                node = tree->mTreeRoot;
            }
        } else {
            s = node->mParent->mLeft;
            if(s->mColor == RB_RED) {
                s->mColor = RB_BLACK;
                node->mParent->mColor = RB_RED;
                RBTreeRightRotate(tree, node->mParent);
                s = node->mParent->mLeft;
            }
            if(s->mLeft->mColor == RB_BLACK && s->mRight->mColor == RB_BLACK) {
                s->mColor = RB_RED;
                node = node->mParent;
            } else {
                if(s->mLeft->mColor == RB_BLACK) {
                    s->mRight->mColor = RB_BLACK;
                    s->mColor = RB_RED;
                    RBTreeLeftRotate(tree, s);
                    s = node->mParent->mLeft;
                }
                s->mColor = node->mParent->mColor;
                node->mParent->mColor = RB_BLACK;
                s->mLeft->mColor = RB_BLACK;
                RBTreeRightRotate(tree, node->mParent);
                node = tree->mTreeRoot;
            }
        }
    }
    node->mColor = RB_BLACK;
}

void RBTreeDelete(RBTree_t *tree, struct RBNode_t *node)
{
    struct RBNode_t *y = node;
    struct RBNode_t *x;
    RBColor_t origincolor = y->mColor;
    if(node->mLeft == &tree->mSentinelLeaf) {
        x = node->mRight;
        RBTreeTransplant(tree, node, node->mRight);
    } else if(node->mRight == &tree->mSentinelLeaf) {
        x = node->mLeft;
        RBTreeTransplant(tree, node, node->mLeft);
    } else {
        y = RBTreeMinimum(node->mRight, &tree->mSentinelLeaf);
        origincolor = y->mColor;
        x = y->mRight;
        if(y->mParent == node) {
            x->mParent = y;
        } else {
            RBTreeTransplant(tree, y, y->mRight);
            y->mRight = node->mRight;
            y->mRight->mParent = y;
        }
        RBTreeTransplant(tree, node, y);
        y->mLeft = node->mLeft;
        y->mLeft->mParent = y;
        y->mColor = node->mColor;
    }
    if(origincolor == RB_BLACK) {
        RBTreeDeleteFixup(tree, x);
    }
}

void RBTreeAdd(RBTree_t *tree, PrimaryType_t num)
{
    struct RBNode_t *node = (struct RBNode_t *)malloc(sizeof(struct RBNode_t));
    node->mKey.mPrimaryVal = num;
    RBTreeInsert(tree, node);
}

void RBTreeDel(RBTree_t *tree, PrimaryType_t num)
{
    RBData_t check;
    check.mPrimaryVal = num;
    struct RBNode_t *node = RBTreeSearch(tree->mTreeRoot, &check, &tree->mSentinelLeaf);
    if(node == &tree->mSentinelLeaf) {
        puts("Error");
        return;
    }
    RBTreeDelete(tree, node);
    free(node);
}

RBTree_t SetSeg, SetSum;
int A[100001];
long long Sum[100001];

long long GetSum(int s, int e)
{
    return Sum[e] - Sum[s - 1];
}

int main()
{
    int N, x;
    long long num;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        Sum[i] = Sum[i - 1] + A[i];
    }
    RBTreeInitialize(&SetSeg);
    RBTreeInitialize(&SetSum);
    num = 1LL << 32 | N;
    RBTreeAdd(&SetSeg, num);
    RBTreeAdd(&SetSum, GetSum(1, N));
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &x);
        RBData_t check;
        check.mPrimaryVal = x;
        struct RBNode_t *node = RBTreeSearchRange(SetSeg.mTreeRoot, &check, &SetSeg.mSentinelLeaf);
        long long s = node->mKey.mPrimaryVal >> 32;
        long long e = (node->mKey.mPrimaryVal << 32) >> 32;
        if(s <= x - 1) {
            num = s << 32 | (x - 1);
            RBTreeAdd(&SetSeg, num);
            RBTreeAdd(&SetSum, GetSum(s, x - 1));
        }
        if(x + 1 <= e) {
            num = (x + 1);
            num <<= 32;
            num |= e;
            RBTreeAdd(&SetSeg, num);
            RBTreeAdd(&SetSum, GetSum(x + 1, e));
        }
        RBTreeDel(&SetSeg, node->mKey.mPrimaryVal);
        RBTreeDel(&SetSum, GetSum(s, e));
        printf("%I64d\n", RBTreeMaximum(SetSum.mTreeRoot, &SetSum.mSentinelLeaf)->mKey.mPrimaryVal);
    }
    RBTreeDestroy(&SetSeg);
    RBTreeDestroy(&SetSum);
    return 0;
}
