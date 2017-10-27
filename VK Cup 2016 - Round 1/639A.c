#include <stdio.h>

int T[150000];
int Displays[6];
int Size;

int main()
{
    int n, k, q, i, j, type, id;
    scanf("%d %d %d", &n, &k, &q);
    for(i = 0; i < n; ++i) {
        scanf("%d", &T[i]);
    }
    while(q--) {
        scanf("%d %d", &type, &id);
        --id;
        if(type == 1) {
            for(i = 0; i < k; ++i) {
                if(i >= Size || T[id] > T[Displays[i]]) {
                    break;
                }
            }
            if(i < k) {
                for(j = k - 1; j > i; --j) {
                    Displays[j] = Displays[j - 1];
                }
                Displays[i] = id;
            }
            ++Size;
        } else {
            char find = 0;
            for(i = 0; i < Size && i < k; ++i) {
                if(Displays[i] == id) {
                    find = 1;
                    break;
                }
            }
            puts(find ? "YES" : "NO");
        }
    }
    return 0;
}
