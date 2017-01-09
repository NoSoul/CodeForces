#include <stdio.h>
#include <string.h>
#include <math.h>

int IsNorthPole(int x)
{
    return x == 0;
}

int IsSouthPole(int x)
{
    return x == 20000;
}

int main()
{
    int idx, n;
    while(scanf("%d", &n) != EOF) {
        idx = 0;
        char invalid = 0;
        while(n--) {
            int offset;
            char dir[6];
            scanf("%d %s", &offset, dir);
            if(IsNorthPole(idx)) {
                if(strcmp(dir, "South") != 0) {
                    invalid = 1;
                }
            }
            if(IsSouthPole(idx)) {
                if(strcmp(dir, "North") != 0) {
                    invalid = 1;
                }
            }
            if(strcmp(dir, "North") == 0) {
                idx = idx - offset;
                if(idx < 0) {
                    invalid = 1;
                }
            } else if(strcmp(dir, "South") == 0) {
                idx = idx + offset;
                if(idx > 20000) {
                    invalid = 1;
                }
            }
        }
        puts(!invalid && IsNorthPole(idx) ? "YES" : "NO");
    }
    return 0;
}
