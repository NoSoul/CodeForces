#include <stdio.h>
#include <string.h>

typedef struct {
    int m_l;
    int m_r;
    int m_Idx;
} DataType_t;

int DataCMP(DataType_t a, DataType_t b)
{
    if(a.m_l == b.m_l) {
        return a.m_r > b.m_r;
    }
    return a.m_l > b.m_l;
}

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && DataCMP(val, array[now >> 1])) {
        array[now] = array[now >> 1];
        now >>= 1;
    }
    array[now] = val;
}

DataType_t BinaryHeapPop(DataType_t *array, int *len)
{
    DataType_t ret = array[1];
    int now = 1, temp;
    while((now << 1) <= *len) {
        temp = now << 1;
        if((temp + 1) <= *len && DataCMP(array[temp + 1], array[temp])) {
            ++temp;
        }
        if(DataCMP(array[temp], array[*len])) {
            array[now] = array[temp];
        } else {
            break;
        }
        now = temp;
    }
    array[now] = array[*len];
    --(*len);
    return ret;
}

void BinaryHeapSort(DataType_t *array, int len)
{
    while(len) {
        int curIdx = len;
        array[curIdx] = BinaryHeapPop(array, &len);
    }
}

int main()
{
    int T;
    DataType_t Array[100001];
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int size = 0;
        int ans[100001];
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; ++i) {
            DataType_t temp;
            scanf("%d %d", &temp.m_l, &temp.m_r);
            temp.m_Idx = i;
            BinaryHeapPush(Array, &size, temp);
        }
        BinaryHeapSort(Array, size);
        int find = -1;
        int right = Array[1].m_r;
        ans[Array[1].m_Idx] = 1;
        for(int i = 2; i <= n; ++i) {
            if(Array[i].m_l <= right) {
                ans[Array[i].m_Idx] = 1;
                if(right < Array[i].m_r) {
                    right = Array[i].m_r;
                }
            } else {
                find = i;
                break;
            }
        }
        if(~find) {
            for(int i = find; i <= n; ++i) {
                ans[Array[i].m_Idx] = 2;
            }
            for(int i = 0; i < n; ++i) {
                printf("%d ", ans[i]);
            }
            puts("");
        } else {
            puts("-1");
        }
    }
    return 0;
}
