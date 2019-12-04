#include <stdio.h>

int main()
{
    int da, db;
    scanf("%d %d", &da, &db);
    if(da == db) {
        printf("%d0 %d1\n", da, db);
    } else if(da + 1 == db) {
        printf("%d %d\n", da, db);
    } else if(da == 9 && db == 1) {
        printf("%d %d\n", 9, 10);
    } else {
        printf("-1");
    }
    return 0;
}
