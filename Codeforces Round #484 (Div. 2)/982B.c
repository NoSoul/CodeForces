#include <stdio.h>

typedef struct {
    int m_Row;
    int m_Width;
} DataType_t;

int DataCMP(DataType_t a, DataType_t b)
{
    return a.m_Width > b.m_Width ? 1 : 0;
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

DataType_t Data[200001];
int Size;
DataType_t Stack[200001];
int Top;

int main()
{
    int n, w;
    char str[400001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        DataType_t temp;
        scanf("%d", &temp.m_Width);
        temp.m_Row = i + 1;
        BinaryHeapPush(Data, &Size, temp);
    }
    BinaryHeapSort(Data, Size);
    scanf("%s", str);
    int pos = 1;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '0') {
            printf("%d ", Data[pos].m_Row);
            Stack[Top++] = Data[pos++];
        } else {
            printf("%d ", Stack[--Top].m_Row);
        }
    }
    puts("");
    return 0;
}
