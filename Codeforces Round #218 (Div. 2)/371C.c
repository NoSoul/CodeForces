#include <stdio.h>

typedef long long LL_t;

int main()
{
    int i, nb, ns, nc, pb, ps, pc, flag;
    int needb, needs, needc, Min;
    LL_t Sum, One, Ans;
    char Str[101];
    scanf("%s", Str);
    scanf("%d %d %d", &nb, &ns, &nc);
    scanf("%d %d %d", &pb, &ps, &pc);
    scanf("%I64d", &Sum);
    needb = needs = needc = 0;
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'B') {
            ++needb;
        } else if(Str[i] == 'S') {
            ++needs;
        } else {
            ++needc;
        }
    }
    One = needb * pb + needs * ps + needc * pc;
    Min = 0x7fffffff;
    if(needb) {
        if(nb / needb < Min) {
            Min = nb / needb;
        }
    }
    if(needs) {
        if(ns / needs < Min) {
            Min = ns / needs;
        }
    }
    if(needc) {
        if(nc / needc < Min) {
            Min = nc / needc;
        }
    }
    Ans = Min;
    nb -= Min * needb;
    ns -= Min * needs;
    nc -= Min * needc;
    while(1) {
        flag = 1;
        if(needb && nb != 0) {
            flag = 0;
        }
        if(needs && ns != 0) {
            flag = 0;
        }
        if(needc && nc != 0) {
            flag = 0;
        }
        if(flag) {
            break;
        }
        if(nb >= needb) {
            nb -= needb;
        } else {
            if(Sum < ((needb - nb)*pb)) {
                break;
            }
            Sum -= (needb - nb) * pb;
            nb = 0;
        }
        if(ns >= needs) {
            ns -= needs;
        } else {
            if(Sum < ((needs - ns)*ps)) {
                break;
            }
            Sum -= (needs - ns) * ps;
            ns = 0;
        }
        if(nc >= needc) {
            nc -= needc;
        } else {
            if(Sum < ((needc - nc)*pc)) {
                break;
            }
            Sum -= (needc - nc) * pc;
            nc = 0;
        }
        ++Ans;
    }
    printf("%I64d\n", Ans + Sum / One);
    return 0;
}
